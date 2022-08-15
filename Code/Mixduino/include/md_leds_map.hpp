#pragma once

#include <Arduino.h>
#include <Shifter.h>
#include "md_led.hpp"
#include "pin_map.h"


Shifter shftRgt(FBR_SIG, FBR_LATCH, SRCLK, 1);
Shifter shftLft(FBL_SIG, FBL_LATCH, SRCLK, 1);

MDLed_t leds_group[] = {MDLed_t(&shftLft, 0), MDLed_t(&shftLft, 1), MDLed_t(&shftLft, 2), MDLed_t(&shftLft, 3),
                                MDLed_t(&shftLft, 4), MDLed_t(&shftLft, 5), MDLed_t(&shftLft, 6), MDLed_t(&shftLft, 7),
                                MDLed_t(&shftRgt, 0), MDLed_t(&shftRgt, 1), MDLed_t(&shftRgt, 2), MDLed_t(&shftRgt, 3),
                                MDLed_t(&shftRgt, 4), MDLed_t(&shftRgt, 5), MDLed_t(&shftRgt, 6)};
