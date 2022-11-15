#include "esphome/core/log.h"
#include "nixie.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        static const char *TAG = "nixie_clock.nixie";

        void NixieClockComponent::setup() {
            // initialize output pins
            this->clock_pin_->setup();
            this->clock_pin_->digital_write(false);
            this->data_pin_->setup();
            this->data_pin_->digital_write(false);
            this->latch_pin_->setup();
            this->latch_pin_->digital_write(false);
            this->oe_pin_->setup();
            this->oe_pin_->digital_write(true);
            this->reset_pin->setup();
            this->reset_pin->digital_write(false);
            ESP_LOGCONFIG(TAG, "Setup completed!");
        }

        void NixieClockComponent::loop() {
        }

        void NixieClockComponent::updateTime(esphome::time::ESPTime time) {
        }

    }
}