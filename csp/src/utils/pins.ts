/**
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        pins.ts
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
 *  2025-09-11     xqyjlj       initial version
 */

import type { App, ComputedRef, ShallowReactive } from 'vue'
import type { Project, ProjectConfigsPinUnitType, ProjectManager } from './project'
import type { Ip, IpManager, IpParameter, IpRefParameter, Summary, SummaryManager, SummaryPin } from '~/database'
import { computed, inject, markRaw, shallowReactive, watchEffect } from 'vue'
import { IpObject, isEnumParameter } from '~/database/ip'
import { allocateSignals } from './pinmux'

export class Pin {
  private _parameters: Record<string, ComputedRef<IpParameter>>
  private _project: Project
  private _presets?: Record<string, IpObject>
  private _path: string
  private _ipPath: string
  private _functionPath: string
  private _modePath: string
  private _labelPath: string
  private _lockedPath: string
  private _item: ShallowReactive<ProjectConfigsPinUnitType>

  constructor(
    private _name: string,
    private _summaryPin: SummaryPin,
    private _ip: Ip,
  ) {
    this._project = _ip.project()

    this._path = `pins.${this._name}`
    this._ipPath = `${this._ip.instance}.${this._name}`
    this._functionPath = `${this._path}.function`
    this._modePath = `${this._path}.mode`
    this._labelPath = `${this._path}.label`
    this._lockedPath = `${this._path}.locked`

    this._parameters = _ip.buildParameters(this._name)

    this._item = shallowReactive<ProjectConfigsPinUnitType>({
      function: this._project.configs.get(this._functionPath, ''),
      mode: this._project.configs.get(this._modePath, ''),
      label: this._project.configs.get(this._labelPath, ''),
      locked: this._project.configs.get(this._lockedPath, false),
      position: this.position,
    })

    this._project.configs.emitter.on('changed', this._onProjectConfigsChanged.bind(this))

    watchEffect(() => {
      if (!this.function.value)
        return
      const direction = this.parameters.gpio_direction_t?.value
      const pad = this.parameters.gpio_pin_type_t?.value
      if (direction && pad && isEnumParameter(pad)) {
        const allowed = direction.value.value === 'output' ? ['push_pull', 'open_drain'] : ['pullup', 'pulldown']
        if (!allowed.includes(pad.value.value) && allowed[0] in pad.values)
          pad.value.value = allowed[0]
      }
    })
  }

  get name(): string {
    return this._name
  }

  function = computed((): string => this._item.function!)

  mode = computed((): string => this._item.mode!)

  label = computed({
    get: (): string => this._item.label!,
    set: (value: string | null) => {
      this._project.configs.set(this._labelPath, value)
    },
  })

  locked = computed({
    get: (): boolean => this._item.locked!,
    set: (value: boolean) => {
      this._project.configs.set(this._lockedPath, value)
    },
  })

  state = computed((): string => {
    const key = this.mode.value || this.function.value
    if (key && key.includes(':')) {
      const parts = key.split(':')
      // 对于 GPIO 功能，直接返回一个固定的预设名称
      // 这样不管选择输入还是输出，都会显示所有配置选项
      if (parts[0] === this._ip.instance) {
        return this.parameters.gpio_direction_t?.value.value.value === 'output' ? 'Output' : 'Input'
      }
      return this.presets[parts[1]] ? parts[1] : 'Input'
    }
    return 'unknown'
  })

  get parameters(): Record<string, ComputedRef<IpParameter>> {
    return this._parameters
  }

  get presets(): Record<string, IpObject> {
    if (!this._presets) {
      this._presets = {}
      for (const [presetName, presetValue] of Object.entries(this._ip.origin.presets ?? {})) {
        this._presets[presetName] = new IpObject(presetValue, this._parameters, this._ip)
      }
    }
    return this._presets
  }

  refParameters = computed((): Record<string, IpRefParameter> => {
    return this.presets[this.state.value]?.refParameters.value ?? {}
  })

  get position(): number {
    return this._summaryPin.position
  }

  get type(): string {
    return this._summaryPin.type
  }

  get signals(): string[] {
    return this._summaryPin.signals
  }

  get modes(): string[] {
    return this._summaryPin.modes
  }

  get functions(): string[] {
    return this._summaryPin.functions()
  }

  reset() {
    this._project.configs.set<Record<string, any>>(this._ipPath, {})
    this._project.configs.set<ProjectConfigsPinUnitType>(this._path, {})
  }

  setFunction(func: string, mode: string = '', locked = true) {
    if (!this.functions.includes(func))
      return
    if (func !== this.function.value) {
      const state = (mode || func).split(':')[1]
      const presets = this.presets[state] ?? this.presets.Input
      if (presets) {
        const models: Record<string, any> = {}
        for (const [key, refParameter] of Object.entries(presets.refParameters.value)) {
          models[key] = refParameter.default.value
        }
        this._project.configs.set<Record<string, any>>(this._ipPath, models)
      }
    }

    this._project.configs.set<ProjectConfigsPinUnitType>(this._path, {
      locked,
      function: func,
      mode,
      label: this.label.value,
      position: this.position,
    })
  }

