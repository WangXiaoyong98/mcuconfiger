#!/usr/bin/env python3
# -*- coding:utf-8 -*-

# Licensed under the Apache License v. 2 (the "License")
# You may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     https://www.apache.org/licenses/LICENSE-2.0.html
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#
# Copyright (C) 2025-2025 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        builder.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-12-15     xqyjlj       initial version
#

import copy

from csp.project import Project
from . import chip

inc_dirs = [
    "core/inc",
    "hal/libraries/cmsis/device",
    "hal/libraries/cmsis/inc",
    "hal/libraries/std_drivers/inc",
]

src_files_group = {
    "Core": [
        "core/src/csp_gpio.c",
        "core/src/csp_main.c",
    ],
    "device": [
        "core/src/csp_board.c",
    ],
    "cmsis": [
        "core/src/csp_system_sp28038.c",
    ],
    "startup": [
        "startup_arm.s",
    ],
    "std_drivers": [
        "hal/libraries/std_drivers/src/adc.c",
        "hal/libraries/std_drivers/src/crc.c",
        "hal/libraries/std_drivers/src/dcc.c",
        "hal/libraries/std_drivers/src/dma.c",
        "hal/libraries/std_drivers/src/dmamux.c",
        "hal/libraries/std_drivers/src/ecap.c",
        "hal/libraries/std_drivers/src/epwm.c",
        "hal/libraries/std_drivers/src/eqep.c",
        "hal/libraries/std_drivers/src/ewm.c",
        "hal/libraries/std_drivers/src/gpio.c",
        "hal/libraries/std_drivers/src/i2c.c",
        "hal/libraries/std_drivers/src/lin.c",
        "hal/libraries/std_drivers/src/lin_sci.c",
        "hal/libraries/std_drivers/src/lptim.c",
        "hal/libraries/std_drivers/src/mcan.c",
        "hal/libraries/std_drivers/src/ptim.c",
        "hal/libraries/std_drivers/src/rcm.c",
        "hal/libraries/std_drivers/src/sci.c",
        "hal/libraries/std_drivers/src/spi_dma.c",
        "hal/libraries/std_drivers/src/spi.c",
        "hal/libraries/std_drivers/src/sysctl.c",
        "hal/libraries/std_drivers/src/wwdt.c",
        "hal/libraries/std_drivers/src/xbar.c",
    ],
    "utilities": [
        "hal/libraries/Utilities/adapter_uart.c",
        "hal/libraries/Utilities/assert.c",
        "hal/libraries/Utilities/debug_console.c",
        "hal/libraries/Utilities/retarget/retarget.c",
        "hal/libraries/Utilities/retarget/uart_stdout.c",
    ],
}

device_map = {
    "SP28038": ["SP28038"],
}


def builder_defines(project: Project) -> list[str]:
    cl = chip.chip_info(project)
    li = [cl["class"], "SP28038"]
    return li


def builder_inc_dirs(project: Project) -> list:
    return inc_dirs


def builder_src_files_group(project: Project) -> dict:
    group = copy.deepcopy(src_files_group)

    builder = project.gen.builder
    toolchains = project.gen.toolchains

    # Startup files are now in fixed startup group
    # No need to dynamically add them to Core group

    for key in group.keys():
        group[key].sort()

    return group


def builder_src_files(project: Project) -> list:
    files = []

    for _, value in builder_src_files_group(project).items():
        files.extend(value)

    files = list(set(files))
    files.sort()

    return files
