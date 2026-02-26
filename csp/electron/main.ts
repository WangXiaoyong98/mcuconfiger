/**
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        main.ts
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
 *  2025-04-26     xqyjlj       initial version
 */

import type { ProcessArgsType } from './types'
import path from 'node:path'
import { fileURLToPath } from 'node:url'
import { app, BrowserWindow, dialog } from 'electron'
import * as handlers from './ipc-handlers'
import { createWindow } from './src/window'
import { clientOffline, createServer, processArgs } from './utils'
import { accessSync, constants, mkdirSync } from 'node:fs'
import './src/cli'

// 检查必要的权限
function checkPermissions() {
  try {
    // 检查是否有写入配置文件的权限
    const configDir = path.join(app.getPath('userData'), 'config')
    mkdirSync(configDir, { recursive: true })
    accessSync(configDir, constants.W_OK)
    
    // 检查是否有写入临时文件的权限
    const tempDir = app.getPath('temp')
    accessSync(tempDir, constants.W_OK)
    
    console.log('Permission check passed')
  } catch (error) {
    console.error('Permission check failed:', error)
    dialog.showErrorBox('Permission Error', 'The application does not have sufficient permissions to run. Please run as administrator.')
    app.quit()
  }
}

const __dirname = path.dirname(fileURLToPath(import.meta.url))

process.env.APP_ROOT = path.join(__dirname, '..')

export const VITE_DEV_SERVER_URL = process.env.VITE_DEV_SERVER_URL
export const MAIN_DIST = path.join(process.env.APP_ROOT, 'dist-electron')
export const RENDERER_DIST = path.join(process.env.APP_ROOT, 'dist')

process.env.VITE_PUBLIC = VITE_DEV_SERVER_URL ? path.join(process.env.APP_ROOT, 'public') : RENDERER_DIST
process.env.MAIN_DIST = MAIN_DIST
process.env.RENDERER_DIST = RENDERER_DIST

const gotTheLock = app.requestSingleInstanceLock(processArgs)
if (!gotTheLock) {
  app.quit()
}

app.on('second-instance', (_event: Electron.Event, _argv: string[], _workingDirectory: string, additionalData: unknown) => {
  const data = additionalData as ProcessArgsType
  createWindow(data)
})

app.on('window-all-closed', () => {
  if (processArgs.backendUrl) {
    clientOffline(processArgs.backendUrl)
  }
  if (process.platform !== 'darwin') {
    app.quit()
  }
})

app.on('activate', async () => {
  if (BrowserWindow.getAllWindows().length === 0) {
    processArgs.backendUrl = await createServer()
    createWindow(processArgs)
  }
})

app.whenReady().then(async () => {
  checkPermissions()
  try {
    processArgs.backendUrl = await createServer()
    createWindow(processArgs)
  } catch (error) {
    console.error('Failed to start backend server:', error)
    dialog.showErrorBox('Backend Server Error', `Failed to start backend server: ${error instanceof Error ? error.message : String(error)}\n\nPlease check if the server files are properly installed.`)
    app.quit()
  }
})

app.whenReady().then(() => {
  const handlersTyped = handlers as Record<string, () => void>
  for (const handler in handlersTyped) {
    handlersTyped[handler]()
  }
})
