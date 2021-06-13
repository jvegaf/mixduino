
#ifndef ARDUINO_SR_MAP_H
#define ARDUINO_SR_MAP_H
#include <Arduino.h>

#pragma once



////////////////////////////////////
// REGISTERS

//SETS
const byte VU_REG_SET      = 0;
const byte FB_REG_SET      = 1;


// VU
const byte VU_MASTER_RIGHT = 0;
const byte VU_MASTER_LEFT  = 1;
const byte VU_LINE_3       = 2;
const byte VU_LINE_2       = 3;
const byte VU_LINE_1       = 4;

// FB

const byte FB_RIGHT        = 0;
const byte FB_LEFT         = 1;


////////////////////////////////////
// MASTER RIGHT
const byte VUMASR_0        = 0;
const byte VUMASR_1        = 1;
const byte VUMASR_2        = 2;
const byte VUMASR_3        = 3;
const byte VUMASR_4        = 4;
const byte VUMASR_5        = 5;
const byte VUMASR_6        = 6;
const byte VUMASR_7        = 7;

////////////////////////////////////
// MASTER LEFT
const byte VUMASL_0        = 8;
const byte VUMASL_1        = 9;
const byte VUMASL_2        = 10;
const byte VUMASL_3        = 11;
const byte VUMASL_4        = 12;
const byte VUMASL_5        = 13;
const byte VUMASL_6        = 14;
const byte VUMASL_7        = 15;

////////////////////////////////////
// VUMETER LINE 1
const byte VUL1_0          = 16;
const byte VUL1_1          = 17;
const byte VUL1_2          = 18;
const byte VUL1_3          = 19;
const byte VUL1_4          = 20;
const byte VUL1_5          = 21;
const byte VUL1_6          = 22;
const byte VUL1_7          = 23;

////////////////////////////////////
// VUMETER LINE 2
const byte VUL2_0          = 24;
const byte VUL2_1          = 25;
const byte VUL2_2          = 26;
const byte VUL2_3          = 27;
const byte VUL2_4          = 28;
const byte VUL2_5          = 29;
const byte VUL2_6          = 30;
const byte VUL2_7          = 31;

////////////////////////////////////
// VUMETER LINE 3
const byte VUL3_0          = 32;
const byte VUL3_1          = 33;
const byte VUL3_2          = 34;
const byte VUL3_3          = 35;
const byte VUL3_4          = 36;
const byte VUL3_5          = 37;
const byte VUL3_6          = 38;
const byte VUL3_7          = 39;

///////////////////////////////////
// FB RIGHT
const byte HP_L3           = 0;
const byte PLAY_R          = 1;
const byte CUE_R           = 2;
const byte LOOP_R          = 3;
const byte FX3_R           = 4;
const byte FX2_R           = 5;
const byte FX1_R           = 6;

////////////////////////////////////
// FB LEFT
const byte FX3_L           = 8;
const byte FX2_L           = 9;
const byte FX1_L           = 10;
const byte PLAY_L          = 11;
const byte CUE_L           = 12;
const byte LOOP_L          = 13;
const byte HP_L1           = 14;
const byte HP_L2           = 15;


#endif



