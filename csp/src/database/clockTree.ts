/**
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        clockTree.ts
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
 *  2025-05-15     xqyjlj       initial version
 */

import type {
  ClockTreeEdgeType,
  ClockTreeEdgeTypeType,
  ClockTreeNodeType,
  ClockTreeNodeTypeType,
  ClockTreeNodeUnitType,
  ClockTreeType,
} from '@/electron/types'
import type { XYPosition } from '@vue-flow/core'
import type { App } from 'vue'
import type { Ip, IpManager, IpParameter } from './ip'
import type { ClockInput } from '~/utils/clockCalculation'
import { computed, inject, markRaw, shallowRef, watchEffect } from 'vue'
import { calculateClocks } from '~/utils/clockCalculation'
import { isEnumParameter, isNumberParameter } from './ip'

// #region typedef

export class ClockTree {
  private _nodes: Record<string, ClockTreeNode> = {}
  private _edges: Record<string, ClockTreeEdge> = {}
  private _revision = shallowRef(0)

  calculation = computed(() => {
    void this._revision.value
    const inputs: Record<string, ClockInput> = {}
    for (const [name, node] of Object.entries(this.nodes)) {
      const parameter = node.parameter.value
      if (!parameter)
        continue
      inputs[name] = {
        type: node.type,
        value: parameter.value.value,
        enabled: parameter.enabled.value,
        options: isEnumParameter(parameter)
          ? Object.fromEntries(Object.entries(node.refParameter.value?.values.value ?? parameter.values).map(([key, value]) => [key, value.enabled.value]))
          : undefined,
        min: isNumberParameter(parameter) ? parameter.min.value : undefined,
        max: isNumberParameter(parameter) ? parameter.max.value : undefined,
      }
    }
    return calculateClocks(inputs, Object.values(this._origin.edges))
  })

  constructor(
    private _origin: ClockTreeType,
    public ip: Ip,
  ) {
    for (const [name, node] of Object.entries(this._origin.nodes)) {
      this._nodes[name] = markRaw(new ClockTreeNode(node, name, this))
    }

    for (const [name, edge] of Object.entries(this._origin.edges)) {
      this._edges[name] = new ClockTreeEdge(edge)
    }

    // Persist derived frequencies even when the clock page has never been opened.
    watchEffect(() => {
      const { outputs } = this.calculation.value
      for (const [name, node] of Object.entries(this.nodes)) {
        if (node.type === 'ct-output' || node.type === 'ct-probe') {
          const parameter = node.parameter.value
          if (parameter && isNumberParameter(parameter))
            parameter.value.value = outputs[name] ?? 0
        }
      }
    })
  }

  get origin(): ClockTreeType {
    return this._origin
  }

  get instance(): string {
    return this._origin.instance
  }

  get nodes(): Record<string, ClockTreeNode> {
    return this._nodes
  }

  get edges(): Record<string, ClockTreeEdge> {
    return this._edges
  }

  updateEdges(edges: Record<string, ClockTreeEdgeType>) {
    this._edges = {}
    this._origin.edges = edges
    for (const [name, edge] of Object.entries(this._origin.edges)) {
      this._edges[name] = new ClockTreeEdge(edge)
    }
    this._revision.value++
  }
}

export class ClockTreeEdge {
  constructor(
    private _origin: ClockTreeEdgeType,
  ) {
  }

  get origin(): ClockTreeEdgeType {
    return this._origin
  }

  get type(): ClockTreeEdgeTypeType {
    return this._origin.type
  }

  get source(): string {
    return this._origin.source
  }

  get target(): string {
    return this._origin.target
  }

  get sourceHandle(): string | undefined | null {
    return this._origin.sourceHandle
  }

  get targetHandle(): string | undefined | null {
    return this._origin.targetHandle
  }

  get label(): string | undefined {
    return this._origin.label
  }
}

export class ClockTreeNode {
  constructor(
    private _origin: ClockTreeNodeType,
    private _name: string,
    private _parent: ClockTree,
  ) {
  }

  get origin(): ClockTreeNodeType {
    return this._origin
  }

  get ip(): Ip {
    return this._parent.ip
  }

  get ref(): string {
    return this._name
  }

  refParameter = computed(() => this.ip.containers.clockTree.refParameters.value[this._name])

  parameter = computed((): IpParameter | undefined => this.refParameter.value?.parameter.value)

  output = computed(() => this._parent.calculation.value.outputs[this._name] ?? 0)

  issues = computed(() => this._parent.calculation.value.issues.filter(issue => issue.node === this._name))

  enabled = computed((): boolean => this.parameter.value?.enabled.value ?? false)

  readonly = computed((): boolean => !this.enabled.value || (this.refParameter.value?.readonly.value ?? true))

  get type(): ClockTreeNodeTypeType {
    return this._origin.type
  }

  get position(): XYPosition {
    return this._origin.position ??= { x: 0, y: 0 }
  }

  get unit(): ClockTreeNodeUnitType | undefined {
    return this._origin.unit
  }
}

// #endregion

export class ClockTreeManager {
  private _map: Record<string, Record<string, { clockTree: ClockTree, define: string }>> = markRaw({})
  private _ipManager?: IpManager

  constructor() {
  }

  setIpManager(ipManager: IpManager) {
    this._ipManager = markRaw(ipManager)
  }

  async load(vendor: string, name: string, define: string) {
    const content = await window.electron.invoke('database:getClockTree', vendor, define) as ClockTreeType
    const ip = content && this._ipManager?.getPeripheral(vendor, content.instance)
    if (content && ip) {
      const clockTree = new ClockTree(content, ip);
      (this._map[vendor] ??= {})[name] = markRaw({ clockTree, define })
    }
  }

  save(vendor: string, name: string, clockTree?: ClockTree) {
    if (this._map[vendor]?.[name]) {
      const define = this._map[vendor][name].define
      clockTree ??= this._map[vendor][name].clockTree
      window.electron.send('database:setClockTree', vendor, define, clockTree.origin)
    }
  }

  get(vendor: string, name: string): ClockTree | null {
    if (this._map[vendor]?.[name]) {
      return this._map[vendor][name].clockTree
    }

    return null
  }
}

export function createClockTreeManagerPlugin() {
  const manager = new ClockTreeManager()

  return {
    manager,
    plugin: {
      install(app: App) {
        app.provide('database@clockTreeManager', manager)
      },
    },
    setIpManager(ipManager: IpManager) {
      manager.setIpManager(ipManager)
    },
  }
}

export function useClockTreeManager(): ClockTreeManager {
  return inject('database@clockTreeManager')!
}
