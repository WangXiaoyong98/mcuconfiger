/**
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        server.ts
 *  @brief
 *
 * ****************************************************************************
 *  @attention
 *  Licensed under the Apache License v. 2 (the "License");
 *  You may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      https://www.apache.org/licenses/LICENSE-2.0.html
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  Copyright (C) 2025-2025 xqyjlj<xqyjlj@126.com>
 *
 * ****************************************************************************
 *  Change Logs:
 *  Date           Author       Notes
 *  ------------   ----------   -----------------------------------------------
 *  2025-07-10     xqyjlj       initial version
 */

import type { ProjectType } from '@/electron/types'
import type { Socket } from 'socket.io-client'
import type { App } from 'vue'
import type { PackageDescriptionType, PackageIndexType } from './packages'
import type { SioCoderDumpResponseFile } from '~/proto/sio_coder_dump'
import { io } from 'socket.io-client'
import { inject, markRaw } from 'vue'
import { SioCoderDumpProgress, SioCoderDumpRequest, SioCoderDumpResponse } from '~/proto/sio_coder_dump'
import { SioCoderGenerateProgress, SioCoderGenerateRequest, SioCoderGenerateResponse } from '~/proto/sio_coder_generate'
import { SioPackageDescriptionRequest, SioPackageDescriptionResponse } from '~/proto/sio_package_description'
import { SioPackageInstallProgress, SioPackageInstallRequest, SioPackageInstallResponse } from '~/proto/sio_package_install'
import { SioPackageListResponse } from '~/proto/sio_package_list'
import { SioPackageUninstallRequest, SioPackageUninstallResponse } from '~/proto/sio_package_uninstall'
import { socketRequest } from './socketRequest'

// #region typedef

export interface CoderDumpResponseType {
  [k: string]: SioCoderDumpResponseFile
}

export interface PackageIndexResponseType {
  [kind: string]: {
    [name: string]: {
      [version: string]: string
    }
  }
}

export class Server {
  private _url: string
  private _socket?: Socket

  constructor(url: string) {
    this._url = url

    if (!url) {
      console.error('Backend URL is empty. Cannot connect to server.')
      window.electron.send('system:showError', {
        title: 'Backend Server Error',
        message: 'Backend server URL is not available. Please restart the application.',
      })
      return
    }

    this._socket = io(url, {
      timeout: 5000,
      reconnectionAttempts: 0,
    })

    this._socket.on('connect_error', (error) => {
      console.error('Failed to connect to backend server:', error)
      window.electron.send('system:showError', {
        title: 'Backend Server Error',
        message: `Failed to connect to backend server at ${url}. Please check if the server is running.\n\nFix suggestions:\n1. Ensure the server files are properly installed\n2. Run the application as administrator\n3. Check if port 55432 is not blocked by firewall`,
      })
    })
  }

  get url(): string {
    return this._url
  }

  get socket(): Socket | undefined {
    return this._socket
  }

  async coderDump(
    content: ProjectType | null,
    path: string,
    diff: boolean,
    onProgress?: (count: number, index: number, file: string) => void,
  ): Promise<CoderDumpResponseType> {
    return new Promise((resolve, reject) => {
      const socket = this._socket
      if (!socket) {
        const error = new Error('Backend server is not connected')
        console.error('coderDump failed:', error)
        reject(error)
        return
      }
      if (onProgress) {
        socket.on('coder/dump.progress', (progress: ArrayBuffer) => {
          const req = SioCoderDumpProgress.decode(new Uint8Array(progress))
          onProgress(req.count, req.index, req.file)
        })
      }

      const req = SioCoderDumpRequest.fromPartial({
        content: content as any,
        path,
        diff,
      })

      const buf = SioCoderDumpRequest.encode(req).finish()
      socket.emit('sio/coder/dump', buf)

      socket.once('coder/dump.result', (response: ArrayBuffer) => {
        if (onProgress) {
          socket.off('coder/dump.progress')
        }
        const resp = SioCoderDumpResponse.decode(new Uint8Array(response))
        if (resp.success) {
          resolve(resp.files)
        }
        else {
          console.error(`Failed to coder dump: ${resp.error}`)
          reject(new Error(resp.error))
        }
      })
    })
  }

