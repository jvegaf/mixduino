
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
