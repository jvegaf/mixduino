#pragma once

#include <Arduino.h>


/////////////////////////////////////////
// CHANNELS

static const uint8_t kChFx1     = 3;
static const uint8_t kChFx2     = 4;
static const uint8_t kChBrowser = 5;
static const uint8_t kChDeckA   = 6;
static const uint8_t kChDeckB   = 7;
static const uint8_t kChDeckC   = 8;
static const uint8_t kChMixer   = 10;

/////////////////////////////////////////
// NOTES

static const uint8_t SEND_MON_STATE = 38;  // d1


static const uint8_t kPlayNum = 0;
static const uint8_t kCueNum  = 1;
static const uint8_t kLoopNum = 2;
static const uint8_t kSyncNum = 3;
static const uint8_t kTmpoNum = 4;

static const uint8_t kPlayerMidi[] = {
  kPlayNum,
  kCueNum,
  kLoopNum,
  kSyncNum,
  kTmpoNum
};

static const uint8_t kTPlayerMidi = 5;

static const uint8_t kPad1Num = 8;
static const uint8_t kPad2Num = 9;
static const uint8_t kPad3Num = 10;
static const uint8_t kPad4Num = 11;
static const uint8_t kPad5Num = 12;
static const uint8_t kPad6Num = 13;
static const uint8_t kPad7Num = 14;
static const uint8_t kPad8Num = 15;

static const uint8_t kPadMidi[] = {
  kPad1Num,
  kPad2Num,
  kPad3Num,
  kPad4Num,
  kPad5Num,
  kPad6Num,
  kPad7Num,
  kPad8Num
};
// Control Changes

// channel 12

static const uint8_t LEVEL_DECK_A = 0;
static const uint8_t LEVEL_DECK_B = 1;
static const uint8_t LEVEL_DECK_C = 2;
static const uint8_t MASTER_OUT_L = 3;
static const uint8_t MASTER_OUT_R = 4;