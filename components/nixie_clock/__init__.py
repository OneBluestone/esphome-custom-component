import esphome.codegen as cg
import esphome.config_validation as cv
from esphome.const import CONF_ID

nixie_clock_component_ns = cg.esphome_ns.namespace('nixie')
NixieClockComponent = nixie_clock_component_ns.class_('NixieClockComponent', cg.Component)

CONFIG_SCHEMA = cv.Schema({
    cv.GenerateID(): cv.declare_id(NixieClockComponent)
}).extend(cv.COMPONENT_SCHEMA)


def to_code(config):
    var = cg.new_Pvariable(config[CONF_ID])
    yield cg.register_component(var, config)
