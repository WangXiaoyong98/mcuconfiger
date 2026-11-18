import type { Socket } from 'socket.io-client'

interface RequestOptions<T> {
  event: string
  payload?: Uint8Array
  decode: (response: Uint8Array) => T
  timeout?: number
  progressEvent?: string
  onProgress?: (response: Uint8Array) => void
}

/** Use acknowledgements so concurrent requests cannot consume each other's result. */
export function socketRequest<T>(socket: Socket | undefined, options: RequestOptions<T>): Promise<T> {
  if (!socket)
    return Promise.reject(new Error('Backend server is not connected'))

  return new Promise((resolve, reject) => {
    let settled = false
    let timer: ReturnType<typeof setTimeout>

    function cleanup() {
      clearTimeout(timer)
      socket!.off('connect', send)
      socket!.off('connect_error', fail)
      socket!.off('disconnect', disconnected)
      if (options.progressEvent)
        socket!.off(options.progressEvent, progress)
    }

    function fail(error: unknown) {
      if (settled)
        return
      settled = true
      cleanup()
      reject(error instanceof Error ? error : new Error(String(error)))
    }

    function resetTimeout() {
      clearTimeout(timer)
      timer = setTimeout(() => fail(new Error(`${options.event}: no response from the server. Refresh packages to check the result before retrying.`)), options.timeout ?? 15000)
    }

    function disconnected() {
      fail(new Error('Backend server disconnected'))
    }

    function progress(response: ArrayBuffer) {
      if (settled)
        return
      resetTimeout()
      try {
        options.onProgress?.(new Uint8Array(response))
      }
      catch (error) {
        fail(error)
      }
    }

    function acknowledge(response: ArrayBuffer) {
      if (settled)
        return
      try {
        if (!response)
          throw new Error('The backend did not return a package result. Please restart the application.')
        const result = options.decode(new Uint8Array(response))
        settled = true
        cleanup()
        resolve(result)
      }
      catch (error) {
        fail(error)
      }
    }

    function send() {
      if (settled)
        return
      // Do not buffer operations while disconnected: a timed-out install must not run later.
      // Socket.IO also expires its internal acknowledgement entry if the server never replies.
      const sender = socket!.timeout(Math.max(options.timeout ?? 15000, 300000))
      const callback = (error: Error | null, response: ArrayBuffer) => error ? fail(error) : acknowledge(response)
      if (options.payload === undefined)
        sender.emit(options.event, callback)
      else
        sender.emit(options.event, options.payload, callback)
    }

    socket.on('connect_error', fail)
    socket.on('disconnect', disconnected)
    if (options.progressEvent)
      socket.on(options.progressEvent, progress)
    resetTimeout()
    if (socket.connected) {
      send()
    }
    else {
      socket.once('connect', send)
      socket.connect()
    }
  })
}
