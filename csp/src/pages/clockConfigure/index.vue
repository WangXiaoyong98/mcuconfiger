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
 *  2025-05-13     xqyjlj       initial version
-->

<script setup lang="ts">
import type { ClockViewInstance } from '~/components/instance'
import { nextTick, shallowRef } from 'vue'
import { useClockTreeManager } from '~/database'
import { useProjectManager } from '~/utils'

const clockViewRef = shallowRef<ClockViewInstance>()
const project = useProjectManager().get()
const clock = project ? useClockTreeManager().get(project.vendor, project.targetChip) : null

function handZoomIn() {
  clockViewRef.value?.zoomIn()
}

function handRescale() {
  clockViewRef.value?.rescale()
}

function handZoomOut() {
  clockViewRef.value?.zoomOut()
}

async function handDownload() {
  clockViewRef.value?.rescale() /* !< 强制重新缩放，否则会导致下载的图像不正确 */
  await nextTick()
  clockViewRef.value?.downloadSvg()
}
</script>

<template>
  <div class="main-div flex">
    <el-empty v-if="!clock" :description="$t('configuration.noClock')" />
    <template v-else>
      <el-collapse class="clock-settings">
        <el-collapse-item :title="$t('configuration.clockSources')" name="sources">
          <IpConfigurator type="modes" :instance="clock.instance" />
        </el-collapse-item>
      </el-collapse>
      <el-alert
        v-if="clock.calculation.value.issues.length"
        :title="$t('configuration.clockIssues')"
        type="warning"
        :closable="false"
        show-icon
      >
        <div v-for="issue in clock.calculation.value.issues" :key="`${issue.node}-${issue.reason}`">
          {{ clock.nodes[issue.node]?.parameter.value?.display.value || issue.node }}:
          {{ $t(`configuration.${issue.reason}`) }}
        </div>
      </el-alert>
      <div class="clock-div flex">
        <ClockView ref="clockViewRef" />
      </div>
    </template>
    <div class="my-4 items-center justify-center" style="text-align: center;">
      <el-tooltip :content="$t('command.zoomIn')">
        <el-button circle @click="handZoomIn">
          <el-icon><i class="ri-zoom-in-line" /></el-icon>
        </el-button>
      </el-tooltip>
      <el-tooltip :content="$t('command.fullScreen')">
        <el-button circle @click="handRescale">
          <el-icon><i class="ri-fullscreen-line" /></el-icon>
        </el-button>
      </el-tooltip>
      <el-tooltip :content="$t('command.zoomOut')">
        <el-button circle @click="handZoomOut">
          <el-icon><i class="ri-zoom-out-line" /></el-icon>
        </el-button>
      </el-tooltip>
      <el-tooltip :content="$t('command.export')">
        <el-button circle @click="handDownload">
          <el-icon><i class="ri-export-line" /></el-icon>
        </el-button>
      </el-tooltip>
    </div>
  </div>
</template>

<style scoped>
.main-div {
  display: flex;
  flex: 1;
  flex-direction: column;
  min-width: 0;
  min-height: 0;
}

.clock-div {
  display: flex;
  flex: 1;
  min-width: 0;
  min-height: 0;
}

.clock-settings :deep(.ep-collapse-item__content) {
  max-height: 240px;
  overflow: auto;
}

.main-div > .ep-alert {
  max-height: 150px;
  overflow: auto;
  flex-shrink: 0;
}
</style>
