#pragma once

#include <Arduino.h>
#include "np_conf.h"

namespace MD
{

////////////////////////////////////
// FB RIGHT

static const uint8_t OUT_PCUEL3 = 0;
static const uint8_t OUT_CUE_R  = 1;
static const uint8_t OUT_PLAY_R = 2;
static const uint8_t OUT_LOOP_R = 3;
static const uint8_t OUT_FX3_R  = 4;
static const uint8_t OUT_FX2_R  = 5;
static const uint8_t OUT_FX1_R  = 6;




////////////////////////////////////
// FB LEFT
static const uint8_t OUT_FX3_L  = 0;
static const uint8_t OUT_FX2_L  = 1;
static const uint8_t OUT_FX1_L  = 2;
static const uint8_t OUT_PLAY_L = 3;
static const uint8_t OUT_CUE_L  = 4;
static const uint8_t OUT_LOOP_L = 5;
static const uint8_t OUT_PCUEL2 = 6;
static const uint8_t OUT_PCUEL1 = 7;

static const uint8_t playerLeftOutBndl[] = {
  OUT_PLAY_L,
  OUT_CUE_L,
  OUT_LOOP_L,
  NP_SYNC_L
};

static const uint8_t playerRightOutBndl[] = {
  OUT_PLAY_R,
  OUT_CUE_R,
  OUT_LOOP_R,
  NP_SYNC_R
};
  
} // namespace MD

