
#ifndef ARDUINO_PINMAP_H
#define ARDUINO_PINMAP_H
#include <Arduino.h>

#pragma once


//////////////////////////////////////
// RIGHT PAD BUTTONS

byte const SWPADR_1       = 39;
byte const SWPADR_2       = 35;
byte const SWPADR_3       = 31;
byte const SWPADR_4       = 25;
byte const SWPADR_5       = 37;
byte const SWPADR_6       = 33;
byte const SWPADR_7       = 29;
byte const SWPADR_8       = 27;


//////////////////////////////////////
// LEFT BUTTONS

byte const SWFXL_1        = 7;
byte const SWFXL_2        = 8;
byte const SWFXL_3        = 9;


//////////////////////////////////////
// RIGHT BUTTONS

byte const SWFXR_1        = 11;
byte const SWFXR_2        = 4;
byte const SWFXR_3        = 5;
byte const SWRANGE_R      = 42;
byte const SWSYNC_R       = 44;
byte const SWLOOP_R       = 26;
byte const SWCUE_R        = 28;
byte const SWPLAY_R       = 22;

//////////////////////////////////////
// I2C

// byte const SDA            = 20;
// byte const SCL            = 21;

//////////////////////////////////////
// BROWSER

byte const R_BROWSER_B      = 34;
byte const R_BROWSER_A      = 36;
byte const L_BROWSER_B      = 12;
byte const L_BROWSER_A      = 13;
byte const SWBR_PREVIEW   = 30;
byte const SWBR_BACK      = 38; //browser view
byte const SW_BROWSER_L   = 10;
byte const SW_BROWSER_R   = 32;

//////////////////////////////////////
// COMMON

byte const DECK_SEL       = 41;
byte const SWPRECUE_L3    = 45;

//////////////////////////////////////
// MULTIPLEXER

byte const MPLEX_S0       = 47;
byte const MPLEX_S1       = 49;
byte const MPLEX_S2       = 40;
byte const MPLEX_S3       = 53;
byte const MPLEX_A0       = A2;
byte const MPLEX_A1       = A1;

//////////////////////////////////////
// SHIFT REGISTERS

byte const VU_LATCH       = 50;
byte const FB_LATCH       = 43;
byte const SF_CLOCK       = 52;
byte const VU_SF_DATA     = 48;
byte const FB_SF_DATA     = 51;

//////////////////////////////////////
// NEOPIXELS DATA

byte const NP_L_PADS_DATA    = 2;
byte const NP_L_FB_DATA      = 3;
byte const NP_R_PADS_DATA    = 23;
byte const NP_R_FB_DATA      = 24;

//////////////////////////////////////
// POTS ANALOG PINS

byte const GAIN_L3        = A3;
byte const GAIN_L2        = A4;
byte const GAIN_L1        = A5;
byte const PFXL_3         = A6;
byte const PFXL_2         = A7;
byte const PFXL_1         = A8;
byte const PFXR_3         = A10;
byte const PFXR_2         = A9;
byte const PFXR_1         = A0;
byte const TRE_L3         = A11;
byte const TRE_L2         = A12;
byte const TRE_L1         = A13;
byte const PMASTER        = A14;

#endif
