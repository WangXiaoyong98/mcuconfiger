<script setup lang="ts">
import type { Pin } from '~/utils/pins'
import { ElMessage } from 'element-plus'
import { computed, shallowReactive, shallowRef, watch } from 'vue'
import { useI18n } from 'vue-i18n'
import { usePinsManager } from '~/utils/pins'

const emit = defineEmits<{ select: [name: string] }>()
const manager = usePinsManager()
const { t } = useI18n()
const search = shallowRef('')
const configuredOnly = shallowRef(false)
const pins = computed(() => Object.values(manager.pins).filter(pin => pin.functions.length > 0))
const labels = shallowReactive<Record<string, string>>({})
watch(() => pins.value.map(pin => [pin.name, pin.label.value]), (values) => {
  for (const [name, label] of values)
    labels[name] = label
}, { immediate: true })
const configured = computed(() => pins.value.filter(pin => pin.function.value).length)
const rows = computed(() => {
  const terms = search.value.trim().toLowerCase().split(/\s+/).filter(Boolean)
  return pins.value.filter(pin => (!configuredOnly.value || pin.function.value)
    && terms.every(term => `${pin.name} ${pin.position} ${pin.label.value} ${pin.functions.join(' ')}`.toLowerCase().includes(term)))
    .sort((a, b) => a.position - b.position)
})

function assign(pin: Pin, value: string) {
  const error = manager.assign(pin.name, value)
  if (error)
    ElMessage.warning(t(`configuration.${error}`))
  else
    emit('select', pin.name)
}

function label(pin: Pin, value: string) {
  const trimmed = value.trim()
  if (trimmed && (!/^[A-Z_]\w*$/i.test(trimmed) || pins.value.some(other => other !== pin && other.label.value === trimmed))) {
    ElMessage.warning(t('configuration.invalidLabel'))
    labels[pin.name] = pin.label.value
    return
  }
  pin.label.value = trimmed
}
</script>

<template>
  <div class="pinmux-panel">
    <div class="pinmux-toolbar">
      <el-input v-model="search" clearable :placeholder="$t('configuration.searchPins')" />
      <el-checkbox v-model="configuredOnly">
        {{ $t('configuration.configuredOnly') }}
      </el-checkbox>
      <el-tag>{{ configured }} / {{ pins.length }}</el-tag>
    </div>
    <el-alert
      v-if="!manager.allocation.value.success"
      :title="$t('configuration.pinConflicts')"
      :description="manager.allocation.value.conflicts.join(', ')"
      type="warning"
      :closable="false"
      show-icon
    />
    <el-table :data="rows" row-key="name" height="100%" highlight-current-row @row-click="(pin: Pin) => emit('select', pin.name)">
      <el-table-column prop="position" :label="$t('configuration.position')" width="58" />
      <el-table-column prop="name" :label="$t('label.name')" width="92" />
      <el-table-column :label="$t('pin.function')" min-width="156">
        <template #default="{ row }: { row: Pin }">
          <el-select :model-value="row.function.value" filterable :empty-values="[null, undefined]" :placeholder="$t('configuration.unassigned')" :disabled="row.locked.value" @change="(value: string) => assign(row, value)">
            <el-option value="" :label="$t('configuration.unassigned')" />
            <el-option v-for="func in row.functions" :key="func" :label="func" :value="func" />
          </el-select>
        </template>
      </el-table-column>
      <el-table-column :label="$t('pin.label')" min-width="110">
        <template #default="{ row }: { row: Pin }">
          <el-input v-model="labels[row.name]" @change="(value: string) => label(row, value)" />
        </template>
      </el-table-column>
      <el-table-column :label="$t('configuration.lock')" width="68">
        <template #default="{ row }: { row: Pin }">
          <el-switch v-model="row.locked.value" :disabled="!row.function.value" />
        </template>
      </el-table-column>
    </el-table>
  </div>
</template>

<style scoped>
.pinmux-panel {
  display: flex;
  flex-direction: column;
  flex: 1;
  min-height: 0;
  gap: 12px;
  padding: 12px;
}
.pinmux-toolbar {
  display: flex;
  align-items: center;
  gap: 12px;
  flex-wrap: wrap;
}
.pinmux-toolbar .ep-input {
  flex: 1;
  min-width: 180px;
}
</style>
