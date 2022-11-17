#include "esphome/core/log.h"
#include "nixie.h"

namespace esphome {
    namespace nixie {
        static const char *TAG = "nixie_clock.nixie";

        void NixieClockComponent::setup() {
            ESP_LOGCONFIG(TAG, "Setup!");
            // initialize output pins
            ESP_LOGCONFIG(TAG, "Clock!");
            this->clock_pin_->setup();
            ESP_LOGCONFIG(TAG, "Clock Write!");
            this->clock_pin_->digital_write(false);
            ESP_LOGCONFIG(TAG, "Data!");
            this->data_pin_->setup();
            ESP_LOGCONFIG(TAG, "Data Write!");
            this->data_pin_->digital_write(false);
            ESP_LOGCONFIG(TAG, "Latch!");
            this->latch_pin_->setup();
            ESP_LOGCONFIG(TAG, "Latch Write!");
            this->latch_pin_->digital_write(false);
            ESP_LOGCONFIG(TAG, "OE!");
            this->oe_pin_->setup();
            ESP_LOGCONFIG(TAG, "OE Write!");
            this->oe_pin_->digital_write(true);
            ESP_LOGCONFIG(TAG, "Reset!");
            this->reset_pin_->setup();
            ESP_LOGCONFIG(TAG, "Reset Write!");
            this->reset_pin_->digital_write(false);

            ESP_LOGCONFIG(TAG, "Setup Done!");
        }

        void NixieClockComponent::loop() {
            ESP_LOGCONFIG(TAG, "Loop!");
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
                this->data_pin_->digital_write(b);
                this->clock_pin_->digital_write(true);
                this->clock_pin_->digital_write(false);
            }
        }

    }
}