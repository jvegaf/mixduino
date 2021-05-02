
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>
#include "sr_map.h"

#pragma once


/////////////////////////////////////////
// OUTS

const uint8_t MASTER_OUT_L        = 10;
const uint8_t MASTER_OUT_R        = 11;
const uint8_t LEVEL_DECK_A        = 12;
const uint8_t LEVEL_DECK_B        = 13;
const uint8_t LEVEL_DECK_C        = 14;

const uint8_t MONITOR_CUE_A       = 49;
const uint8_t MONITOR_CUE_B       = 50;
const uint8_t MONITOR_CUE_C       = 51;

const uint8_t FX1_BTN_1           = 42;
const uint8_t FX1_BTN_2           = 43;
const uint8_t FX1_BTN_3           = 44;
const uint8_t FX2_BTN_1           = 45;
const uint8_t FX2_BTN_2           = 46;
const uint8_t FX2_BTN_3           = 47;

const uint8_t PLAY_DECK_A         = 48;
const uint8_t PLAY_DECK_B         = 49; // & DECK_C

const uint8_t CUE_DECK_A          = 50;
const uint8_t CUE_DECK_B          = 51; // & DECK_C

// ch 1
const uint8_t HOTCUE_1T_DK_A      = 43;
const uint8_t HOTCUE_2T_DK_A      = 44;
const uint8_t HOTCUE_3T_DK_A      = 45;
const uint8_t HOTCUE_4T_DK_A      = 46;
const uint8_t HOTCUE_5T_DK_A      = 47;
const uint8_t HOTCUE_6T_DK_A      = 48;
const uint8_t HOTCUE_7T_DK_A      = 49;
const uint8_t HOTCUE_8T_DK_A      = 50;

const uint8_t HOTCUE_1T_DK_B      = 51;
const uint8_t HOTCUE_2T_DK_B      = 52;
const uint8_t HOTCUE_3T_DK_B      = 53;
const uint8_t HOTCUE_4T_DK_B      = 54;
const uint8_t HOTCUE_5T_DK_B      = 55;
const uint8_t HOTCUE_6T_DK_B      = 56;
const uint8_t HOTCUE_7T_DK_B      = 57;
const uint8_t HOTCUE_8T_DK_B      = 58;

const uint8_t HOTCUE_1T_DK_C      = 59;
const uint8_t HOTCUE_2T_DK_C      = 60;
const uint8_t HOTCUE_3T_DK_C      = 61;
const uint8_t HOTCUE_4T_DK_C      = 62;
const uint8_t HOTCUE_5T_DK_C      = 63;
const uint8_t HOTCUE_6T_DK_C      = 64;
const uint8_t HOTCUE_7T_DK_C      = 65;
const uint8_t HOTCUE_8T_DK_C      = 66;

const uint8_t RANGE_SELECTOR_DK_A = 67;
const uint8_t TEMPO_MASTER_DK_A   = 68;
const uint8_t SYNC_ON_DECK_A      = 69;

const uint8_t RANGE_SELECTOR_DK_B = 70;
const uint8_t SYNC_ON_DECK_B      = 71;
const uint8_t TEMPO_MASTER_DK_B   = 72;

#endif
