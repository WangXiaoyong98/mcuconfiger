import importlib.util
import sys
import unittest
from pathlib import Path

import jinja2

ROOT = Path(__file__).resolve().parents[4]
sys.path.insert(0, str(ROOT / "csp/server/public"))

from csp.project import Project


class PinmuxGenerationTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.hal = ROOT / "csp_hal_sp28038"
        spec = importlib.util.spec_from_file_location(
            "test_gpio_filters", cls.hal / "tools/generator/filters/gpio.py"
        )
        cls.gpio = importlib.util.module_from_spec(spec)
        spec.loader.exec_module(cls.gpio)

    def project(self, pins, gpio=None):
        return Project(
            {
                "name": "pinmux_test",
                "version": "0.1.2",
                "vendor": "StarPower",
                "targetChip": "SP28038",
                "gen": {"hal": "csp_hal_sp28038", "halVersion": "latest"},
                "configs": {"pins": pins, "GPIO": gpio or {}},
            }
        )

    def test_selected_physical_pin_is_used_for_alternate_function(self):
        project = self.project({"GPIO22": {"function": "SCI3_TX:Y"}})
        rows = self.gpio.sp28038_pin_configurations(project)
        self.assertEqual(rows[0]["macro"], "GPIO_22_SCI3_TX")
        self.assertEqual(rows[0]["pin"], 22)
        self.assertIsNone(rows[0]["direction"])

    def test_gpio_direction_pad_and_qualification_reach_generated_code(self):
        project = self.project(
            {
                "GPIO22": {"function": "GPIO:22"},
                "GPIO32": {"function": "I2C1_SDA:Y"},
            },
            {
                "GPIO22": {
                    "gpio_direction_t": "output",
                    "gpio_pin_type_t": "open_drain",
                    "gpio_qualification_mode_t": "six_sample",
                }
            },
        )
        env = jinja2.Environment(
            loader=jinja2.FileSystemLoader(
                [
                    ROOT / "csp/resources/templates",
                    self.hal / "tools/generator/templates",
                ]
            )
        )
        env.filters["sp28038_pin_configurations"] = self.gpio.sp28038_pin_configurations
        rendered = env.get_template("csp_gpio.c.j2").render(
            CSP={"project": project, "user_code": {}}
        )
        self.assertIn("GPIO_setPinConfig(GPIO_22_GPIO22);", rendered)
        self.assertIn("GPIO_setPinConfig(GPIO_32_I2C1_SDA);", rendered)
        self.assertIn("GPIO_setDirectionMode(22U, GPIO_DIR_MODE_OUT);", rendered)
        self.assertIn("GPIO_PIN_TYPE_OD", rendered)
        self.assertIn("GPIO_setQualificationMode(22U, GPIO_QUAL_6SAMPLE);", rendered)

    def test_invalid_mapping_and_duplicate_signals_are_rejected(self):
        with self.assertRaisesRegex(ValueError, "No vendor pin mapping"):
            self.gpio.sp28038_pin_configurations(
                self.project({"GPIO22": {"function": "SCI1_TX:Y"}})
            )
        with self.assertRaisesRegex(ValueError, "Signal assigned more than once"):
            self.gpio.sp28038_pin_configurations(
                self.project(
                    {
                        "GPIO22": {"function": "SCI3_TX:Y"},
                        "GPIO14": {"function": "SCI3_TX:Y"},
                    }
                )
            )

    def test_disabling_all_pad_flags_does_not_reenable_input(self):
        project = self.project(
            {"GPIO22": {"function": "GPIO:22"}},
            {"GPIO22": {"gpio_input_enable_t": "false"}},
        )
        self.assertEqual(self.gpio.sp28038_pin_configurations(project)[0]["pad"], "0U")
