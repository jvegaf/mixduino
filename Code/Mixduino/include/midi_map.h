
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once


/////////////////////////////////////////
// INPUTS

const uint8_t GENERAL_CH      = 3;
const uint8_t LEFT_BTNS_CH    = 5;
const uint8_t LEFT_PAD_CH     = 6;
const uint8_t RIGHT_BTNS_CH   = 7;
const uint8_t RIGHT_PAD_CH    = 8;
const uint8_t ARDUINO_BTNS_CH = 9;



const uint8_t SEND_MON_STATE = 48; // c2

/////////////////////////////////////////
// OUTS

// const uint8_t MONITOR_CUE_A       = 39; // d#1
// const uint8_t MONITOR_CUE_B       = 40; // e1
// const uint8_t MONITOR_CUE_C       = 41; // f1

// const uint8_t FX1_BTN_1           = 42; // f#1
// const uint8_t FX1_BTN_2           = 43; // g1
// const uint8_t FX1_BTN_3           = 44; // g#1
// const uint8_t FX2_BTN_1           = 45; // a1
// const uint8_t FX2_BTN_1           = 46; // a#1
// const uint8_t FX2_BTN_3           = 47; // b1

// const uint8_t PLAY_DECK_A         = 48; // c2
// const uint8_t PLAY_DECK_B         = 49; // c#2     & DECK_C

// const uint8_t CUE_DECK_A          = 50; // d2
// const uint8_t CUE_DECK_B          = 51; // d#2     & DECK_C

// const uint8_t LOOP_DECK_A          = 52; // e2
// const uint8_t LOOP_DECK_B          = 53; // f2     & DECK_C




// Control Changes

// channel 1

const uint8_t HOTCUE_1T_DK_A      = 0;
const uint8_t HOTCUE_2T_DK_A      = 1;
const uint8_t HOTCUE_3T_DK_A      = 2;
const uint8_t HOTCUE_4T_DK_A      = 3;
const uint8_t HOTCUE_5T_DK_A      = 4;
const uint8_t HOTCUE_6T_DK_A      = 5;
const uint8_t HOTCUE_7T_DK_A      = 6;
const uint8_t HOTCUE_8T_DK_A      = 7;
const uint8_t RANGE_SELECTOR_DK_A = 8;
const uint8_t SYNC_ON_DECK_A      = 9;
const uint8_t HOTCUE_1T_DK_B      = 10;
const uint8_t HOTCUE_2T_DK_B      = 11;
const uint8_t HOTCUE_3T_DK_B      = 12;
const uint8_t HOTCUE_4T_DK_B      = 13;
const uint8_t HOTCUE_5T_DK_B      = 14;
const uint8_t HOTCUE_6T_DK_B      = 15;
const uint8_t HOTCUE_7T_DK_B      = 16;
const uint8_t HOTCUE_8T_DK_B      = 17;
const uint8_t DECK_B_C_SELECTION  = 18;
const uint8_t RANGE_SELECTOR_DK_B = 19;
const uint8_t SYNC_ON_DECK_B      = 20;

// channel 3 

const uint8_t LEVEL_DECK_A = 0;
const uint8_t LEVEL_DECK_B = 1;
const uint8_t LEVEL_DECK_C = 2;
const uint8_t MASTER_OUT_L = 3;
const uint8_t MASTER_OUT_R = 4;

#endif
