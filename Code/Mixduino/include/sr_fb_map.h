
#ifndef ARDUINO_SR_FB_MAP_H
#define ARDUINO_SR_FB_MAP_H
#include <Arduino.h>

#pragma once

////////////////////////////////////
// FB RIGHT

const byte PCUEL3 = 0;
const byte CUE_R  = 1;
const byte PLAY_R = 2;
const byte LOOP_R = 3;
const byte FX3_R  = 4;
const byte FX2_R  = 5;
const byte FX1_R  = 6;

const byte fbRightSet[] = {
    PCUEL3,
    CUE_R,
    PLAY_R,
    LOOP_R,
    FX3_R,
    FX2_R,
    FX1_R
};

////////////////////////////////////
// FB LEFT
const byte FX3_L  = 0;
const byte FX2_L  = 1;
const byte FX1_L  = 2;
const byte PLAY_L = 3;
const byte CUE_L  = 4;
const byte LOOP_L = 5;
const byte PCUEL2 = 6;
const byte PCUEL1 = 7;

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

#endif
