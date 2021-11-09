
#ifndef MD_PINMAP_H
#define MD_PINMAP_H
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

const uint8_t FX_SW_BUNDLE[] = {
    SWFXL_1,
    SWFXL_2,
    SWFXL_3,
    SWFXR_1,
    SWFXR_2,
    SWFXR_3
};

uint8_t const T_FX_SW    = 6;

uint8_t const L_BROWSER_A = 2;
uint8_t const L_BROWSER_B = 3;
uint8_t const NP_DATA     = 6;
uint8_t const L1VU_LATCH  = 16;
uint8_t const L1VU_SIG    = 17;
uint8_t const R_BROWSER_B = 18;
uint8_t const R_BROWSER_A = 19;
uint8_t const MRVU_LATCH  = 26;
uint8_t const MRVU_SIG    = 28;
uint8_t const MLVU_LATCH  = 30;
uint8_t const L2VU_SIG    = 31;
uint8_t const MLVU_SIG    = 32;
uint8_t const L3VU_SIG    = 34;
uint8_t const L3VU_LATCH  = 36;
uint8_t const FBL_LATCH   = 37;
uint8_t const L2VU_LATCH  = 38;
uint8_t const FBL_SIG     = 39;
uint8_t const FBR_LATCH   = 42;
uint8_t const FBR_SIG     = 44;
uint8_t const SRCLK       = 52;

//////////////////////////////////////
// MULTIPLEXER

uint8_t const MPLEX_S0          = 47;
uint8_t const MPLEX_S1          = 49;
uint8_t const MPLEX_S2          = 40;
uint8_t const MPLEX_S3          = 53;
uint8_t const TOP_POTMUX_SIG    = A1;
uint8_t const RIGHT_SWMUX_SIG   = A2;
uint8_t const LEFT_SWMUX_SIG    = A3;
uint8_t const BOTTOM_POTMUX_SIG = A4;

const uint8_t MUXPIN_BUNDLE[] = {
    MPLEX_S0,
    MPLEX_S1,
    MPLEX_S2,
    MPLEX_S3
};

uint8_t const T_MUXPIN_BUNDLE = 4;


const uint8_t ARD_SW_BUNDLE[] = {
    SW_BROWSER_L,
    SW_BROWSER_R,
    SWBR_PREVIEW,
    SWBR_BACK,
    SWFXL_1,
    SWFXL_2,
    SWFXL_3,
    SWFXR_1,
    SWFXR_2,
    SWFXR_3,
    LEFT_SWMUX_SIG,
    RIGHT_SWMUX_SIG
};

uint8_t const T_ARD_SW_BUNDLE = 12;

//////////////////////////////////////
// POTS ANALOG PINS

uint8_t const PFXR_1  = A0;
uint8_t const PMASTER = A14;

const uint8_t ARD_POTS_BUNDLE[] = {
    PFXR_1,
    PMASTER};

uint8_t const T_ARD_POTS = 2;

#endif
