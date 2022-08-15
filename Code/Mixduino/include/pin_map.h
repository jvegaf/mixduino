#pragma once

#include <Arduino.h>


//////////////////////////////////////
// BUTTONS
const uint8_t SWFXR_2 = 4;
const uint8_t SWFXR_3 = 5;
const uint8_t SWFXL_1 = 8;
const uint8_t SW_BROWSER_R = 7;
const uint8_t SW_BROWSER_L = 10;
const uint8_t SWFXL_2 = 9;
const uint8_t SWFXL_3 = 11;
const uint8_t SWFXR_1 = 12;
const uint8_t SWBR_PREVIEW = 14;
const uint8_t SWBR_BACK = 15;

const uint8_t ard_sw_pins[] = {
    SWFXL_3,
    SWFXL_2,
    SWFXL_1,
    SWFXR_3,
    SWFXR_2,
    SWFXR_1,
    SW_BROWSER_R,
    SW_BROWSER_L,
    SWBR_BACK,
    SWBR_PREVIEW
};

const uint8_t t_ard_sw = 10;

const uint8_t L_BROWSER_A = 2;
const uint8_t L_BROWSER_B = 3;
const uint8_t NP_DATA = 6;
const uint8_t L1VU_LATCH = 16;
const uint8_t L1VU_SIG = 17;
const uint8_t R_BROWSER_B = 18;
const uint8_t R_BROWSER_A = 19;
const uint8_t MRVU_LATCH = 26;
const uint8_t MRVU_SIG = 28;
const uint8_t MLVU_LATCH = 30;
const uint8_t L2VU_SIG = 31;
const uint8_t MLVU_SIG = 32;
const uint8_t L3VU_SIG = 34;
const uint8_t L3VU_LATCH = 36;
const uint8_t FBL_LATCH = 37;
const uint8_t L2VU_LATCH = 38;
const uint8_t FBL_SIG = 39;
const uint8_t FBR_LATCH = 42;
const uint8_t FBR_SIG = 44;
const uint8_t SRCLK = 52;

//////////////////////////////////////
// MULTIPLEXER

const uint8_t MPLEX_S0 = 47;
const uint8_t MPLEX_S1 = 49;
const uint8_t MPLEX_S2 = 40;
const uint8_t MPLEX_S3 = 53;
const uint8_t t_pots_datapin = A1;
const uint8_t r_mux_datapin  = A2;
const uint8_t l_mux_datapin  = A3;
const uint8_t b_pots_datapin = A4;

//////////////////////////////////////
// POTS ANALOG PINS

const uint8_t PFXR_1 = A0;
const uint8_t PMASTER = A14;

const uint8_t aPotsSet[] = {
    PFXR_1,
    PMASTER};

const uint8_t nAPots = 2;

const uint8_t mux_pins_arr[] = {
    MPLEX_S0,
    MPLEX_S1,
    MPLEX_S2,
    MPLEX_S3
};

const uint8_t t_muxpins = 4;


const uint8_t in_pins[] = {
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
  r_mux_datapin,
  l_mux_datapin
};



const uint8_t t_in_p = 12;
const uint8_t t_out_p = 20;

const uint8_t out_pins[] = {
    L_BROWSER_A,
    L_BROWSER_B,
    NP_DATA,
    L1VU_LATCH,
    L1VU_SIG,
    R_BROWSER_B,
    R_BROWSER_A,
    MRVU_LATCH,
    MRVU_SIG,
    MLVU_LATCH,
    L2VU_SIG,
    MLVU_SIG,
    L3VU_SIG,
    L3VU_LATCH,
    FBL_LATCH,
    L2VU_LATCH,
    FBL_SIG,
    FBR_LATCH,
    FBR_SIG,
    SRCLK
};