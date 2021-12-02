#pragma once

#include <Arduino.h>


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

const uint8_t aSwSet[] = {
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

const uint8_t nASw = 10;

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

static const uint8_t MPLEX_S0         = 47;
static const uint8_t MPLEX_S1         = 49;
static const uint8_t MPLEX_S2         = 40;
static const uint8_t MPLEX_S3         = 53;
static const uint8_t S_TOP_MUXPOTS    = A1;
static const uint8_t S_RIGH_BTNS      = A2;
static const uint8_t S_LEFT_BTNS      = A3;
static const uint8_t S_BOTTOM_MUXPOTS = A4;

static const uint8_t kMuxPinsBndl[] = {
  MPLEX_S0,
  MPLEX_S1,
  MPLEX_S2,
  MPLEX_S3
};

static const uint8_t ktMuxPinsBndl = 4;


static const uint8_t kBtnInputPinsBndl[] = {
  S_LEFT_BTNS,
  S_RIGH_BTNS,
  SWFXR_2,
  SWFXR_3,
  SWFXL_1,
  SW_BROWSER_R,
  SW_BROWSER_L,
  SWFXL_2,
  SWFXL_3,
  SWFXR_1,
  SWBR_PREVIEW,
  SWBR_BACK,
  L_BROWSER_A,
  L_BROWSER_B,
  R_BROWSER_A,
  R_BROWSER_B
};

static const uint8_t ktBtnInputPinsBndl = 16;

static const uint8_t kOutputPins[] = {
  MPLEX_S0,
  MPLEX_S1,
  MPLEX_S2,
  MPLEX_S3,
  SRCLK,
  L1VU_LATCH,
  L1VU_SIG,
  L2VU_LATCH,
  L2VU_SIG,
  L3VU_LATCH,
  L3VU_SIG,
  MLVU_LATCH,
  MLVU_SIG,
  MRVU_LATCH,
  MRVU_SIG
};

static const uint8_t ktOutputPins = 15;






//////////////////////////////////////
// POTS ANALOG PINS

static const uint8_t PFXR_1  = A0;
static const uint8_t PMASTER = A14;

static const uint8_t kPotsBundle[] = {
    PFXR_1,
    PMASTER
};

static const uint8_t kTPotsBndl = 2;