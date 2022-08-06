#ifndef __MD_LEDS_MAP_HPP__
#define __MD_LEDS_MAP_HPP__

#include <Arduino.h>
#include <Shifter.h>
#include "md_led.hpp"
#include "pin_map.h"

Shifter* shftRgt = new Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1);
Shifter* shftLft = new Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1);

const uint8_t t_leds = 15;

const MDLed_t fx3_l  (shftLft, 0);
const MDLed_t fx2_l  (shftLft, 1);
const MDLed_t fx1_l  (shftLft, 2);
const MDLed_t play_l (shftLft, 3);
const MDLed_t cue_l  (shftLft, 4);
const MDLed_t loop_l (shftLft, 5);
const MDLed_t cue_b  (shftLft, 6);
const MDLed_t cue_a  (shftLft, 7);
const MDLed_t cue_c  (shftRgt, 0);
const MDLed_t cue_r  (shftRgt, 1);
const MDLed_t play_r (shftRgt, 2);
const MDLed_t loop_r (shftRgt, 3);
const MDLed_t fx3_r  (shftRgt, 4);
const MDLed_t fx2_r  (shftRgt, 5);
const MDLed_t fx1_r  (shftRgt, 6);


#endif // __MD_LEDS_MAP_HPP__
