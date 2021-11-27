
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////////
// CHANNELS

uint8_t const FX1_CH      = 3;
uint8_t const FX2_CH      = 4;
uint8_t const BROWSER_CH  = 5;
uint8_t const DECK_A_CH   = 6;
uint8_t const DECK_B_CH   = 7;
uint8_t const DECK_C_CH   = 8;
uint8_t const MIXER_CH    = 10;

/////////////////////////////////////////
// NOTES

uint8_t const PLAY_NOTE       = 0;
uint8_t const CUE_NOTE        = 1;
uint8_t const SYNC_NOTE       = 2;
uint8_t const LOOP_NOTE       = 3;
uint8_t const LOAD_TRACK_NOTE = 4;
uint8_t const PAD_HOTCUE_NOTE = 16;
uint8_t const PAD_LOOP_NOTE   = 24;
uint8_t const PAD_FX_NOTE     = 32;

uint8_t const TEMPO_MIDI_NUMBER = 16;

uint8_t PLAYER_MIDI_BUNDLE[] = {
    PLAY_NOTE,
    CUE_NOTE,
    SYNC_NOTE,
    LOOP_NOTE};

uint8_t const T_MIDI_PLAYER = 4;

uint8_t const SEND_MON_STATE = 38;  // d1

uint8_t const T_MIDI_BLIND_SET = 5;
// Control Changes

// channel 12

uint8_t const LEVEL_DECK_A = 0;
uint8_t const LEVEL_DECK_B = 1;
uint8_t const LEVEL_DECK_C = 2;
uint8_t const MASTER_OUT_L = 3;
uint8_t const MASTER_OUT_R = 4;

// mixer pots

uint8_t const GAIN_DK_A   = 0;
uint8_t const GAIN_DK_B   = 1;
uint8_t const GAIN_DK_C   = 2;
uint8_t const TRE_DK_A    = 3;
uint8_t const TRE_DK_B    = 4;
uint8_t const TRE_DK_C    = 5;
uint8_t const MID_DK_A    = 6;
uint8_t const MID_DK_B    = 7;
uint8_t const MID_DK_C    = 8;
uint8_t const BAS_DK_A    = 9;
uint8_t const BAS_DK_B    = 10;
uint8_t const BAS_DK_C    = 11;
uint8_t const FILTER_DK_A = 12;
uint8_t const FILTER_DK_B = 13;
uint8_t const FILTER_DK_C = 14;
uint8_t const VOLUME_DK_A = 15;
uint8_t const VOLUME_DK_B = 16;
uint8_t const VOLUME_DK_C = 17;
uint8_t const VOL_MON     = 18;
uint8_t const MIX_MON     = 19;
uint8_t const VOL_MASTER  = 20;

uint8_t MIDI_MIXER_POTS_BNDL[] = {
    GAIN_DK_A,
    GAIN_DK_B,
    GAIN_DK_C,
    TRE_DK_A,
    TRE_DK_B,
    TRE_DK_C,
    MID_DK_A,
    MID_DK_B,
    MID_DK_C,
    BAS_DK_A,
    BAS_DK_B,
    BAS_DK_C,
    FILTER_DK_A,
    FILTER_DK_B,
    FILTER_DK_C,
    VOLUME_DK_A,
    VOLUME_DK_B,
    VOLUME_DK_C,
    VOL_MON,
    MIX_MON,
    VOL_MASTER

}; 

uint8_t const T_MIDI_MIXER_POTS = 21;
uint8_t const T_MIDI_MIXER_BTNS = 3;


#endif
