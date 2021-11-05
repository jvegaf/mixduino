
#ifndef ARDUINO_SR_FB_MAP_H
#define ARDUINO_SR_FB_MAP_H
#include <Arduino.h>
#include "midi_map.h"

#pragma once

////////////////////////////////////
// FB RIGHT

uint8_t const PCUEL3 = 0;
uint8_t const CUE_R  = 1;
uint8_t const PLAY_R = 2;
uint8_t const LOOP_R = 3;
uint8_t const FX3_R  = 4;
uint8_t const FX2_R  = 5;
uint8_t const FX1_R  = 6;

const uint8_t FB_LED_BUNDLE_R[] = {
    PLAY_R,
    CUE_R,
    LOOP_R,
    PCUEL3
};
const uint8_t T_FB_BDL_R = 4;

const uint8_t FB_FX_BUNDLE_R[] = {
    FX3_R,
    FX2_R,
    FX1_R
};

////////////////////////////////////
// FB LEFT
uint8_t const FX3_L  = 0;
uint8_t const FX2_L  = 1;
uint8_t const FX1_L  = 2;
uint8_t const PLAY_L = 3;
uint8_t const CUE_L  = 4;
uint8_t const LOOP_L = 5;
uint8_t const PCUEL2 = 6;
uint8_t const PCUEL1 = 7;

const uint8_t FB_LED_BUNDLE_L[] = {
    PLAY_L,
    CUE_L,
    LOOP_L,
    PCUEL2,
    PCUEL1
};

const uint8_t T_FB_BDL_L = 5;

const uint8_t FB_FX_BUNDLE_L[] = {
    FX3_L,
    FX2_L,
    FX1_L
};

const uint8_t nFbLeft = 8;

#endif
