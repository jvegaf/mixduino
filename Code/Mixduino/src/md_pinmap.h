
#ifndef ARDUINO_MD_PINMAP_H
#define ARDUINO_MD_PINMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// BUTTONS
uint8_t const SWFXR_2      = 4;
uint8_t const SWFXR_3      = 5;
uint8_t const SWFXL_1      = 8;
uint8_t const SW_BROWSER_R = 7;
uint8_t const SW_BROWSER_L = 10;
uint8_t const SWFXL_2      = 9;
uint8_t const SWFXL_3      = 11;
uint8_t const SWFXR_1      = 12;
uint8_t const SWBR_PREVIEW = 14;
uint8_t const SWBR_BACK    = 15;

const uint8_t aSwSet[]     = {
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

const uint8_t nASw         = 10;

uint8_t const L_BROWSER_A  = 2;
uint8_t const L_BROWSER_B  = 3;
uint8_t const NP_DATA      = 6;
uint8_t const L1VU_LATCH   = 16;
uint8_t const L1VU_SIG     = 17;
uint8_t const R_BROWSER_B  = 18;
uint8_t const R_BROWSER_A  = 19;
uint8_t const MRVU_LATCH   = 26;
uint8_t const MRVU_SIG     = 28;
uint8_t const MLVU_LATCH   = 30;
uint8_t const L2VU_SIG     = 31;
uint8_t const MLVU_SIG     = 32;
uint8_t const L3VU_SIG     = 34;
uint8_t const L3VU_LATCH   = 36;
uint8_t const FBL_LATCH    = 37;
uint8_t const L2VU_LATCH   = 38;
uint8_t const FBL_SIG      = 39;
uint8_t const FBR_LATCH    = 42;
uint8_t const FBR_SIG      = 44;
uint8_t const SRCLK        = 52;

//////////////////////////////////////
// MULTIPLEXER

uint8_t const MPLEX_S0     = 47;
uint8_t const MPLEX_S1     = 49;
uint8_t const MPLEX_S2     = 40;
uint8_t const MPLEX_S3     = 53;
uint8_t const MPLEX_A1     = A1;
uint8_t const MPLEX_A2     = A2;
uint8_t const MPLEX_A3     = A3;
uint8_t const MPLEX_A4     = A4;

const uint8_t MUX_PINS[]    = {
    MPLEX_S0,
    MPLEX_S1,
    MPLEX_S2,
    MPLEX_S3
};

//////////////////////////////////////
// POTS ANALOG PINS

uint8_t const PFXR_1       = A0;
uint8_t const PMASTER      = A14;

const uint8_t aPotsSet[]   = {
    PFXR_1,
    PMASTER
};

const uint8_t nAPots       = 2;

#endif
