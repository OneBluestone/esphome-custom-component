#pragma once

#include "esphome/core/component.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        class NixieClockComponent : public Component {
        public:
            NixieClockComponent(esphome::gpio::GPIOPin clock_pin,
                                esphome::gpio::GPIOPin data_pin,
                                esphome::gpio::GPIOPin latch_pin,
                                esphome::gpio::GPIOPin oe_pin,
                                esphome::gpio::GPIOPin reset_pin);
            NixieClockComponent();
            void setup() override;

            void loop() override;

            void updateTime(esphome::time::ESPTime time);

        protected:
            esphome::gpio::GPIOPin *data_pin_;
            esphome::gpio::GPIOPin *clock_pin_;
            esphome::gpio::GPIOPin *latch_pin_;
            esphome::gpio::GPIOPin *oe_pin_;
            esphome::gpio::GPIOPin *reset_pin_;
        };
    }
}