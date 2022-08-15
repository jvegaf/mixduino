#pragma once

#include <Arduino.h>

// PAD MODES
/**
 *  hotcues
 *  loop size selector .5 1 2 4 5 16 32 off
 *  beatjump -.5 -1 -4 -16 .5 1 4 16
 *  range selector 8 10 20 100 tempbend down up
 *  
 * channels 5 6 7
 * 
 * INPUTS
 * Channel 2 buttons (inputs)
 * channel 3 leds (ouputs)
 */

// Shared constants

const uint8_t t_pads      = 8;
const uint8_t t_deck_comp = 4;
const uint8_t t_leds      = 15;


enum class Location {
  Left,
  Right
};

// Elements



 
