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
# Copyright (C) 2022-2024 xqyjlj<xqyjlj@126.com>
#
# @author      xqyjlj
# @file        generator.py
#
# Change Logs:
# Date           Author       Notes
# ------------   ----------   -----------------------------------------------
# 2024-10-12     xqyjlj       initial version
#

import glob
import os
import shutil
import xml.etree.ElementTree as etree
from typing import Callable

from csp.project import Project
from .filters import builder, chip

script_dir = os.path.dirname(__file__)
root_dir = os.path.join(script_dir, "..", "..")


def _remove_trailing_digits(s):
    return s.rstrip("0123456789")


def files_table(project: Project) -> dict[str, dict[str, str]]:
    all_modules = [
        "ADC",
        "CRC",
        "DCC",
        "DMA",
        "DMAMUX",
        "ECAP",
        "EPWM",
        "EQEP",
        "EWM",
        "FLASH",
        "GPIO",
        "I2C",
        "I2S",
        "LIN_SCI",
        "LIN",
        "LPTIM",
        "MCAN",
        "PTIM",
        "RCM",
        "SCI",
        "SPI_DMA",
        "SPI",
        "SYSCTRL",
        "WWDT",
        "XBAR",
    ]
    files = {
        "core/inc/csp_main.h": {"brief": "main program body"},
        "core/src/csp_main.c": {"brief": "main program body"},
        "core/src/csp_isr.c": {"brief": "interrupt function entry"},
        "core/inc/csp_board.h": {"brief": "board header file"},
        "core/src/csp_board.c": {"brief": "board source file"},
        "core/src/csp_system_sp28038.c": {
            "brief": "CMSIS Cortex-M4 Device Peripheral Access Layer System Source File"
        },
        ".gitignore": {"force": False},
    }

    modules: list[str] = project.modules
    for module in all_modules:
        mod = module.lower()
        name = _remove_trailing_digits(mod)
        files[f"core/inc/csp/csp_{mod}.h"] = {
            "brief": f"this file provides code for the csp_{mod} initialization",
            "template": f"csp_{name}.h.j2",
            "module": module,
        }
        files[f"core/src/csp_{mod}.c"] = {
            "brief": f"this file provides code for the csp_{mod} initialization",
            "template": f"csp_{name}.c.j2",
            "module": module,
        }
        if module not in modules:
            files[f"core/inc/csp/csp_{mod}.h"]["gen"] = False  # type: ignore
            files[f"core/src/csp_{mod}.c"]["gen"] = False  # type: ignore

    builder = project.gen.builder
    targetChip = project.targetChip
    toolchains = project.gen.toolchains

    if builder == "CMake":
        files["CMakeLists.txt"] = {
            "brief": "this file provides code for the cmake build system"
        }
    elif builder == "XMake":
        files["xmake.lua"] = {
            "brief": "this file provides code for the xmake build system"
        }
    elif builder == "MDK-Arm":
        files[f"{project.name}.uvprojx"] = {}
        files["startup_arm.s"] = {
            "brief": f"CMSIS Cortex-M3 based Core Device Startup File for Device {targetChip}"
        }

    if toolchains == "gcc-arm-none-eabi":
        files[f"{targetChip}.lds"] = {
            "brief": f"this file provides linker script for the {targetChip} device",
            "template": "linker_script.lds.j2",
        }
        files["startup_gcc.S"] = {
            "brief": f"CMSIS Cortex-M3 based Core Device Startup File for Device {targetChip}"
        }

    return files


def copy_library(
    project: Project, output: str, callback: Callable[[str, int, int, bool, str], None]
):
    file_list = [
        "libraries/cmsis/device/arm/*",
        "libraries/cmsis/device/gcc/*",
        "libraries/cmsis/inc/*",
        "libraries/std_drivers/inc/*.h",
        "libraries/std_drivers/src/*.c",
        "libraries/std_drivers/src/*.h",
        ".clang-format",
        ".gitattributes",
        ".gitignore",
        "LICENSE",
        "README*.md",
    ]

    li = {}

    # libraries
    for match in file_list:
        for source in glob.glob(f"{root_dir}/{match}"):
            dest = f"{output}/hal/{os.path.relpath(source, root_dir)}"
            dest = dest.replace("\\", "/")
            li[source] = dest

    count = len(li)
    for index, (source, dest) in enumerate(li.items(), start=1):
        if not os.path.exists(dest):
            if not os.path.isdir(os.path.dirname(dest)):
                os.makedirs(os.path.dirname(dest))
            shutil.copy(source, dest)
            callback(dest, index, count, True, "because the file does not exist")
        else:
            callback(dest, index, count, False, "because the file already exists")


def get_mdk(project: Project, path: str = ""):
    if not path or not os.path.isfile(path):
        path = f"{root_dir}/tools/generator/resource/template.uvprojx"

    tree = etree.parse(path)

    info = chip.chip_info(project)
    cpu = (
        f'IRAM(0x{info["ram"]["addr"]:08X},0x{info["ram"]["size"]:08X}) '
        f'IROM(0x{info["flash"]["addr"]:08X},0x{info["flash"]["size"]:08X}) '
        'CPUTYPE("Cortex-M4") CLOCK(12000000) ELITTLE'
    )
    defines = builder.builder_defines(project)
    includes = builder.builder_inc_dirs(project)
    files = builder.builder_src_files_group(project)

    return {
        "etree": tree,
        "cpu": cpu,
        "vendor": "StarPower",
        "defines": defines,
        "includes": includes,
        "files": files,
        "line": info["line"],
    }
