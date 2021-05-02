
#ifndef ARDUINO_SR_MAP_H
#define ARDUINO_SR_MAP_H
#include <Arduino.h>

#pragma once



////////////////////////////////////
// REGISTERS

//SETS
const uint8_t VU_REG_SET      = 0;
const uint8_t FB_REG_SET      = 1;


// VU
const uint8_t VU_MASTER_RIGHT = 0;
const uint8_t VU_MASTER_LEFT  = 1;
const uint8_t VU_LINE_3       = 2;
const uint8_t VU_LINE_2       = 3;
const uint8_t VU_LINE_1       = 4;

// FB

const uint8_t FB_RIGHT        = 0;
const uint8_t FB_LEFT         = 1;


////////////////////////////////////
// MASTER RIGHT
const uint8_t VUMASR_0        = 0;
const uint8_t VUMASR_1        = 1;
const uint8_t VUMASR_2        = 2;
const uint8_t VUMASR_3        = 3;
const uint8_t VUMASR_4        = 4;
const uint8_t VUMASR_5        = 5;
const uint8_t VUMASR_6        = 6;
const uint8_t VUMASR_7        = 7;

////////////////////////////////////
// MASTER LEFT
const uint8_t VUMASL_0        = 8;
const uint8_t VUMASL_1        = 9;
const uint8_t VUMASL_2        = 10;
const uint8_t VUMASL_3        = 11;
const uint8_t VUMASL_4        = 12;
const uint8_t VUMASL_5        = 13;
const uint8_t VUMASL_6        = 14;
const uint8_t VUMASL_7        = 15;

////////////////////////////////////
// VUMETER LINE 1
const uint8_t VUL1_0          = 16;
const uint8_t VUL1_1          = 17;
const uint8_t VUL1_2          = 18;
const uint8_t VUL1_3          = 19;
const uint8_t VUL1_4          = 20;
const uint8_t VUL1_5          = 21;
const uint8_t VUL1_6          = 22;
const uint8_t VUL1_7          = 23;

////////////////////////////////////
// VUMETER LINE 2
const uint8_t VUL2_0          = 24;
const uint8_t VUL2_1          = 25;
const uint8_t VUL2_2          = 26;
const uint8_t VUL2_3          = 27;
const uint8_t VUL2_4          = 28;
const uint8_t VUL2_5          = 29;
const uint8_t VUL2_6          = 30;
const uint8_t VUL2_7          = 31;

////////////////////////////////////
// VUMETER LINE 3
const uint8_t VUL3_0          = 32;
const uint8_t VUL3_1          = 33;
const uint8_t VUL3_2          = 34;
const uint8_t VUL3_3          = 35;
const uint8_t VUL3_4          = 36;
const uint8_t VUL3_5          = 37;
const uint8_t VUL3_6          = 38;
const uint8_t VUL3_7          = 39;

///////////////////////////////////
// FB RIGHT
const uint8_t HP_L3           = 1;
const uint8_t PLAY_R          = 2;
const uint8_t CUE_R           = 3;
const uint8_t FX3_R           = 4;
const uint8_t FX2_R           = 5;
const uint8_t FX1_R           = 6;

////////////////////////////////////
// FB LEFT
const uint8_t CUE_L           = 9;
const uint8_t PLAY_L          = 10;
const uint8_t FX1_R           = 11;
const uint8_t FX2_R           = 12;
const uint8_t FX3_R           = 13;
const uint8_t HP_L1           = 14;
const uint8_t HP_L2           = 15;


#endif



