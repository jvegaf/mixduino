
#ifndef ARDUINO_PINMAP_H
#define ARDUINO_PINMAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////
// IMPORTANT !!! NEED PHYSICAL CHANGE
// byte const SWPADL_5       = 0;
// byte const SWPADL_8       = 1;


//////////////////////////////////////
// LEFT PAD BUTTONS

byte const SWPADL_1       = 24;
byte const SWPADL_2       = 19;
byte const SWPADL_3       = 26;
byte const SWPADL_4       = 46;
byte const SWPADL_5       = 14;
byte const SWPADL_6       = 28;
byte const SWPADL_7       = 3;
byte const SWPADL_8       = 68; // A14


//////////////////////////////////////
// RIGHT PAD BUTTONS

byte const SWPADR_1       = 39;
byte const SWPADR_2       = 35;
byte const SWPADR_3       = 31;
byte const SWPADR_4       = 27;
byte const SWPADR_5       = 37;
byte const SWPADR_6       = 33;
byte const SWPADR_7       = 29;
byte const SWPADR_8       = 25;


//////////////////////////////////////
// LEFT BUTTONS

byte const SWFXL_1           = 7;
byte const SWRANGE_L         = 16;
byte const SWSYNC_L          = 8;
byte const SWCUE_L           = 22;
byte const SWPLAY_L          = 18;

//////////////////////////////////////
// RIGHT BUTTONS

byte const SWFXR_1        = 11;
byte const SWFXR_2        = 12;
byte const SWFXR_3        = 13;
byte const SWRANGE_R      = 42;
byte const SWSYNC_R       = 44;
byte const SWCUE_R        = 15;
byte const SWPLAY_R       = 9;

//////////////////////////////////////
// I2C

// byte const SDA            = 20;
// byte const SCL            = 21;

//////////////////////////////////////
// BROWSER

byte const L_BROWSER_A        = 5;
byte const L_BROWSER_B        = 6;
byte const R_BROWSER_B      = 34;
byte const R_BROWSER_A      = 36;
byte const SWBR_PREVIEW   = 30;
byte const SWBR_BACK      = 38; //browser view
byte const SW_BROWSER_L   = 10;
byte const SW_BROWSER_R   = 32;

//////////////////////////////////////
// COMMON

byte const DECK_SEL       = 4;
byte const SWSHIFT        = 17;
byte const SWPRECUE_L1    = 45;
byte const SWPRECUE_L2    = 43;
byte const SWPRECUE_L3    = 41;

//////////////////////////////////////
// MULTIPLEXER

byte const MPLEX_S0       = 47;
byte const MPLEX_S1       = 49;
byte const MPLEX_S2       = 40;
byte const MPLEX_S3       = 53;
byte const MPLEX_A0       = A0;

//////////////////////////////////////
// SHIFT REGISTERS

byte const VU_LATCH       = 50;
byte const FB_LATCH       = 67; //A13
byte const SF_CLOCK       = 52;
byte const VU_SF_DATA     = 48;
byte const FB_SF_DATA     = 51;

//////////////////////////////////////
// NEOPIXELS DATA

byte const NP_SIG_LEFT    = 2;
byte const NP_SIG_RIGHT   = 23;

//////////////////////////////////////
// POTS ANALOG PINS

byte const GAIN_L3        = A1;
byte const GAIN_L2        = A2;
byte const GAIN_L1        = A3;
byte const PFXL_3         = A4;
byte const PFXL_2         = A5;
byte const PFXL_1         = A6;
byte const PFXR_3         = A7;
byte const PFXR_2         = A8;
byte const PFXR_1         = A9;
byte const TRE_L3         = A10;
byte const TRE_L2         = A11;
byte const TRE_L1         = A12;
byte const PMASTER        = A15;

#endif
