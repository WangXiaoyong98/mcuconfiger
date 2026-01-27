#!/usr/bin/env python3
# -*- coding:utf-8 -*-

#
# ------------------------------------------------------------------------------
#  @author:            csplink coder
#  @file:              gpio.py
#  @version:           0.0.6
#  @time:              2025-11-15 17:54:10
#
# ------------------------------------------------------------------------------
#  @attention
#
#  Copyright (C) 2025 csplink software.
#  All rights reserved.
#
# ------------------------------------------------------------------------------
#

from typing import Literal

from csp.project import Project

# --< user code begin import, do not change this comment!
# isort: off
import json
import yaml

# isort: on
# --> user code end import, do not change this comment!

# ------------------------------------------------------------------------------
# region autogen filters
# fmt: off

_gpio_mode_t_return_type = Literal[
    "af_od",
    "af_pp",
    "analog",
    "evt_falling",
    "evt_rising",
    "evt_rising_falling",
    "input",
    "it_falling",
    "it_rising",
    "it_rising_falling",
    "output_od",
    "output_pp",
]


_gpio_pull_t_return_type = Literal[
    "nopull",
    "pulldown",
    "pullup",
]


_gpio_speed_t_return_type = Literal[
    "high",
    "low",
    "medium",
]


_gpio_state_t_return_type = Literal[
    "reset",
    "set",
]


_gpio_pin_type_t_return_type = Literal[
    "push_pull",
    "open_drain",
    "pullup",
    "pulldown",
]


def gpio_mode_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_mode_t_return_type = "input",
) -> _gpio_mode_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_mode_t", default)


def gpio_pull_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_pull_t_return_type = "nopull",
) -> _gpio_pull_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_pull_t", default)


def gpio_speed_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_speed_t_return_type = "low",
) -> _gpio_speed_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_speed_t", default)


def gpio_state_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_state_t_return_type = "reset",
) -> _gpio_state_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_state_t", default)


def gpio_pin_type_t(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: _gpio_pin_type_t_return_type = "push_pull",
) -> _gpio_pin_type_t_return_type:
    return project.configs.get(f"{instance}.{channel}.gpio_pin_type_t", default)


def gpio_pad_config(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: str = "GPIO_PIN_TYPE_IE",
) -> str:
    result = project.configs.get(f"{instance}.{channel}.gpio_pad_config", default)
    if not result:
        return default
    return result


def gpio_qualification_mode(
    project: Project,
    channel: str,
    instance: str = "GPIO",
    default: str = "GPIO_QUAL_SYNC",
) -> str:
    result = project.configs.get(f"{instance}.{channel}.gpio_qualification_mode", default)
    if not result:
        return default
    return result


def gpio_channel_pin_type(project: Project, channel: str) -> str:
    try:
        pin_type = gpio_pin_type_t(project, channel)
        
        if pin_type == "push_pull":
            return "GPIO_PIN_TYPE_IE"
        elif pin_type == "open_drain":
            return "GPIO_PIN_TYPE_IE | GPIO_PIN_TYPE_OD"
        elif pin_type == "pullup":
            return "GPIO_PIN_TYPE_IE | GPIO_PIN_TYPE_PULLUP"
        elif pin_type == "pulldown":
            return "GPIO_PIN_TYPE_IE | GPIO_PIN_TYPE_PULLDOWN"
        else:
            return "GPIO_PIN_TYPE_IE"
    except Exception:
        return "GPIO_PIN_TYPE_IE"


def gpio_channels(
    project: Project,
    instance: str = "GPIO",
) -> list[str]:
    return list(project.configs.get(instance, {}).keys())


