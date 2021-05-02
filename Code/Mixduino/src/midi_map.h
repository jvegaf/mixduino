
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>
#include "sr_map.h"

#pragma once


/////////////////////////////////////////
// OUTS

const uint8_t MASTER_OUT_L = 10;
const uint8_t MASTER_OUT_R = 11;
const uint8_t LEVEL_DECK_A = 12;
const uint8_t LEVEL_DECK_B = 13;
const uint8_t LEVEL_DECK_C = 14;

const uint8_t MONITOR_CUE_A = 49;
const uint8_t MONITOR_CUE_B = 50;
const uint8_t MONITOR_CUE_C = 51;

const uint8_t FX1_BTN_1 = 42;
const uint8_t FX1_BTN_2 = 43;
const uint8_t FX1_BTN_3 = 44;
const uint8_t FX2_BTN_1 = 45;
const uint8_t FX2_BTN_2 = 46;
const uint8_t FX2_BTN_3 = 47;

const uint8_t PLAY_DECK_A = 48;
const uint8_t PLAY_DECK_B = 49; // & DECK_C

const uint8_t CUE_DECK_A = 50;
const uint8_t CUE_DECK_B = 51; // & DECK_C




#endif
