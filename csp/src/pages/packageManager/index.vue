<!--
 * ****************************************************************************
 *  @author      xqyjlj
 *  @file        index.vue
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
import type PackageInstaller from '~/components/PackageInstaller.vue'
import type { PackageDescription } from '~/utils'
import type { PackageSelection } from '~/utils/packageCatalog'
import { ElMessageBox, ElNotification } from 'element-plus'
import { computed, onBeforeUnmount, shallowRef, watch } from 'vue'
import { useI18n } from 'vue-i18n'
import { usePackageManager, useProjectManager } from '~/utils'
import { buildPackageTree, packageKey } from '~/utils/packageCatalog'

const { t } = useI18n()
const manager = usePackageManager()
const projectManager = useProjectManager()
const { loading, error, busy } = manager
const installer = shallowRef<InstanceType<typeof PackageInstaller>>()
const query = shallowRef('')
const kind = shallowRef('')
const selected = shallowRef<PackageSelection | null>(null)
const description = shallowRef<PackageDescription>()
const descriptionError = shallowRef('')
const loadingDescription = shallowRef(false)
const confirming = shallowRef(false)
let descriptionRequest = 0

const kinds = computed(() => manager.packageIndex.types().sort())
const total = computed(() => Object.values(manager.packageIndex.origin.value)
  .reduce((count, names) => count + Object.values(names).reduce((sum, versions) => sum + Object.keys(versions).length, 0), 0))
const filteredTree = computed(() => buildPackageTree(manager.packageIndex.origin.value, query.value, kind.value))
const shown = computed(() => filteredTree.value.reduce((count, group) => count + group.children!.reduce((sum, item) => sum + item.children!.length, 0), 0))
const selectedKey = computed(() => selected.value ? packageKey(selected.value) : '')

function inUse(selection: PackageSelection): boolean {
  const project = projectManager?.get()
  if (!project)
    return false
  if (selection.kind === 'hal')
    return project.gen.hal.value === selection.name && project.gen.halVersion.value === selection.version
  return selection.kind === 'toolchains' && project.gen.useToolchainsPackage.value
    && project.gen.toolchains.value === selection.name && project.gen.toolchainsVersion.value === selection.version
}
const selectedInUse = computed(() => selected.value ? inUse(selected.value) : false)

function select(kind: string, name: string, version: string) {
  selected.value = { kind, name, version }
}

async function loadDescription() {
  const request = ++descriptionRequest
  const selection = selected.value
  description.value = undefined
  descriptionError.value = ''
  loadingDescription.value = !!selection
  if (!selection)
    return
  try {
    const result = await manager.getPackageDescription(selection.kind, selection.name, selection.version)
    if (request === descriptionRequest)
      description.value = result
  }
  catch (error) {
    if (request === descriptionRequest)
      descriptionError.value = error instanceof Error ? error.message : String(error)
  }
  finally {
    if (request === descriptionRequest)
      loadingDescription.value = false
  }
}

watch([selected, manager.packageIndex.origin], () => {
  const item = selected.value
  if (item && !manager.packageIndex.path(item.kind, item.name, item.version)) {
    selected.value = null
    return
  }
  loadDescription()
}, { immediate: true })
watch(kinds, (values) => {
  if (kind.value && !values.includes(kind.value))
    kind.value = ''
})
onBeforeUnmount(() => {
  descriptionRequest++
})

async function refresh() {
  await manager.reload().catch(() => {})
}

function installed(selection: PackageSelection) {
  query.value = ''
  kind.value = ''
  selected.value = selection
}

async function uninstall(selection: PackageSelection | null = selected.value) {
  if (!selection || busy.value || confirming.value)
    return
  if (inUse(selection)) {
    ElNotification({ title: t('label.error'), message: t('packageManager.inUse'), type: 'warning', offset: 35 })
    return
  }
  confirming.value = true
  try {
    await ElMessageBox.confirm(
      t('packageManager.confirmUninstall', { name: selection.name, version: selection.version }),
      t('command.uninstall'),
      { type: 'warning', confirmButtonText: t('command.uninstall'), cancelButtonText: t('packageManager.cancel') },
    )
  }
  catch {
    return
  }
  finally {
    confirming.value = false
  }
  // Recheck after the confirmation: project/package state may have changed meanwhile.
  if (busy.value || inUse(selection))
    return
  try {
    await manager.uninstall(selection.kind, selection.name, selection.version)
    ElNotification({ title: t('label.success'), message: t('message.uninstallSuccess'), type: 'success', offset: 35 })
  }
  catch (error) {
    ElNotification({
      title: t('label.error'),
      message: `${t('message.uninstallFailed')}: ${error instanceof Error ? error.message : String(error)}`,
      type: 'error',
      duration: 0,
      offset: 35,
    })
  }
}
</script>

