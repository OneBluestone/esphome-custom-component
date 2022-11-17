#include "esphome/core/log.h"
#include "nixie.h"

namespace esphome {
    namespace nixie {
        static const char *TAG = "nixie_clock.nixie";

        void NixieClockComponent::setup() {
            ESP_LOGCONFIG(TAG, "Setup!");
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
        }

        void NixieClockComponent::updateTime(esphome::time::ESPTime time) {
            ESP_LOGCONFIG(TAG, "UpdateTime!");
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
                ESP_LOGCONFIG(TAG, b ? "1" : "0");

                this->data_pin_->digital_write(b);
                this->clock_pin_->digital_write(true);
                this->clock_pin_->digital_write(false);
            }
            ESP_LOGCONFIG(TAG, "+");
        }

    }
}