def pin_function(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.function", default)


def pin_label(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.label", default)


def pin_locked(
    project: Project,
    channel: str,
    default: bool = False,
) -> bool:
    return project.configs.get(f"pins.{channel}.locked", default)


def pin_mode(
    project: Project,
    channel: str,
    default: str = "",
) -> str:
    return project.configs.get(f"pins.{channel}.mode", default)


def pin_channels(
    project: Project,
) -> str:
    return list(project.configs.get("pins", {}).keys())


def get_gpio_number_from_chip_db(
    project: Project,
    function_name: str,
    default: str = "0"
) -> str:
    """
    从芯片数据库中根据功能名称获取GPIO编号
    """
    # 通过项目对象获取目标芯片型号
    target_chip = getattr(project, 'targetChip', None)
    if not target_chip:
        return default
    
    # 构建芯片数据库文件路径 - 使用灵活的路径查找
    import os
    
    # 智能搜索可能的路径
    possible_paths = []
    
    # 1. 当前工作目录 (后端启动路径)
    cwd = os.getcwd()
    possible_paths.append(os.path.join(cwd, 'csp', 'resources', 'database', 'summary', 'StarPower', f'{target_chip}.yml'))
    
    # 2. 脚本所在目录的上级目录
    script_dir = os.path.dirname(os.path.abspath(__file__))
    # 向上导航到不同层级
    for i in range(1, 8):  # 尝试向上8级
        search_dir = script_dir
        for _ in range(i):
            search_dir = os.path.dirname(search_dir)
        possible_paths.append(os.path.join(search_dir, 'csp', 'resources', 'database', 'summary', 'StarPower', f'{target_chip}.yml'))
    
    # 3. 常见的开发目录
    common_dirs = [
        os.path.expanduser('~'),  # 用户主目录
        os.path.join(os.path.expanduser('~'), 'Desktop'),  # 桌面
        os.path.join(os.path.expanduser('~'), 'Documents'),  # 文档
    ]
    for common_dir in common_dirs:
        possible_paths.append(os.path.join(common_dir, 'mcufix', 'csp', 'resources', 'database', 'summary', 'StarPower', f'{target_chip}.yml'))
        possible_paths.append(os.path.join(common_dir, 'mcu0114', 'csp', 'resources', 'database', 'summary', 'StarPower', f'{target_chip}.yml'))
    
    # 找到第一个存在的路径
    db_path = None
    for path in possible_paths:
        if os.path.exists(path):
            db_path = path
            break
    
    # 如果都找不到，使用默认路径
    if not db_path:
        # 默认使用脚本所在目录的上级目录
        default_root = os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(os.path.dirname(script_dir)))))
        db_path = os.path.join(default_root, 'csp', 'resources', 'database', 'summary', 'StarPower', f'{target_chip}.yml')
    
    try:
        if os.path.exists(db_path):
            # 读取芯片数据库文件
            with open(db_path, 'r', encoding='utf-8') as f:
                import yaml
                chip_data = yaml.safe_load(f)
            
            # 获取引脚信息
            chip_pins = chip_data.get('pins', {}) if chip_data else {}
            
            # 调试：输出要查找的功能名称
            # print(f"Looking for function: {function_name}")
            
            for pin_name, pin_info in chip_pins.items():
                if "signals" in pin_info:
                    for signal in pin_info["signals"]:
                        # 处理字符串形式的信号，如 "EQEP1S:Y"
                        if isinstance(signal, str) and ':' in signal:
                            signal_name = signal.split(':')[0]
                            if signal_name == function_name:
                                gpio_number = extract_gpio_number_from_pin_name(pin_name)
                                # print(f"Found {function_name} on pin {pin_name}, GPIO number: {gpio_number}")
                                if gpio_number:
                                    return gpio_number
                        # 处理直接匹配的字符串，如 "EQEP1S"
                        elif isinstance(signal, str) and signal == function_name:
                            gpio_number = extract_gpio_number_from_pin_name(pin_name)
                            if gpio_number:
                                return gpio_number
                        # 处理字典形式的信号
                        elif isinstance(signal, dict) and function_name in signal:
                            gpio_number = extract_gpio_number_from_pin_name(pin_name)
                            if gpio_number:
                                return gpio_number
    except Exception as e:
        # 输出错误信息用于调试
        print(f"Error accessing chip database for {function_name}: {e}")
        pass
    
    # 如果没有找到，返回默认值
    # print(f"Could not find GPIO number for {function_name}, returning {default}")
    return default


