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
            this->reset_pin_->setup();
            this->reset_pin_->digital_write(false);

            ESP_LOGCONFIG(TAG, "Setup completed!");
        }

        void NixieClockComponent::loop() {
        }

        void NixieClockComponent::updateTime(esphome::time::ESPTime time) {
            send_8_bits(time.second);
            send_8_bits(time.minute);
            send_8_bits(time.hour);

            // pulse latch to activate new values
            this->latch_pin_->digital_write(true);
            this->latch_pin_->digital_write(false);
        }

        void NixieClockComponent::send_8_bits(int value) {
            for (int i = 7; i >= 0; i--) {
                bool b = (value >> i)  & 1;
                this->data_pin_->digital_write(b);
                this->clock_pin_->digital_write(true);
                this->clock_pin_->digital_write(false);
            }
        }

    }
}