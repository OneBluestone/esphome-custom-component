#include "esphome/core/log.h"
#include "nixie.h"
#include "esphome/components/time/real_time_clock.h"
#include "esphome/core/gpio.h"

namespace esphome {
    namespace nixie {
        static const char *TAG = "nixie_clock.nixie";
        NixieClockComponent::NixieClockComponent(esphome::gpio::GPIOPin clock_pin,
                                                 esphome::gpio::GPIOPin data_pin,
                                                 esphome::gpio::GPIOPin latch_pin,
                                                 esphome::gpio::GPIOPin oe_pin,
                                                 esphome::gpio::GPIOPin reset_pin) {
            clock_pin_ = clock_pin;
            data_pin_ = data_pin;
            latch_pin_ = latch_pin;
            oe_pin_ = oe_pin;
            reset_pin_ = reset_pin;
        }

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