def extract_gpio_number_from_pin_name(pin_name: str) -> str | None:
    if pin_name.startswith("GPIO"):
        gpio_part = pin_name[4:]
        if gpio_part.isdigit():
            return gpio_part
    return None


def pin_position(
    project: Project,
    channel: str,
    default: int = 0,
) -> int:
    return project.configs.get(f"pins.{channel}.position", default)


# fmt: on
# endregion
# ------------------------------------------------------------------------------


# --< user code begin code, do not change this comment!
def __hash_dict(dictionary) -> int:
    json_str = json.dumps(dictionary, sort_keys=True)
    return hash(json_str)


def gpio_used_channels(project: Project) -> list[str]:
    pins = []
    channels = gpio_channels(project)
    for channel in channels:
        locked = pin_locked(project, channel)
        function = pin_function(project, channel)
        mode = pin_mode(project, channel)

        if (
            locked  # locked == True
            and len(function) != 0  # function != ""
            and not channel.startswith("RCM-")  # name startswith "RCM-"
            and len(mode) == 0  # mode == ""
        ):
            pins.append(channel)

    pins.sort()
    return pins


def gpio_used_clocks(project: Project) -> list[str]:
    clocks = []

    channels = gpio_used_channels(project)
    for channel in channels:
        clocks.append(f"RCM_APB2_PERIPH_GPIO{str(channel[1]).upper()}")
        function = pin_function(project, channel)
        if function == "GPIO:EXTI":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")
        elif function == "GPIO:EVENTOUT":
            clocks.append(f"RCM_APB2_PERIPH_AFIO")

    clocks = list(set(clocks))
    clocks.sort()

    return clocks


def gpio_clocks_to_alias(clocks: list[str]) -> list[str]:
    names = []

    for clock in clocks:
        names.append(clock.replace("RCM_APB2_PERIPH_", ""))

    names.sort()

    return names


def gpio_channel_to_clock(channel: str) -> str:
    return f"RCM_APB2_PERIPH_GPIO{str(channel[1]).upper()}"


def gpio_channel_to_port(channel: str) -> str:
    return f"GPIO{str(channel[1]).upper()}"


def gpio_channel_to_port_source(channel: str) -> str:
    return f"GPIO_PORT_SOURCE_{str(channel[1]).upper()}"


def gpio_channel_to_pin(channel: str) -> str:
    return f"GPIO_PIN_{channel[2:]}"


def gpio_channel_to_pin_source(channel: str) -> str:
    return f"GPIO_PIN_SOURCE_{channel[2:]}"


def gpio_channel_to_eint_line(channel: str) -> str:
    return f"EINT_LINE_{channel[2:]}"


def gpio_channels_to_pins(channels: list[str]) -> list[str]:
    pins = []

    for channel in channels:
        pins.append(gpio_channel_to_pin(channel))

    pins.sort()

    return pins


def gpio_used_ports(channels: list[str]) -> list[str]:
    ports = []

    for channel in channels:
        ports.append(gpio_channel_to_port(channel))

    ports = list(set(ports))
    ports.sort()

    return ports


def gpio_channels_group_by_port(
    project: Project, channels: list[str], port: str
) -> list[list[str]]:
    channels_group_map: dict[str, list[str]] = {}
    channels_group = []
    for channel in channels:
        config = {}
        if port[4] == channel[1]:
            config["function"] = pin_function(project, channel)
            config["gpio_mode_t"] = gpio_mode_t(project, channel)
            config["gpio_pull_t"] = gpio_pull_t(project, channel)
            config["gpio_speed_t"] = gpio_speed_t(project, channel)

            # group according to different configurations, pins with the same configuration are in the same group
            hash_str = __hash_dict(config)
            if not hash_str in channels_group_map:
                channels_group_map[hash_str] = [channel]
            else:
                channels_group_map[hash_str].append(channel)

    for _, value in channels_group_map.items():
        group = list(set(value))
        group.sort()
        channels_group.append(group)

    channels_group.sort()

    return channels_group


def gpio_channel_alias(project: Project, channel: str) -> str:
    return pin_label(project, channel)


