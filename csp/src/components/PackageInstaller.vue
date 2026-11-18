<script setup lang="ts">
import type { FileProgressDialogInstance } from './instance'
import type { PackageSelection } from '~/utils/packageCatalog'
import { ElNotification } from 'element-plus'
import { shallowRef } from 'vue'
import { useI18n } from 'vue-i18n'
import { showOpenDialog, usePackageManager } from '~/utils'

const emit = defineEmits<{ installed: [selection: PackageSelection] }>()
const { t } = useI18n()
const manager = usePackageManager()
const progressDialog = shallowRef<FileProgressDialogInstance>()
let choosing = false

async function install(fromDirectory = false) {
  if (manager.busy.value || choosing)
    return
  choosing = true
  try {
    const { filePaths, canceled } = await showOpenDialog({
      title: t(fromDirectory ? 'packageManager.installFolder' : 'message.installPackage'),
      properties: [fromDirectory ? 'openDirectory' : 'openFile'],
      ...(!fromDirectory && { filters: [{ name: t('fileType.csppack'), extensions: ['csppack'] }] }),
    })
    if (canceled || filePaths?.length !== 1)
      return
    progressDialog.value?.reset()
    progressDialog.value?.show(t('label.installing'))
    const description = await manager.install(filePaths[0], (count, index, file) => {
      progressDialog.value?.updateProgress(count, index, file)
    })
    ElNotification({ title: t('label.success'), message: t('message.installSuccess'), type: 'success', offset: 35 })
    emit('installed', { kind: description.type.toLowerCase(), name: description.name, version: description.version.toLowerCase() })
  }
  catch (error) {
    ElNotification({
      title: t('label.error'),
      message: `${t('message.installFailed')}: ${error instanceof Error ? error.message : String(error)}`,
      type: 'error',
      duration: 0,
      offset: 35,
    })
  }
  finally {
    choosing = false
    progressDialog.value?.hide()
  }
}

defineExpose({ install })
</script>

<template>
  <FileProgressDialog ref="progressDialog" />
</template>
