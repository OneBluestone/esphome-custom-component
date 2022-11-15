#pragma once

#include "esphome/core/component.h"
#include "esphome/components/time/real_time_clock.h"

namespace esphome {
    namespace nixie {
        class NixieClockComponent : public Component {
        public:
            NixieClockComponent(GPIOPin, GPIOPin, GPIOPin, GPIOPin, GPIOPin);
            void setup() override;
            void loop() override;
            void updateTime(ESPTime);
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