
#ifndef ARDUINO_PINMAP_H
#define ARDUINO_PINMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// BUTTONS
byte const SWFXR_2 = 4;
byte const SWFXR_3 = 5;
byte const SWFXL_1 = 8;
byte const SW_BROWSER_R = 7;
byte const SW_BROWSER_L = 10;
byte const SWFXL_2 = 9;
byte const SWFXL_3 = 11;
byte const SWFXR_1 = 12;
byte const SWBR_PREVIEW = 14;
byte const SWBR_BACK = 15;

const byte aSwSet[] = {
    SWFXR_2,
    SWFXR_3,
    SWFXL_1,
    SW_BROWSER_R,
    SW_BROWSER_L,
    SWFXL_2,
    SWFXL_3,
    SWFXR_1,
    SWBR_PREVIEW,
    SWBR_BACK
};

const byte nASw = 10;

byte const L_BROWSER_A = 2;
byte const L_BROWSER_B = 3;
byte const NP_DATA = 6;
byte const L1VU_LATCH = 16;
byte const L1VU_SIG = 17;
byte const R_BROWSER_B = 18;
byte const R_BROWSER_A = 19;
byte const MRVU_LATCH = 26;
byte const MRVU_SIG = 28;
byte const MLVU_LATCH = 30;
byte const L2VU_SIG = 31;
byte const MLVU_SIG = 32;
byte const L3VU_SIG = 34;
byte const L3VU_LATCH = 36;
byte const FBL_LATCH = 37;
byte const L2VU_LATCH = 38;
byte const FBL_SIG = 39;
byte const FBR_LATCH = 42;
byte const FBR_SIG = 44;
byte const SRCLK = 52;

//////////////////////////////////////
// MULTIPLEXER

byte const MPLEX_S0 = 47;
byte const MPLEX_S1 = 49;
byte const MPLEX_S2 = 40;
byte const MPLEX_S3 = 53;
byte const MPLEX_A1 = A1;
byte const MPLEX_A2 = A2;
byte const MPLEX_A3 = A3;
byte const MPLEX_A4 = A4;

//////////////////////////////////////
// POTS ANALOG PINS

byte const PFXR_1 = A0;
byte const PMASTER = A14;

const byte aPotsSet[] = {
    PFXR_1,
    PMASTER};

const byte nAPots = 2;

#endif
