
#ifndef ARDUINO_SR_FB_MAP_H
#define ARDUINO_SR_FB_MAP_H
#include <Arduino.h>
#include "midi_map.h"

#pragma once

////////////////////////////////////
// FB RIGHT

const uint8_t PCUEL3 = MONITOR_CUE_C;
const uint8_t CUE_R  = CUE_DECK_B;
const uint8_t PLAY_R = PLAY_DECK_B;
const uint8_t LOOP_R = LOOP_DECK_B;
const uint8_t FX3_R  = FX2_BTN_3;
const uint8_t FX2_R  = FX2_BTN_2;
const uint8_t FX1_R  = FX2_BTN_1;

const uint8_t fbRightSet[] = {
    PCUEL3,
    CUE_R,
    PLAY_R,
    LOOP_R,
    FX3_R,
    FX2_R,
    FX1_R
};

const uint8_t nFbRight = 7;

////////////////////////////////////
// FB LEFT
const uint8_t FX3_L  = FX1_BTN_3;
const uint8_t FX2_L  = FX1_BTN_2;
const uint8_t FX1_L  = FX1_BTN_1;
const uint8_t PLAY_L = PLAY_DECK_A;
const uint8_t CUE_L  = CUE_DECK_A;
const uint8_t LOOP_L = LOOP_DECK_A;
const uint8_t PCUEL2 = MONITOR_CUE_B;
const uint8_t PCUEL1 = MONITOR_CUE_A;

const uint8_t fbLeftSet[] = {
    FX3_L,
    FX2_L,
    FX1_L,
    PLAY_L,
    CUE_L,
    LOOP_L,
    PCUEL2,
    PCUEL1
};

const uint8_t nFbLeft = 8;

#endif