<template>
  <section class="package-manager">
    <header class="package-toolbar">
      <div class="heading">
        <h2>{{ $t('label.packages') }}</h2>
        <el-tag type="info">
          {{ $t('packageManager.installedCount', { count: total }) }}
        </el-tag>
      </div>
      <div class="toolbar-actions">
        <el-button type="primary" :disabled="busy || confirming" @click="installer?.install()">
          <i class="ri-add-line" aria-hidden="true" /> {{ $t('message.installPackage') }}
        </el-button>
        <el-button :disabled="busy || confirming" @click="installer?.install(true)">
          {{ $t('packageManager.installFolder') }}
        </el-button>
        <el-button :loading="loading" :disabled="busy" @click="refresh">
          {{ $t('packageManager.refresh') }}
        </el-button>
      </div>
    </header>
    <el-alert v-if="error" :title="$t('packageManager.loadFailed')" :description="error" type="error" show-icon :closable="false" />
    <el-splitter class="package-panels">
      <el-splitter-panel :min="240" size="300" max="50%">
        <div class="package-sidebar">
          <div class="package-filters">
            <el-input v-model="query" clearable :placeholder="$t('packageManager.search')" :aria-label="$t('packageManager.search')">
              <template #prefix>
                <i class="ri-search-line" aria-hidden="true" />
              </template>
            </el-input>
            <el-select v-model="kind" :placeholder="$t('packageManager.allTypes')" :aria-label="$t('packageManager.allTypes')">
              <el-option value="" :label="$t('packageManager.allTypes')" />
              <el-option v-for="item in kinds" :key="item" :label="item" :value="item" />
            </el-select>
            <span class="package-count">{{ $t('packageManager.showingCount', { shown, total }) }}</span>
          </div>
          <PackageTree :query="query" :kind="kind" :selected-key="selectedKey" :disabled="busy || confirming" @click="select" @uninstall="uninstall" />
        </div>
      </el-splitter-panel>
      <el-splitter-panel :min="280">
        <div class="package-details">
          <div v-if="selected" class="detail-actions">
            <span class="selected-name" :title="selected.name">{{ selected.name }} · {{ selected.version }}</span>
            <el-tooltip :content="$t('packageManager.inUse')" :disabled="!selectedInUse">
              <span><el-button type="danger" plain :disabled="busy || confirming || selectedInUse" @click="uninstall()">{{ $t('command.uninstall') }}</el-button></span>
            </el-tooltip>
          </div>
          <el-scrollbar class="details-scrollbar">
            <div v-if="loadingDescription" class="detail-placeholder">
              <el-skeleton :rows="7" animated />
            </div>
            <div v-else-if="descriptionError" class="detail-placeholder">
              <el-alert :title="$t('packageManager.descriptionFailed')" :description="descriptionError" type="error" show-icon :closable="false" />
              <el-button class="retry-button" @click="loadDescription">
                {{ $t('packageManager.retry') }}
              </el-button>
            </div>
            <PackageInfo v-else-if="description" :description="description" />
            <el-empty v-else :description="$t(total ? 'packageManager.selectPackage' : 'packageManager.empty')">
              <p v-if="!total" class="empty-hint">
                {{ $t('packageManager.emptyHint') }}
              </p>
            </el-empty>
          </el-scrollbar>
        </div>
      </el-splitter-panel>
    </el-splitter>
    <PackageInstaller ref="installer" @installed="installed" />
  </section>
</template>

<style scoped>
.package-manager {
  display: flex;
  flex: 1;
  flex-direction: column;
  min-width: 0;
  min-height: 0;
}
.package-toolbar {
  display: flex;
  align-items: center;
  justify-content: space-between;
  flex-wrap: wrap;
  gap: 12px;
  padding: 16px;
  border-bottom: 1px solid var(--ep-border-color-light);
}
.heading,
.toolbar-actions {
  display: flex;
  align-items: center;
  flex-wrap: wrap;
  gap: 8px;
}
.heading h2 {
  margin: 0;
  font-size: 18px;
}
.toolbar-actions :deep(.ep-button + .ep-button) {
  margin-left: 0;
}
.package-panels {
  flex: 1;
  min-height: 0;
}
.package-sidebar,
.package-details {
  display: flex;
  flex-direction: column;
  height: 100%;
  min-height: 0;
  min-width: 0;
}
.package-filters {
  display: flex;
  flex-direction: column;
  gap: 10px;
  padding: 16px;
}
.package-count,
.empty-hint {
  font-size: 12px;
  color: var(--ep-text-color-secondary);
}
.detail-actions {
  display: flex;
  align-items: center;
  justify-content: space-between;
  gap: 12px;
  padding: 12px 16px;
  border-bottom: 1px solid var(--ep-border-color-light);
}
.selected-name {
  overflow: hidden;
  text-overflow: ellipsis;
  white-space: nowrap;
}
.details-scrollbar {
  flex: 1;
  min-height: 0;
}
.detail-placeholder {
  padding: 24px;
}
.retry-button {
  margin-top: 12px;
}
.empty-hint {
  max-width: 320px;
  line-height: 1.7;
  text-align: center;
  padding: 0 16px;
}
</style>