  async coderGenerate(
    path: string,
    output?: string,
    files?: string[],
    onProgress?: (count: number, index: number, file: string, write: boolean) => void,
    timeout = 30000,
  ): Promise<boolean> {
    return new Promise((resolve, reject) => {
      const socket = this._socket
      if (!socket) {
        const error = new Error('Backend server is not connected')
        console.error('coderGenerate failed:', error)
        reject(error)
        return
      }
      let timeoutId: ReturnType<typeof setTimeout> | null = null

      if (onProgress) {
        socket.on('coder/generate.progress', (progress: ArrayBuffer) => {
          const req = SioCoderGenerateProgress.decode(new Uint8Array(progress))
          onProgress(req.count, req.index, req.file, req.write)
        })
      }

      timeoutId = setTimeout(() => {
        if (onProgress) {
          socket.off('coder/generate.progress')
        }
        socket.off('coder/generate.result')
        reject(new Error(`coderGenerate timeout after ${timeout}ms`))
      }, timeout)

      const req = SioCoderGenerateRequest.fromPartial({
        path,
        output,
        files,
      })

      const buf = SioCoderGenerateRequest.encode(req).finish()
      socket.emit('sio/coder/generate', buf)

      socket.once('coder/generate.result', (response: ArrayBuffer) => {
        if (timeoutId) {
          clearTimeout(timeoutId)
        }
        if (onProgress) {
          socket.off('coder/generate.progress')
        }

        const resp = SioCoderGenerateResponse.decode(new Uint8Array(response))
        if (resp.success) {
          resolve(true)
        }
        else {
          console.error(`Failed to coder generate: ${resp.error}`)
          reject(new Error(resp.error))
        }
      })
    })
  }

  async packageList(): Promise<PackageIndexType> {
    return socketRequest(this._socket, {
      event: 'sio/package/list',
      decode: (data) => {
        const response = SioPackageListResponse.decode(data)
        if (!response.success)
          throw new Error(response.error || 'Failed to load packages')
        return response.packages ?? {}
      },
    })
  }

  async getPackageDescription(type: string, name: string, version: string): Promise<PackageDescriptionType> {
    const request = SioPackageDescriptionRequest.fromPartial({ type, name, version })
    return socketRequest(this._socket, {
      event: 'sio/package/description',
      payload: SioPackageDescriptionRequest.encode(request).finish(),
      decode: (data) => {
        const response = SioPackageDescriptionResponse.decode(data)
        if (!response.success || !response.description)
          throw new Error(response.error || 'Package description is unavailable')
        return response.description as PackageDescriptionType
      },
    })
  }

  async packageInstall(
    path: string,
    onProgress?: (count: number, index: number, file: string) => void,
  ): Promise<PackageDescriptionType> {
    const request = SioPackageInstallRequest.fromPartial({ path })
    return socketRequest(this._socket, {
      event: 'sio/package/install',
      payload: SioPackageInstallRequest.encode(request).finish(),
      timeout: 60000,
      progressEvent: 'package/install.progress',
      onProgress: (data) => {
        const progress = SioPackageInstallProgress.decode(data)
        onProgress?.(progress.count, progress.index, progress.file)
      },
      decode: (data) => {
        const response = SioPackageInstallResponse.decode(data)
        if (!response.success || !response.description)
          throw new Error(response.error || 'Failed to install package')
        return response.description as PackageDescriptionType
      },
    })
  }

  async packageUninstall(type: string, name: string, version: string): Promise<boolean> {
    const request = SioPackageUninstallRequest.fromPartial({ type, name, version })
    return socketRequest(this._socket, {
      event: 'sio/package/uninstall',
      payload: SioPackageUninstallRequest.encode(request).finish(),
      timeout: 60000,
      decode: (data) => {
        const response = SioPackageUninstallResponse.decode(data)
        if (!response.success)
          throw new Error(response.error || 'Failed to uninstall package')
        return true
      },
    })
  }
}

// #endregion

export class ServerManager {
  private _server: Server | null = null

  async init() {
    try {
      const url = await window.electron.invoke('server:getUrl')
      if (url) {
        this._server = markRaw(new Server(url))
      }
      else {
        console.error('Failed to get backend server URL')
        window.electron.send('system:showError', {
          title: 'Backend Server Error',
          message: 'Failed to get backend server URL. Please restart the application.',
        })
      }
    }
    catch (error) {
      console.error('Error initializing server manager:', error)
      window.electron.send('system:showError', {
        title: 'Backend Server Error',
        message: `Error initializing server connection: ${error instanceof Error ? error.message : String(error)}`,
      })
    }
  }

  get server(): Server {
    return this._server!
  }
}

export function createServerManagerPlugin() {
  const manager = new ServerManager()

  return {
    manager,
    plugin: {
      install(app: App) {
        app.provide('utils@serverManager', manager)
      },
    },
    async init() {
      await manager.init()
    },
  }
}

export function useServerManager(): ServerManager {
  return inject('utils@serverManager')!
}