  unsetFunction() {
    this._project.configs.set<Record<string, any>>(this._ipPath, {})
    this._project.configs.set<ProjectConfigsPinUnitType>(this._path, {
      locked: false,
      function: '',
      mode: '',
      label: this.label.value,
      position: this.position,
    })
  }

  private _onProjectConfigsChanged(payload: { path: string[], newValue: any, oldValue: any }) {
    const path = payload.path.join('.')

    if (path === this._functionPath) {
      this._item.function = payload.newValue
    }
    else if (path === this._modePath) {
      this._item.mode = payload.newValue
    }
    else if (path === this._labelPath) {
      this._item.label = payload.newValue
    }
    else if (path === this._lockedPath) {
      this._item.locked = payload.newValue
    }
    else if (path === this._path || this._path.startsWith(`${path}.`)) {
      const value = this._project.configs.get<ProjectConfigsPinUnitType>(this._path, {})
      this._item.function = value.function ?? ''
      this._item.mode = value.mode ?? ''
      this._item.label = value.label ?? ''
      this._item.locked = value.locked ?? false
      this._item.position = value.position ?? this.position
    }
  }
}

export class PinsManager {
  private _pins: Record<string, Pin> = markRaw({})
  private _project?: Project
  private _summary?: Summary
  private _ips: Ip[] = []
  private _managedSignals = new Set<string>()

  constructor() {
  }

  get pins(): Record<string, Pin> {
    return this._pins
  }

  requirements = computed(() => {
    const signals = new Map<string, string>()
    for (const ip of this._ips) {
      if (ip.isPinIp || !ip.activated.value)
        continue
      const refs = { ...ip.containers.modes.refParameters.value, ...ip.containers.configurations.refParameters.value, ...ip.containers.clockTree.refParameters.value }
      for (const ref of Object.values(refs)) {
        const parameter = ref.parameter.value
        if (ref.condition.value && parameter.enabled.value && isEnumParameter(parameter)) {
          for (const [name, signal] of Object.entries(parameter.signals.value ?? {}))
            signals.set(name, signal.mode)
        }
      }
    }
    return signals
  })

  allocation = computed(() => {
    void this._project?.configs.revision.value
    return allocateSignals([...this.requirements.value.keys()].map(signal => ({
      signal,
      pins: this._summary?.findPinsBySignals([signal]) ?? [],
    })), this._project?.configs.get('pins', {}) ?? {})
  })

  init(project: Project, summary: Summary, ipManager: IpManager) {
    this._project = project
    this._summary = summary
    this._ips = ipManager.getPeripherals(project.vendor)
    watchEffect(() => {
      const result = this.allocation.value
      if (!result.success)
        return
      const assigned = new Set(Object.values(result.assignments))
      for (const pin of Object.values(this.pins)) {
        if (!pin.locked.value && this._managedSignals.has(pin.function.value) && !assigned.has(pin.name))
          pin.unsetFunction()
      }
      for (const [signal, name] of Object.entries(result.assignments)) {
        const pin = this.pins[name]
        const mode = this.requirements.value.get(signal) ?? ''
        if (pin.function.value !== signal || (!pin.locked.value && pin.mode.value !== mode))
          pin.setFunction(signal, mode, false)
      }
      this._managedSignals = new Set(this.requirements.value.keys())
    })
  }

  assign(name: string, func: string): 'locked' | 'duplicate' | 'unsupported' | null {
    const pin = this.pins[name]
    if (!pin || (func && !pin.functions.includes(func)))
      return 'unsupported'
    if (pin.function.value === func)
      return null
    if (pin.locked.value)
      return 'locked'
    if (func && !pin.modes.includes(func)) {
      const duplicate = Object.values(this.pins).find(other => other.name !== name && other.function.value === func)
      if (duplicate?.locked.value)
        return 'duplicate'
      duplicate?.unsetFunction()
    }
    if (func)
      pin.setFunction(func)
    else
      pin.unsetFunction()
    return null
  }
}

export function createPinsManagerPlugin() {
  const manager = new PinsManager()

  function init(projectManager: ProjectManager, summaryManager: SummaryManager, ipManager: IpManager) {
    const project = projectManager.get()
    if (project) {
      const summary = summaryManager.get(project.vendor, project.targetChip)
      if (summary) {
        const ip = ipManager.getPeripheral(project.vendor, summary.pinInstance)
        if (ip) {
          for (const [name, summaryPin] of Object.entries(summary.pins)) {
            manager.pins[name] = markRaw(new Pin(name, summaryPin, ip))
          }
          manager.init(project, summary, ipManager)
        }
      }
      else {
        console.error(`No summary found for vendor: ${project.vendor}, targetChip: ${project.targetChip}`)
      }
    }
  }

  return {
    manager,
    plugin: {
      install(app: App) {
        app.provide('utils@pinsManager', manager)
      },
    },
    init,
  }
}

export function usePinsManager(): PinsManager {
  return inject('utils@pinsManager')!
}