def gpio_channel_state(project: Project, channel: str) -> str | None:
    state_map = {
        "reset": "BIT_RESET",
        "set": "BIT_SET",
    }

    state = gpio_state_t(project, channel)

    return state_map[state]


def gpio_channels_classify_by_state(
    project: Project, channels: list
) -> dict[str, list[str]]:
    if not gpio_channel_state(project, channels[0]):
        return {}  # 代表这组通道并非输出类型的
    state_groups_map: dict[str, list[str]] = {}

    for channel in channels:
        state = gpio_channel_state(project, channel)
        if not state in state_groups_map:
            state_groups_map[state] = [channel]
        else:
            state_groups_map[state].append(channel)

    for level_groups in state_groups_map.keys():
        state_groups_map[level_groups].sort()

    return state_groups_map


def gpio_channel_mode(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    pull = gpio_pull_t(project, channel)

    result = ""

    if mode in [
        "input",
        "it_rising",
        "it_falling",
        "it_rising_falling",
        "evt_rising",
        "evt_falling",
        "evt_rising_falling",
    ]:
        if pull == "nopull":
            result = "GPIO_MODE_IN_FLOATING"
        elif pull == "pullup":
            result = "GPIO_MODE_IN_PU"
        elif pull == "pulldown":
            result = "GPIO_MODE_IN_PD"
    elif mode == "output_pp":
        result = "GPIO_MODE_OUT_PP"
    elif mode == "output_od":
        result = "GPIO_MODE_OUT_OD"
    elif mode == "af_pp":
        result = "GPIO_MODE_AF_PP"
    elif mode == "af_od":
        result = "GPIO_MODE_AF_OD"
    elif mode == "analog":
        result = "GPIO_MODE_ANALOG"

    assert result != "", f"failed to get gpio mode, {mode!r}, {pull!r}"

    return result


def gpio_channel_speed(project: Project, channel: str) -> str:
    speed_map = {
        "low": "GPIO_SPEED_2MHz",
        "medium": "GPIO_SPEED_10MHz",
        "high": "GPIO_SPEED_50MHz",
    }

    speed = gpio_speed_t(project, channel, default="")
    if speed == "":
        return ""

    return speed_map[speed]


def gpio_channel_eint_mode(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    result = ""

    if mode in [
        "it_rising",
        "it_falling",
        "it_rising_falling",
    ]:
        result = "EINT_MODE_INTERRUPT"
    elif mode in [
        "evt_rising",
        "evt_falling",
        "evt_rising_falling",
    ]:
        result = "EINT_MODE_EVENT"

    assert result != "", f"failed to get gpio eint mode, {mode!r}"

    return result


def gpio_channel_eint_trigger(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    result = ""

    if mode in [
        "it_rising",
        "evt_rising",
    ]:
        result = "EINT_TRIGGER_RISING"
    elif mode in [
        "it_falling",
        "evt_falling",
    ]:
        result = "EINT_TRIGGER_FALLING"
    elif mode in [
        "it_rising_falling",
        "evt_rising_falling",
    ]:
        result = "EINT_TRIGGER_RISING_FALLING"

    assert result != "", f"failed to get gpio eint trigger, {mode!r}"

    return result


def gpio_channel_direction(project: Project, channel: str) -> str:
    mode = gpio_mode_t(project, channel)
    return "GPIO_DIR_MODE_OUT" if mode == "output" else "GPIO_DIR_MODE_IN"


def gpio_channel_pad_config(project: Project, channel: str) -> str:
    return gpio_pad_config(project, channel)


def gpio_channel_qualification_mode(project: Project, channel: str) -> str:
    return gpio_qualification_mode(project, channel)



def gpio_eventout_channels(project: Project, channels: list[str]) -> list[str]:
    result = []

    for channel in channels:
        function = pin_function(project, channel)
        if function == "GPIO:EVENTOUT":
            result.append(channel)

    return result


def gpio_eint_channels(project: Project, channels: list[str]) -> list[str]:
    result = []

    for channel in channels:
        function = pin_function(project, channel)
        if function.startswith("GPIO:EINT"):
            result.append(channel)

    return result


# --> user code end code, do not change this comment!
