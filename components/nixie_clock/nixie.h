#pragma once

#include "esphome/core/component.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        class NixieClockComponent : public Component {
        public:
            NixieClockComponent(gpio::GPIOPin clock_pin, gpio::GPIOPin data_pin, gpio::GPIOPin latch_pin,
                                gpio::GPIOPin oe_pin, gpio::GPIOPin reset_pin);

            void setup() override;

            void loop() override;

            void updateTime(ESPTime time);

        protected:
            GPIOPin *data_pin_;
            GPIOPin *clock_pin_;
            GPIOPin *latch_pin_;
            GPIOPin *oe_pin_;
            GPIOPin *reset_pin_;
        private:
            NixieClockComponent();
        };
    }
}