import type { Socket } from 'socket.io-client'
import type { PackageDescriptionType, PackageIndexType } from '../src/utils/packages'
import type { Server } from '../src/utils/server'
import assert from 'node:assert/strict'
import { EventEmitter } from 'node:events'
import { it } from 'node:test'
import { buildPackageTree, comparePackageVersions } from '../src/utils/packageCatalog'
import { PackageManager } from '../src/utils/packages'
import { socketRequest } from '../src/utils/socketRequest'

class FakeSocket extends EventEmitter {
  connected = true
  connectionAttempts = 0
  requests: { event: string, acknowledge: (error: Error | null, data: Uint8Array) => void }[] = []

  timeout() { return this }

  connect() {
    this.connectionAttempts++
    return this
  }

  override emit(event: string, ...args: any[]): boolean {
    if (event.startsWith('sio/')) {
      this.requests.push({ event, acknowledge: args.at(-1) })
      return true
    }
    return super.emit(event, ...args)
  }

  get socket() { return this as unknown as Socket }
}

function description(name = 'demo'): PackageDescriptionType {
  return {
    type: 'hal',
    name,
    version: '1.0.0',
    vendor: 'Test',
    license: 'MIT',
    support: '*',
    vendorUrl: { en: '' },
    description: { en: name },
    url: { en: '' },
    author: { name: 'Tester', email: '', website: { blog: '', github: '' } },
  }
}

const index: PackageIndexType = { hal: { demo: { '1.0.0': 'hal/demo/1.0.0' } } }

it('catalog searches type, name and version together and sorts versions numerically', () => {
  assert.deepEqual(['1.9.0', 'latest', '1.10.0', '2.0.0-beta.1'].sort(comparePackageVersions), ['latest', '2.0.0-beta.1', '1.10.0', '1.9.0'])
  const tree = buildPackageTree(index, 'DEMO hal 1.0', 'hal')
  assert.equal(tree[0].children![0].children![0].selection!.name, 'demo')
  assert.deepEqual(buildPackageTree(index, 'missing'), [])
  assert.deepEqual(buildPackageTree(index, '', 'toolchains'), [])
})

it('parallel description requests receive their own acknowledgement, even out of order', async () => {
  const socket = new FakeSocket()
  const options = { event: 'sio/package/description', decode: (bytes: Uint8Array) => bytes[0] }
  const first = socketRequest(socket.socket, options)
  const second = socketRequest(socket.socket, options)
  socket.requests[1].acknowledge(null, new Uint8Array([2]))
  socket.requests[0].acknowledge(null, new Uint8Array([1]))
  assert.deepEqual(await Promise.all([first, second]), [1, 2])
  assert.equal(socket.listenerCount('disconnect'), 0)
})

it('a request timed out before connecting never sends a delayed operation', async () => {
  const socket = new FakeSocket()
  socket.connected = false
  await assert.rejects(socketRequest(socket.socket, { event: 'sio/package/install', decode: data => data, timeout: 5 }), /no response/)
  socket.connected = true
  socket.emit('connect')
  assert.equal(socket.requests.length, 0)
  assert.equal(socket.connectionAttempts, 1)
  assert.equal(socket.eventNames().length, 0)
})

it('retry actively reconnects a disconnected socket', async () => {
  const socket = new FakeSocket()
  socket.connected = false
  const request = socketRequest(socket.socket, { event: 'sio/package/list', decode: data => data[0] })
  assert.equal(socket.connectionAttempts, 1)
  socket.connected = true
  socket.emit('connect')
  socket.requests[0].acknowledge(null, new Uint8Array([7]))
  assert.equal(await request, 7)
})

it('installation reloads again when an older refresh is still pending', async () => {
  let calls = 0
  let finishRefresh!: (data: PackageIndexType) => void
  const updated = { hal: { ...index.hal, added: { '1.0.0': 'hal/added/1.0.0' } } }
  const server = {
    packageList: async () => {
      calls++
      if (calls === 2) {
        return new Promise<PackageIndexType>((resolve) => {
          finishRefresh = resolve
        })
      }
      return calls > 2 ? updated : index
    },
    packageInstall: async () => description('added'),
  }
  const manager = new PackageManager(server as unknown as Server)
  await manager.init()
  const refresh = manager.reload()
  await Promise.resolve()
  const install = manager.install('added.csppack')
  finishRefresh(index)
  await Promise.all([refresh, install])
  assert.equal(calls, 3)
  assert.equal(manager.packageIndex.path('hal', 'added', '1.0.0'), 'hal/added/1.0.0')
})

