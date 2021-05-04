
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>
#include "sr_map.h"

#pragma once


/////////////////////////////////////////
// OUTS

const byte MASTER_OUT_L        = 10;
const byte MASTER_OUT_R        = 11;
const byte LEVEL_DECK_A        = 12;
const byte LEVEL_DECK_B        = 13;
const byte LEVEL_DECK_C        = 14;

const byte MONITOR_CUE_A       = 49;
const byte MONITOR_CUE_B       = 50;
const byte MONITOR_CUE_C       = 51;

const byte FX1_BTN_1           = 42;
const byte FX1_BTN_2           = 43;
const byte FX1_BTN_3           = 44;
const byte FX2_BTN_1           = 45;
const byte FX2_BTN_2           = 46;
const byte FX2_BTN_3           = 47;

const byte PLAY_DECK_A         = 48;
const byte PLAY_DECK_B         = 49; // & DECK_C

const byte CUE_DECK_A          = 50;
const byte CUE_DECK_B          = 51; // & DECK_C

// ch 1
const byte HOTCUE_1T_DK_A      = 0; // CC0
const byte HOTCUE_2T_DK_A      = 1;
const byte HOTCUE_3T_DK_A      = 2;
const byte HOTCUE_4T_DK_A      = 3;
const byte HOTCUE_5T_DK_A      = 4;
const byte HOTCUE_6T_DK_A      = 5;
const byte HOTCUE_7T_DK_A      = 6;
const byte HOTCUE_8T_DK_A      = 7; 

const byte RANGE_SELECTOR_DK_A = 20; // G#0
const byte TEMPO_MASTER_DK_A   = 21; // A0
const byte SYNC_ON_DECK_A      = 22; // A#0

const byte HOTCUE_1T_DK_B      = 23;
const byte HOTCUE_2T_DK_B      = 24;
const byte HOTCUE_3T_DK_B      = 25;
const byte HOTCUE_4T_DK_B      = 26;
const byte HOTCUE_5T_DK_B      = 27;
const byte HOTCUE_6T_DK_B      = 28;
const byte HOTCUE_7T_DK_B      = 29;
const byte HOTCUE_8T_DK_B      = 30;


const byte HOTCUE_1T_DK_C      = 59;
const byte HOTCUE_2T_DK_C      = 60;
const byte HOTCUE_3T_DK_C      = 61;
const byte HOTCUE_4T_DK_C      = 62;
const byte HOTCUE_5T_DK_C      = 63;
const byte HOTCUE_6T_DK_C      = 64;
const byte HOTCUE_7T_DK_C      = 65;
const byte HOTCUE_8T_DK_C      = 66;


const byte RANGE_SELECTOR_DK_B = 70;
const byte SYNC_ON_DECK_B      = 71;
const byte TEMPO_MASTER_DK_B   = 72;

#endif
