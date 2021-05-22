
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>
#include "sr_map.h"

#pragma once


/////////////////////////////////////////
// OUTS

const byte MONITOR_CUE_A       = 39; // d#2
const byte MONITOR_CUE_B       = 40; // e2
const byte MONITOR_CUE_C       = 41; // f2

const byte FX1_BTN_1           = 42; // f#2
const byte FX1_BTN_2           = 43; // g2
const byte FX1_BTN_3           = 44; // g#2
const byte FX2_BTN_1           = 45; // a2
const byte FX2_BTN_2           = 46; // a#2
const byte FX2_BTN_3           = 47; // b2

const byte PLAY_DECK_A         = 48; // c3
const byte PLAY_DECK_B         = 49; // c#3     & DECK_C

const byte CUE_DECK_A          = 50; // d3
const byte CUE_DECK_B          = 51; // d#3     & DECK_C

// Control Changes

// channel 1

const byte HOTCUE_1T_DK_A      = 0; 
const byte HOTCUE_2T_DK_A      = 1;
const byte HOTCUE_3T_DK_A      = 2;
const byte HOTCUE_4T_DK_A      = 3;
const byte HOTCUE_5T_DK_A      = 4;
const byte HOTCUE_6T_DK_A      = 5;
const byte HOTCUE_7T_DK_A      = 6;
const byte HOTCUE_8T_DK_A      = 7; 

const byte RANGE_SELECTOR_DK_A = 8; 
const byte TEMPO_MASTER_DK_A   = 9; 
const byte SYNC_ON_DECK_A      = 10;

// channel 2

const byte HOTCUE_1T_DK_B      = 7;
const byte HOTCUE_2T_DK_B      = 6;
const byte HOTCUE_3T_DK_B      = 5;
const byte HOTCUE_4T_DK_B      = 4;
const byte HOTCUE_5T_DK_B      = 3;
const byte HOTCUE_6T_DK_B      = 2;
const byte HOTCUE_7T_DK_B      = 1;
const byte HOTCUE_8T_DK_B      = 0;
const byte DECK_B_C_SELECTION  = 8;
const byte RANGE_SELECTOR_DK_B = 9;
const byte SYNC_ON_DECK_B      = 10;
const byte TEMPO_MASTER_DK_B   = 11;

// channel 3 

const byte MASTER_OUT_L        = 4;
const byte MASTER_OUT_R        = 3;
const byte LEVEL_DECK_A        = 2;
const byte LEVEL_DECK_B        = 1;
const byte LEVEL_DECK_C        = 0;

#endif
