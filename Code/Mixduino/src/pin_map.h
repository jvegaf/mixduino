
#ifndef ARDUINO_PINMAP_H
#define ARDUINO_PINMAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////
// IMPORTANT !!! NEED PHYSICAL CHANGE
// uint8_t const SWPADL_5       = 0;
// uint8_t const SWPADL_8       = 1;


//////////////////////////////////////
// LEFT PAD BUTTONS

uint8_t const SWPADL_1       = 24;
uint8_t const SWPADL_2       = 19;
uint8_t const SWPADL_3       = 26;
uint8_t const SWPADL_4       = 46;
uint8_t const SWPADL_5       = 14;
uint8_t const SWPADL_6       = 28;
uint8_t const SWPADL_7       = 3;
uint8_t const SWPADL_8       = 68; // A14


//////////////////////////////////////
// RIGHT PAD BUTTONS

uint8_t const SWPADR_1       = 39;
uint8_t const SWPADR_2       = 35;
uint8_t const SWPADR_3       = 31;
uint8_t const SWPADR_4       = 27;
uint8_t const SWPADR_5       = 37;
uint8_t const SWPADR_6       = 33;
uint8_t const SWPADR_7       = 29;
uint8_t const SWPADR_8       = 25;


//////////////////////////////////////
// LEFT BUTTONS

uint8_t const SWFXL_1        = 7;
uint8_t const SWFXL_2        = 6;
uint8_t const SWFXL_3        = 5;
uint8_t const SWRANGE_L      = 16;
uint8_t const SWSYNC_L       = 8;
uint8_t const SWCUE_L        = 22;
uint8_t const SWPLAY_L       = 18;

//////////////////////////////////////
// RIGHT BUTTONS

uint8_t const SWFXR_1        = 11;
uint8_t const SWFXR_2        = 12;
uint8_t const SWFXR_3        = 13;
uint8_t const SWRANGE_R      = 42;
uint8_t const SWSYNC_R       = 44;
uint8_t const SWCUE_R        = 15;
uint8_t const SWPLAY_R       = 9;

//////////////////////////////////////
// I2C

uint8_t const SDA            = 20;
uint8_t const SCL            = 21;

//////////////////////////////////////
// BROWSER

uint8_t const BROWSER_B      = 34;
uint8_t const BROWSER_A      = 36;
uint8_t const SWBR_PREVIEW   = 30;
uint8_t const SWBR_BACK      = 38;
uint8_t const SW_BROWSER_L   = 10;
uint8_t const SW_BROWSER_R   = 32;

//////////////////////////////////////
// COMMON

uint8_t const DECK_SEL       = 4;
uint8_t const SWSHIFT        = 17;
uint8_t const SWPRECUE_L1    = 45;
uint8_t const SWPRECUE_L2    = 43;
uint8_t const SWPRECUE_L3    = 41;

//////////////////////////////////////
// MULTIPLEXER

uint8_t const MPLEX_S0       = 47;
uint8_t const MPLEX_S1       = 49;
uint8_t const MPLEX_S2       = 40;
uint8_t const MPLEX_S3       = 53;
uint8_t const MPLEX_A0       = A0;

//////////////////////////////////////
// SHIFT REGISTERS

uint8_t const VU_LATCH       = 50;
uint8_t const FB_LATCH       = 67; //A13
uint8_t const SF_CLOCK       = 52;
uint8_t const VU_SF_DATA     = 48;
uint8_t const FB_SF_DATA     = 51;

//////////////////////////////////////
// NEOPIXELS DATA

uint8_t const NP_SIG_LEFT    = 2;
uint8_t const NP_SIG_RIGHT   = 23;

//////////////////////////////////////
// POTS ANALOG PINS

uint8_t const GAIN_L3        = A1;
uint8_t const GAIN_L2        = A2;
uint8_t const GAIN_L1        = A3;
uint8_t const PFXL_3         = A4;
uint8_t const PFXL_2         = A5;
uint8_t const PFXL_1         = A6;
uint8_t const PFXR_3         = A7;
uint8_t const PFXR_2         = A8;
uint8_t const PFXR_1         = A9;
uint8_t const TRE_L3         = A10;
uint8_t const TRE_L2         = A11;
uint8_t const TRE_L1         = A12;
uint8_t const PMASTER        = A15;

#endif