it('disconnect rejects promptly and removes only this request\'s progress listener', async () => {
  const socket = new FakeSocket()
  const externalListener = () => {}
  socket.on('package/install.progress', externalListener)
  const request = socketRequest(socket.socket, {
    event: 'sio/package/install',
    decode: data => data,
    progressEvent: 'package/install.progress',
  })
  socket.emit('disconnect')
  await assert.rejects(request, /disconnected/)
  assert.deepEqual(socket.listeners('package/install.progress'), [externalListener])
  socket.requests[0].acknowledge(null, new Uint8Array([1]))
})

it('invalid responses and connection errors reject instead of leaving requests pending', async () => {
  const socket = new FakeSocket()
  const request = socketRequest(socket.socket, {
    event: 'sio/package/list',
    decode: () => {
      throw new Error('invalid data')
    },
  })
  socket.requests[0].acknowledge(null, new Uint8Array([1]))
  await assert.rejects(request, /invalid data/)
  const next = socketRequest(socket.socket, { event: 'sio/package/list', decode: data => data })
  socket.emit('connect_error', new Error('connection refused'))
  await assert.rejects(next, /connection refused/)
  assert.equal(socket.eventNames().length, 0)
})

it('failed refresh preserves installed packages and supports retry', async () => {
  let fail = false
  const server = { packageList: async () => {
    if (fail)
      throw new Error('offline')
    return index
  } }
  const manager = new PackageManager(server as Server)
  await manager.init()
  fail = true
  await assert.rejects(manager.reload(), /offline/)
  assert.equal(manager.packageIndex.path('hal', 'demo', '1.0.0'), 'hal/demo/1.0.0')
  assert.equal(manager.error.value, 'offline')
  assert.equal(manager.loading.value, false)
  fail = false
  await manager.reload()
  assert.equal(manager.error.value, '')
})

it('refresh invalidates description cache after a package is replaced', async () => {
  let calls = 0
  const server = { packageList: async () => index, getPackageDescription: async () => description(`revision-${++calls}`) }
  const manager = new PackageManager(server as unknown as Server)
  await manager.init()
  assert.equal((await manager.getPackageDescription('hal', 'demo', '1.0.0')).name, 'revision-1')
  await manager.getPackageDescription('hal', 'demo', '1.0.0')
  assert.equal(calls, 1)
  await manager.reload()
  assert.equal((await manager.getPackageDescription('hal', 'demo', '1.0.0')).name, 'revision-2')
})

it('package mutations prevent duplicate submissions and release busy state on failure', async () => {
  let rejectInstall!: (error: Error) => void
  const server = { packageInstall: () => new Promise((_, reject) => {
    rejectInstall = reject
  }) }
  const manager = new PackageManager(server as unknown as Server)
  const install = manager.install('test.csppack')
  assert.equal(manager.busy.value, true)
  await assert.rejects(manager.install('test.csppack'), /in progress/)
  await assert.rejects(manager.uninstall('hal', 'demo', '1.0.0'), /in progress/)
  rejectInstall(new Error('invalid package'))
  await assert.rejects(install, /invalid package/)
  assert.equal(manager.busy.value, false)
})

it('successful uninstall removes stale entries even if the following refresh fails', async () => {
  let fail = false
  const server = {
    packageList: async () => {
      if (fail)
        throw new Error('offline')
      return index
    },
    packageUninstall: async () => true,
  }
  const manager = new PackageManager(server as Server)
  await manager.init()
  fail = true
  await manager.uninstall('hal', 'demo', '1.0.0')
  assert.deepEqual(manager.packageIndex.origin.value, {})
  assert.equal(manager.error.value, 'offline')
})
