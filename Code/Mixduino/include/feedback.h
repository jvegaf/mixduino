
#ifndef ARDUINO_FEEDBACK_H
#define ARDUINO_FEEDBACK_H
#include <Arduino.h>
#include <Shifter.h>
#include "midi_map.h"
#include "md_pinmap.h"
#include <NPKit.h>

#pragma once

const Shifter FEEDBACK_LEFT(FBL_SIG, FBL_LATCH, SRCLK, 1);
const Shifter FEEDBACK_RIGHT(FBR_SIG, FBR_LATCH, SRCLK, 1);

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

const uint8_t fbLeftSet[] = {
    FX1_BTN_3,
    FX1_BTN_2,
    FX1_BTN_1,
    PLAY_DECK_A,
    CUE_DECK_A,
    LOOP_DECK_A,
    MONITOR_CUE_B,
    MONITOR_CUE_A
};

const uint8_t nFbLeft = 8;

////////////////////////////////////
// FB RIGHT

const uint8_t OUT_MONITOR_CUE_C = 0;
const uint8_t OUT_CUE_DECK_B    = 1;
const uint8_t OUT_PLAY_DECK_B   = 2;
const uint8_t OUT_LOOP_DECK_B   = 3;
const uint8_t OUT_FX2_BTN_3     = 4;
const uint8_t OUT_FX2_BTN_2     = 5;
const uint8_t OUT_FX2_BTN_1     = 6;

const uint8_t fbRightSet[] = {
    MONITOR_CUE_C,
    CUE_DECK_B,
    PLAY_DECK_B,
    LOOP_DECK_B,
    FX2_BTN_3,
    FX2_BTN_2,
    FX2_BTN_1
};

const uint8_t nFbRight = 7;

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

const uint8_t nNP = 21;

#endif
