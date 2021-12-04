
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////////
// CHANNELS

static const uint8_t FX1_CH      = 3;
static const uint8_t FX2_CH      = 4;
static const uint8_t BROWSER_CH  = 5;
static const uint8_t DECK_A_CH   = 6;
static const uint8_t DECK_B_CH   = 7;
static const uint8_t DECK_C_CH   = 8;
static const uint8_t MIXER_CH    = 10;


/////////////////////////////////////////
// INPUTS

static const uint8_t LEFT_BTNS_CH    = 5;
static const uint8_t RIGHT_BTNS_CH   = 6;
static const uint8_t ARDUINO_BTNS_CH = 7;

/////////////////////////////////////////
// OUTS

static const uint8_t MONITOR_CUE_A       = 39; // d#2
static const uint8_t MONITOR_CUE_B       = 40; // e2
static const uint8_t MONITOR_CUE_C       = 41; // f2

static const uint8_t FX1_BTN_1           = 42; // f#2
static const uint8_t FX1_BTN_2           = 43; // g2
static const uint8_t FX1_BTN_3           = 44; // g#2
static const uint8_t FX2_BTN_1           = 45; // a2
static const uint8_t FX2_BTN_2           = 46; // a#2
static const uint8_t FX2_BTN_3           = 47; // b2

static const uint8_t PLAY_DECK_A         = 48; // c3
static const uint8_t PLAY_DECK_B         = 49; // c#3     & DECK_C

static const uint8_t CUE_DECK_A          = 50; // d3
static const uint8_t CUE_DECK_B          = 51; // d#3     & DECK_C

static const uint8_t LOOP_DECK_A          = 52; // e3
static const uint8_t LOOP_DECK_B          = 53; // f3     & DECK_C




// Control Changes

// channel 1

static const uint8_t HOTCUE_1T_DK_A      = 0;
static const uint8_t HOTCUE_2T_DK_A      = 1;
static const uint8_t HOTCUE_3T_DK_A      = 2;
static const uint8_t HOTCUE_4T_DK_A      = 3;
static const uint8_t HOTCUE_5T_DK_A      = 4;
static const uint8_t HOTCUE_6T_DK_A      = 5;
static const uint8_t HOTCUE_7T_DK_A      = 6;
static const uint8_t HOTCUE_8T_DK_A      = 7;
static const uint8_t RANGE_SELECTOR_DK_A = 8;
static const uint8_t SYNC_ON_DECK_A      = 9;
static const uint8_t HOTCUE_1T_DK_B      = 10;
static const uint8_t HOTCUE_2T_DK_B      = 11;
static const uint8_t HOTCUE_3T_DK_B      = 12;
static const uint8_t HOTCUE_4T_DK_B      = 13;
static const uint8_t HOTCUE_5T_DK_B      = 14;
static const uint8_t HOTCUE_6T_DK_B      = 15;
static const uint8_t HOTCUE_7T_DK_B      = 16;
static const uint8_t HOTCUE_8T_DK_B      = 17;
static const uint8_t DECK_B_C_SELECTION  = 18;
static const uint8_t RANGE_SELECTOR_DK_B = 19;
static const uint8_t SYNC_ON_DECK_B      = 20;

// channel 3

static const uint8_t LEVEL_DECK_A        = 0;
static const uint8_t LEVEL_DECK_B        = 1;
static const uint8_t LEVEL_DECK_C        = 2;
static const uint8_t MASTER_OUT_L        = 3;
static const uint8_t MASTER_OUT_R        = 4;

#endif
