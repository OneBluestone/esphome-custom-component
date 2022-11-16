#pragma once

#include "esphome/core/component.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        class NixieClockComponent : public Component {
        public:
            NixieClockComponent() = default;
            void setup() override;
            void loop() override;

            void set_data_pin(esphome::gpio::GPIOPin *pin) { data_pin_ = pin; }
            void set_clock_pin(esphome::gpio::GPIOPin *pin) { clock_pin_ = pin; }
            void set_latch_pin(esphome::gpio::GPIOPin *pin) { latch_pin_ = pin; }
            void set_oe_pin(esphome::gpio::GPIOPin *pin) { oe_pin_ = pin; }
            void set_reset_pin(esphome::gpio::GPIOPin *pin) { oe_pin_ = pin; }

            void updateTime(esphome::time::ESPTime time);

        protected:
            void send_8_bits(int value);
            esphome::gpio::GPIOPin *data_pin_;
            esphome::gpio::GPIOPin *clock_pin_;
            esphome::gpio::GPIOPin *latch_pin_;
            esphome::gpio::GPIOPin *oe_pin_;
            esphome::gpio::GPIOPin *reset_pin_;
        };
    }
}