#pragma once
#ifndef MD_FEEDBACK_H
#define MD_FEEDBACK_H
#include <Arduino.h>

const uint8_t T_DECK_PADS = 8;
const uint8_t NPK_BRIGHTNESS = 32;

////////////////////////////////////
// FB LEFT

const uint8_t OUT_FX1_BTN_3     = 0;
const uint8_t OUT_FX1_BTN_2     = 1;
const uint8_t OUT_FX1_BTN_1     = 2;
const uint8_t OUT_PLAY_DECK_A   = 3;
const uint8_t OUT_CUE_DECK_A    = 4;
const uint8_t OUT_LOOP_DECK_A   = 5;
const uint8_t OUT_MONITOR_CUE_B = 6;
const uint8_t OUT_MONITOR_CUE_A = 7;


////////////////////////////////////
// FB RIGHT

const uint8_t OUT_MONITOR_CUE_C = 0;
const uint8_t OUT_CUE_DECK_B    = 1;
const uint8_t OUT_PLAY_DECK_B   = 2;
const uint8_t OUT_LOOP_DECK_B   = 3;
const uint8_t OUT_FX2_BTN_3     = 4;
const uint8_t OUT_FX2_BTN_2     = 5;
const uint8_t OUT_FX2_BTN_1     = 6;


//////////////////////////////////////
// NEOPIXELS

uint8_t const NP_PADL1    = 0;
uint8_t const NP_PADL2    = 1;
uint8_t const NP_PADL3    = 2;
uint8_t const NP_PADL4    = 3;
uint8_t const NP_PADL5    = 4;
uint8_t const NP_PADL6    = 5;
uint8_t const NP_PADL7    = 6;
uint8_t const NP_PADL8    = 7;
uint8_t const NP_MODE_L   = 8;
uint8_t const NP_SYNC_L   = 9;
uint8_t const NP_PADR1   = 10;
uint8_t const NP_PADR2   = 11;
uint8_t const NP_PADR3   = 12;
uint8_t const NP_PADR4   = 13;
uint8_t const NP_PADR5   = 14;
uint8_t const NP_PADR6   = 15;
uint8_t const NP_PADR7   = 16;
uint8_t const NP_PADR8   = 17;
uint8_t const NP_DECK_SEL = 18;
uint8_t const NP_MODE_R   = 19;
uint8_t const NP_SYNC_R   = 20;

const uint8_t T_NPIXELS = 21;

#endif
