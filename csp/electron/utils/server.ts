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
 *  2025-10-20     xqyjlj       initial version
 */

import type { Buffer } from 'node:buffer'
import { spawn } from 'node:child_process'
import axios from 'axios'
import { app } from 'electron'
import * as path from 'node:path'
import * as fs from 'node:fs'
import { processArgs } from './args'
import { getServerFolder } from './settings'

export function clientOnline(url: string) {
  if (!app.isPackaged) {
    return
  }

  axios.get(`${url}/api/client/online`, { params: { id: process.pid } })
    .then(() => {
    })
    .catch((error) => {
      console.error('clientOnline Error:', error.message)
    })
}

export function clientOffline(url: string) {
  if (!app.isPackaged) {
    return
  }

  axios.get(`${url}/api/client/offline`, { params: { id: process.pid } })
    .then(() => {
    })
    .catch((error) => {
      if (axios.isAxiosError(error)) {
        if (error.code === 'ECONNRESET') {
          /* !< 服务端已经断开 */
          return
        }
      }
      console.error('clientOffline Error:', error.message)
    })
}

export function createServer(): Promise<string> {
  return new Promise((resolve, reject) => {
    if (!app.isPackaged) {
      if (processArgs.backendUrl) {
        resolve(processArgs.backendUrl)
      } else {
        reject(new Error('Backend URL is not provided in development mode'))
      }
      return
    }

    try {
      const serverFolder = getServerFolder()
      const exePath = path.join(serverFolder, 'csp-server.exe')
      const pyPath = path.join(serverFolder, 'csp-server.py')

      console.log('Server folder:', serverFolder)
      console.log('Server folder exists:', fs.existsSync(serverFolder))
      console.log('Checking for csp-server.exe:', fs.existsSync(exePath))
      console.log('Checking for csp-server.py:', fs.existsSync(pyPath))
      
      // List files in server folder for debugging
      try {
        const files = fs.readdirSync(serverFolder)
        console.log('Files in server folder:', files.slice(0, 20)) // Limit to first 20 files
      } catch (error) {
        console.error('Failed to read server folder:', error)
      }

      let process
      let commandUsed
      let exeFullPath = exePath

      // Get user data directory for writable storage
      const userDataDir = app.getPath('userData')
      const serverUserDataDir = path.join(userDataDir, 'server')
      const logDir = path.join(serverUserDataDir, 'log')
      
      // Create user data directories if they don't exist
      if (!fs.existsSync(serverUserDataDir)) {
        try {
          fs.mkdirSync(serverUserDataDir, { recursive: true })
          console.log('Created server user data directory:', serverUserDataDir)
        } catch (error) {
          console.error('Failed to create server user data directory:', error)
        }
      }
      
      if (!fs.existsSync(logDir)) {
        try {
          fs.mkdirSync(logDir, { recursive: true })
          console.log('Created log directory:', logDir)
        } catch (error) {
          console.error('Failed to create log directory:', error)
        }
      }
      
      // Also create a log directory in the server folder as a fallback
      const serverLogDir = path.join(serverFolder, 'log')
      if (!fs.existsSync(serverLogDir)) {
        try {
          fs.mkdirSync(serverLogDir, { recursive: true })
          console.log('Created fallback log directory:', serverLogDir)
        } catch (error) {
          console.error('Failed to create fallback log directory:', error)
        }
      }
      
      if (fs.existsSync(exePath)) {
        console.log('Using csp-server.exe at:', exePath)
        commandUsed = 'csp-server.exe'
        
        // Use serverFolder as cwd to ensure server can find its dependencies
        // But set TEMP environment variable to user data directory to avoid permission issues
        process = spawn(exePath, ['serve', '-p', '55432'], {
          cwd: serverFolder,
          env: { 
            ...global.process.env, 
            'PYTHONUNBUFFERED': '1',
            'CSP_USER_DATA_DIR': serverUserDataDir,
            'CSP_LOG_DIR': logDir,
            'TEMP': logDir,
            'TMP': logDir
          }
        })
      } else if (fs.existsSync(pyPath)) {
        console.log('Using csp-server.py with python at:', pyPath)
        commandUsed = 'python csp-server.py'
        
        // Use serverFolder as cwd to ensure server can find its dependencies
        // But set TEMP environment variable to user data directory to avoid permission issues
        process = spawn('python', [pyPath, 'serve', '-p', '55432'], {
          cwd: serverFolder,
          env: { 
            ...global.process.env, 
            'PYTHONUNBUFFERED': '1',
            'CSP_USER_DATA_DIR': serverUserDataDir,
            'CSP_LOG_DIR': logDir,
            'TEMP': logDir,
            'TMP': logDir
          }
        })
      } else {
        const errorMsg = 'Neither csp-server.exe nor csp-server.py found'
        console.error(errorMsg)
        console.error('Server folder path:', serverFolder)
        console.error('Files in server folder:', fs.readdirSync(serverFolder))
        reject(new Error(errorMsg))
        return
      }

      let resolved = false

      const timeout = setTimeout(() => {
        if (!resolved) {
          resolved = true
          const errorMsg = `Server startup timeout after 10s using ${commandUsed}. Please check if the server has sufficient permissions and resources.`
          console.error(errorMsg)
          process.kill()
          reject(new Error(errorMsg))
        }
      }, 10000)

      const checkOutput = (data: Buffer) => {
        const text = data.toString()
        console.log('Server output:', text)
        
        // Check for error messages
        if (text.includes('error') || text.includes('Error') || text.includes('ERROR')) {
          console.error('Server error detected:', text)
          // Don't immediately reject, wait for timeout to handle it
        }
        
        // Match both 127.0.1.x and 127.0.0.1 formats, with optional prefix
        const match = text.match(/(?:Serving on )?http:\/\/(127\.0\.(?:0|1)\.1):(\d+)/)
        if (match) {
          const url = match[0].replace('Serving on ', '')
          resolved = true
          clearTimeout(timeout)
          console.log('Server started successfully at:', url)
          /* !< 延时 1s 等待服务端真正启动 */
          setTimeout(() => {
            clientOnline(url)
            resolve(url)
          }, 1000)
        }
      }

      process.stdout!.on('data', checkOutput)
      process.stderr!.on('data', checkOutput)
      
      // Also log the server's PID and environment variables for debugging
      console.log('Server process PID:', process.pid)
      console.log('Server environment variables:', {
        'CSP_USER_DATA_DIR': serverUserDataDir,
        'CSP_LOG_DIR': logDir,
        'TEMP': logDir,
        'TMP': logDir
      })

      process.once('error', (err) => {
        if (!resolved) {
          resolved = true
          clearTimeout(timeout)
          const errorMsg = `Failed to spawn server process: ${err.message}. Please check if the server has sufficient permissions and is not blocked by antivirus software. Server path: ${exeFullPath}`
          console.error(errorMsg)
          reject(new Error(errorMsg))
        }
      })

      process.once('exit', (code, signal) => {
        if (!resolved) {
          resolved = true
          clearTimeout(timeout)
          const errorMsg = `Server exited with code ${code}${signal ? ` (signal: ${signal})` : ''} using ${commandUsed}. Please check the server logs for more details. Server path: ${exeFullPath}. Working directory: ${serverFolder}`
          console.error(errorMsg)
          reject(new Error(errorMsg))
        }
      })

      // Try to ping the server after a short delay to check if it's running
      setTimeout(() => {
        if (!resolved) {
          console.log('Trying to ping server to check if it\'s running...')
          try {
            const http = require('http')
            const req = http.get('http://127.0.0.1:55432', (res: any) => {
              if (res.statusCode === 200) {
                resolved = true
                clearTimeout(timeout)
                console.log('Server is running successfully at http://127.0.0.1:55432')
                setTimeout(() => {
                  clientOnline('http://127.0.0.1:55432')
                  resolve('http://127.0.0.1:55432')
                }, 1000)
              }
              res.resume()
            })
            req.on('error', () => {
              // Server not responding yet, continue waiting
            })
            req.setTimeout(2000, () => {
              req.destroy()
            })
          } catch (error) {
            console.error('Error pinging server:', error)
          }
        }
      }, 3000)
    }
    catch (error) {
      const errorMsg = `Error in createServer: ${error instanceof Error ? error.message : String(error)}`
      console.error(errorMsg)
      reject(new Error(errorMsg))
    }
  })
}
