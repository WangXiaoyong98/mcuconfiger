<!--
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        PackageTree.vue
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
 *  2025-08-03     xqyjlj       initial version
-->

<script setup lang="ts">
import type { MenuOptions } from '@imengyu/vue3-context-menu'
import type { PackageSelection, PackageTreeNode } from '~/utils/packageCatalog'
import { ElTree } from 'element-plus'
import { computed, shallowReactive, shallowRef } from 'vue'
import { usePackageManager } from '~/utils'
import { buildPackageTree } from '~/utils/packageCatalog'

const props = withDefaults(defineProps<{
  query?: string
  kind?: string
  selectedKey?: string
  disabled?: boolean
}>(), { query: '', kind: '', selectedKey: '', disabled: false })
const emit = defineEmits<{
  click: [kind: string, name: string, version: string]
  uninstall: [selection: PackageSelection]
}>()
const manager = usePackageManager()
const tree = computed(() => buildPackageTree(manager.packageIndex.origin.value, props.query, props.kind))
const expandedKeys = computed(() => tree.value.flatMap(group => [group.key, ...group.children!.map(item => item.key)]))
const menuVisible = shallowRef(false)
const menuOptions = shallowReactive<MenuOptions>({ x: 0, y: 0, minWidth: 180 })
const contextSelection = shallowRef<PackageSelection>()

function select(data: PackageTreeNode) {
  if (data.selection)
    emit('click', data.selection.kind, data.selection.name, data.selection.version)
}

function handleContextMenu(event: MouseEvent, data: PackageTreeNode) {
  event.preventDefault()
  if (!data.selection || props.disabled)
    return
  select(data)
  contextSelection.value = data.selection
  menuOptions.x = event.clientX
  menuOptions.y = event.clientY
  menuVisible.value = true
}

function uninstall() {
  menuVisible.value = false
  if (contextSelection.value && !props.disabled)
    emit('uninstall', contextSelection.value)
}
</script>

<template>
  <el-scrollbar class="package-tree">
    <ElTree
      v-if="tree.length"
      node-key="key"
      :data="tree"
      :default-expanded-keys="expandedKeys"
      :current-node-key="selectedKey"
      :expand-on-click-node="false"
      highlight-current
      @node-click="select"
      @node-contextmenu="handleContextMenu"
    >
      <template #default="{ node, data }">
        <i :class="data.type === 'version' ? 'ri-price-tag-3-line' : 'ri-folder-3-line'" class="node-icon" aria-hidden="true" />
        <span class="node-label" :title="node.label">{{ node.label }}</span>
      </template>
    </ElTree>
    <el-empty v-else :image-size="56" :description="$t('packageManager.noMatches')" />
    <context-menu v-model:show="menuVisible" :options="menuOptions">
      <context-menu-item icon="ri-uninstall-line" :label="$t('command.uninstall')" @click="uninstall" />
    </context-menu>
  </el-scrollbar>
</template>

<style scoped>
.package-tree {
  flex: 1;
  min-height: 0;
  min-width: 0;
  width: 100%;
}
.node-icon {
  margin-right: 8px;
  color: var(--ep-color-primary);
}
.node-label {
  overflow: hidden;
  text-overflow: ellipsis;
}
</style>
