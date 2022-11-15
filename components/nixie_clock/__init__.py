import esphome.codegen as cg
import esphome.config_validation as cv
from esphome import pins
from esphome.const import (
    CONF_ID,
)

nixie_clock_component_ns = cg.esphome_ns.namespace('nixie')

NixieClockComponent = nixie_clock_component_ns.class_('NixieClockComponent', cg.Component)

CONF_CLOCK_PIN = "clock_pin"
CONF_DATA_PIN = "data_pin"
CONF_LATCH_PIN = "latch_pin"
CONF_OE_PIN = "oe_pin"
CONF_RESET_PIN = "reset_pin"

CONFIG_SCHEMA = cv.Schema(
    {
        cv.GenerateID(): cv.declare_id(NixieClockComponent),
        cv.Required(CONF_CLOCK_PIN): pins.gpio_output_pin_schema,
        cv.Required(CONF_DATA_PIN): pins.gpio_output_pin_schema,
        cv.Required(CONF_LATCH_PIN): pins.gpio_output_pin_schema,
        cv.Required(CONF_OE_PIN): pins.gpio_output_pin_schema,
        cv.Required(CONF_RESET_PIN): pins.gpio_output_pin_schema,
    }
).extend(cv.COMPONENT_SCHEMA)


async def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    await cg.register_component(var, config)

    clock_pin = await cg.gpio_pin_expression(config[CONF_CLOCK_PIN])
    cg.add(var.set_clock_pin(clock_pin))

    data_pin = await cg.gpio_pin_expression(config[CONF_DATA_PIN])
    cg.add(var.set_clock_pin(data_pin))

    latch_pin = await cg.gpio_pin_expression(config[CONF_LATCH_PIN])
    cg.add(var.set_clock_pin(latch_pin))

    oe_pin = await cg.gpio_pin_expression(config[CONF_OE_PIN])
    cg.add(var.set_clock_pin(oe_pin))

    reset_pin = await cg.gpio_pin_expression(config[CONF_RESET_PIN])
    cg.add(var.set_clock_pin(reset_pin))

