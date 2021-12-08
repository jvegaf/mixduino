
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////////
// CHANNELS

static const uint8_t IN_ONLY_CH    = 4;
static const uint8_t IN_OUT_CH     = 5;
static const uint8_t LEFT_PAD_CH   = 6;
static const uint8_t RIGHT_PAD_CH  = 7;
static const uint8_t BR_ENCODER_CH = 8;
static const uint8_t VUMETERS_CH   = 12;

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



static const uint8_t T_MIDI_SET = 18;


static const uint8_t T_MIDI_BLIND_SET = 5;
// Control Changes

// channel 12

static const uint8_t LEVEL_DECK_A = 0;
static const uint8_t LEVEL_DECK_B = 1;
static const uint8_t LEVEL_DECK_C = 2;
static const uint8_t MASTER_OUT_L = 3;
static const uint8_t MASTER_OUT_R = 4;

#endif
