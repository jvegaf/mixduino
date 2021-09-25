
#ifndef ARDUINO_SR_FB_MAP_H
#define ARDUINO_SR_FB_MAP_H
#include <Arduino.h>
#include "midi_map.h"

#pragma once

////////////////////////////////////
// FB RIGHT

const byte PCUEL3 = MONITOR_CUE_C;
const byte CUE_R  = CUE_DECK_B;
const byte PLAY_R = PLAY_DECK_B;
const byte LOOP_R = LOOP_DECK_B;
const byte FX3_R  = FX2_BTN_3;
const byte FX2_R  = FX2_BTN_2;
const byte FX1_R  = FX2_BTN_1;

const byte fbRightSet[] = {
    PCUEL3,
    CUE_R,
    PLAY_R,
    LOOP_R,
    FX3_R,
    FX2_R,
    FX1_R
};

const byte nFbRight = 7;

////////////////////////////////////
// FB LEFT
const byte FX3_L  = FX1_BTN_3;
const byte FX2_L  = FX1_BTN_2;
const byte FX1_L  = FX1_BTN_1;
const byte PLAY_L = PLAY_DECK_A;
const byte CUE_L  = CUE_DECK_A;
const byte LOOP_L = LOOP_DECK_A;
const byte PCUEL2 = MONITOR_CUE_B;
const byte PCUEL1 = MONITOR_CUE_A;

const byte fbLeftSet[] = {
    FX3_L,
    FX2_L,
    FX1_L,
    PLAY_L,
    CUE_L,
    LOOP_L,
    PCUEL2,
    PCUEL1
};

const byte nFbLeft = 8;

#endif
