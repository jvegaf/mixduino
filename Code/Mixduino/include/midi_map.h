
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////////
// CHANNELS

uint8_t const IN_ONLY_CH    = 4;
uint8_t const IN_OUT_CH     = 5;
uint8_t const LEFT_PAD_CH   = 6;
uint8_t const RIGHT_PAD_CH  = 7;
uint8_t const BR_ENCODER_CH = 8;
uint8_t const VUMETERS_CH   = 12;

/////////////////////////////////////////
// NOTES

uint8_t const SEND_MON_STATE = 38;  // d1




uint8_t const T_MIDI_SET = 18;


uint8_t const T_MIDI_BLIND_SET = 5;
// Control Changes

// channel 12

uint8_t const LEVEL_DECK_A = 0;
uint8_t const LEVEL_DECK_B = 1;
uint8_t const LEVEL_DECK_C = 2;
uint8_t const MASTER_OUT_L = 3;
uint8_t const MASTER_OUT_R = 4;

#endif
