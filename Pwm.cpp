
#include "Wire.h"

PwmRPi::PwmRPi(unsigned char channel) {
    this->channel = (channel & 0x01);
}

void PwmRPi::begin() {
    pwm.address = PWM_ADDRESS;
    Bcm2835::mapPeripheral(&pwm);
}

void PwmRPi::stop() {
    Bcm2835::unmapPeripheral(&pwm);
}

PwmRPi Pwm0(0);
PwmRPi Pwm1(1);
