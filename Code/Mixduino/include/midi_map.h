
#ifndef ARDUINO_MIDI_MAP_H
#define ARDUINO_MIDI_MAP_H
#include <Arduino.h>

#pragma once

/////////////////////////////////////////
// CHANNELS

uint8_t const IN_ONLY_CH = 4;
uint8_t const IN_OUT_CH = 5;
uint8_t const LEFT_PAD_CH = 6;
uint8_t const RIGHT_PAD_CH = 7;
uint8_t const BR_ENCODER_CH = 8;
uint8_t const VUMETERS_CH = 12;

/////////////////////////////////////////
// NOTES

uint8_t const SEND_MON_STATE = 38; // d1
uint8_t const MON_CUE_A = 39;      // d#1
uint8_t const MON_CUE_B = 40;      // e1
uint8_t const MON_CUE_C = 41;      // f1
uint8_t const FX1_BTN_1 = 42;      // f#1
uint8_t const FX1_BTN_2 = 43;      // g1
uint8_t const FX1_BTN_3 = 44;      // g#1
uint8_t const FX2_BTN_1 = 45;      // a1
uint8_t const FX2_BTN_1 = 46;      // a#1
uint8_t const FX2_BTN_3 = 47;      // b1
uint8_t const PLAY_DK_A = 48;      // c2
uint8_t const PLAY_DK_B = 49;      // c#2     & DECK_C
uint8_t const CUE_DK_A = 50;       // d2
uint8_t const CUE_DK_B = 51;       // d#2     & DECK_C
uint8_t const LOOP_DK_A = 52;      // e2
uint8_t const LOOP_DK_B = 53;      // f2     & DECK_C
uint8_t const SYNC_DECK_A = 54;    // f#2
uint8_t const SYNC_DECK_B = 55;    // g2
uint8_t const DECK_B_C_SEL = 56;   // g#2
uint8_t const BRW_SEL_DECK_A = 57; // a2
uint8_t const BRW_SEL_DECK_B = 58; // a#2     & DECK_c
uint8_t const BRW_PREVIOUS = 59;   // b2
uint8_t const BRW_BACK = 60;       // c3
uint8_t const SHIFT_FN = 61;       // c#3

const uint8_t midiSet[] = {
    MON_CUE_A,
    MON_CUE_B,
    MON_CUE_C,
    FX1_BTN_1,
    FX1_BTN_2,
    FX1_BTN_3,
    FX2_BTN_1,
    FX2_BTN_1,
    FX2_BTN_3,
    PLAY_DK_A,
    PLAY_DK_B,
    CUE_DK_A,
    CUE_DK_B,
    LOOP_DK_A,
    LOOP_DK_B,
    SYNC_DECK_A,
    SYNC_DECK_B,
    DECK_B_C_SEL};

uint8_t const T_MIDI_SET = 18;

const uint8_t blindMidiSet[] = {
    BRW_SEL_DECK_A,
    BRW_SEL_DECK_B,
    BRW_PREVIOUS,
    BRW_BACK,
    SHIFT_FN};

uint8_t const T_MIDI_BLIND_SET = 5;
// Control Changes

// channel 12

uint8_t const LEVEL_DECK_A = 0;
uint8_t const LEVEL_DECK_B = 1;
uint8_t const LEVEL_DECK_C = 2;
uint8_t const MASTER_OUT_L = 3;
uint8_t const MASTER_OUT_R = 4;

#endif
