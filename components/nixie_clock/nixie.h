#pragma once

#include "esphome/core/component.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        class NixieClockComponent : public Component {
        public:
            void setup() override;
            void loop() override;

            void set_data_pin(GPIOPin *pin) { data_pin_ = pin; }
            void set_clock_pin(GPIOPin *pin) { clock_pin_ = pin; }
            void set_latch_pin(GPIOPin *pin) { latch_pin_ = pin; }
            void set_oe_pin(GPIOPin *pin) { oe_pin_ = pin; }
            void set_reset_pin(GPIOPin *pin) { reset_pin_ = pin; }

            void updateTime(esphome::time::ESPTime time);

        protected:
            void send_8_bits(int value);
            GPIOPin *data_pin_;
            GPIOPin *clock_pin_;
            GPIOPin *latch_pin_;
            GPIOPin *oe_pin_;
            GPIOPin *reset_pin_;
            esphome::time::RealTimeClock *clock_;
        };
    }
}