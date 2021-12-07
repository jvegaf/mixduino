
#ifndef MD_PINMAP_H
#define MD_PINMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// BUTTONS
static const uint8_t SWFXR_2      = 4;
static const uint8_t SWFXR_3      = 5;
static const uint8_t SWFXL_1      = 8;
static const uint8_t SW_BROWSER_R = 7;
static const uint8_t SW_BROWSER_L = 10;
static const uint8_t SWFXL_2      = 9;
static const uint8_t SWFXL_3      = 11;
static const uint8_t SWFXR_1      = 12;
static const uint8_t SWBR_PREVIEW = 14;
static const uint8_t SWBR_BACK    = 15;

static const uint8_t FX_SW_BUNDLE[] = {
    SWFXL_1,
    SWFXL_2,
    SWFXL_3,
    SWFXR_1,
    SWFXR_2,
    SWFXR_3
};

static const uint8_t T_FX_SW    = 6;

static const uint8_t L_BROWSER_A = 2;
static const uint8_t L_BROWSER_B = 3;
static const uint8_t NP_DATA     = 6;
static const uint8_t L1VU_LATCH  = 16;
static const uint8_t L1VU_SIG    = 17;
static const uint8_t R_BROWSER_B = 18;
static const uint8_t R_BROWSER_A = 19;
static const uint8_t MRVU_LATCH  = 26;
static const uint8_t MRVU_SIG    = 28;
static const uint8_t MLVU_LATCH  = 30;
static const uint8_t L2VU_SIG    = 31;
static const uint8_t MLVU_SIG    = 32;
static const uint8_t L3VU_SIG    = 34;
static const uint8_t L3VU_LATCH  = 36;
static const uint8_t FBL_LATCH   = 37;
static const uint8_t L2VU_LATCH  = 38;
static const uint8_t FBL_SIG     = 39;
static const uint8_t FBR_LATCH   = 42;
static const uint8_t FBR_SIG     = 44;
static const uint8_t SRCLK       = 52;

//////////////////////////////////////
// MULTIPLEXER

static const uint8_t MPLEX_S0          = 47;
static const uint8_t MPLEX_S1          = 49;
static const uint8_t MPLEX_S2          = 40;
static const uint8_t MPLEX_S3          = 53;
static const uint8_t TOP_POTMUX_SIG    = A1;
static const uint8_t RIGHT_SWMUX_SIG   = A2;
static const uint8_t LEFT_SWMUX_SIG    = A3;
static const uint8_t BOTTOM_POTMUX_SIG = A4;

static const uint8_t MUXPIN_BUNDLE[] = {
    MPLEX_S0,
    MPLEX_S1,
    MPLEX_S2,
    MPLEX_S3
};

static const uint8_t T_MUXPIN_BUNDLE = 4;


static const uint8_t ARD_SW_BUNDLE[] = {
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

static const uint8_t T_ARD_SW_BUNDLE = 12;

//////////////////////////////////////
// POTS ANALOG PINS

static const uint8_t PFXR_1  = A0;
static const uint8_t PMASTER = A14;

static const uint8_t ARD_POTS_BUNDLE[] = {
    PFXR_1,
    PMASTER};

static const uint8_t T_ARD_POTS = 2;

#endif
