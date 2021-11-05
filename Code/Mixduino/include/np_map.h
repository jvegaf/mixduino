
#ifndef ARDUINO_NP_MAP_H
#define ARDUINO_NP_MAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// NEOPIXELS

uint8_t const NP_PADL1    = 0;
uint8_t const NP_PADL2    = 1;
uint8_t const NP_PADL3    = 2;
uint8_t const NP_PADL4    = 3;
uint8_t const NP_PADL5    = 4;
uint8_t const NP_PADL6    = 5;
uint8_t const NP_PADL7    = 6;
uint8_t const NP_PADL8    = 7;
uint8_t const NP_MODE_L   = 8;
uint8_t const NP_SYNC_L   = 9;
uint8_t const NP_PADR_1   = 10;
uint8_t const NP_PADR_2   = 11;
uint8_t const NP_PADR_3   = 12;
uint8_t const NP_PADR_4   = 13;
uint8_t const NP_PADR_5   = 14;
uint8_t const NP_PADR_6   = 15;
uint8_t const NP_PADR_7   = 16;
uint8_t const NP_PADR_8   = 17;
uint8_t const NP_DECK_SEL = 18;
uint8_t const NP_MODE_R   = 19;
uint8_t const NP_SYNC_R   = 20;

uint8_t const T_NP = 21;

uint8_t const HOTCUE_MODE_COLOR     = 0;
uint8_t const LOOP_MODE_COLOR       = 5;
uint8_t const FX_MODE_COLOR         = 7;

const uint8_t PIXLS_PAD_L[] = {
    NP_PADL1,
    NP_PADL2,
    NP_PADL3,
    NP_PADL4,
    NP_PADL5,
    NP_PADL6,
    NP_PADL7,
    NP_PADL8};

const uint8_t PIXLS_PAD_R[] = {
    NP_PADR_1,
    NP_PADR_2,
    NP_PADR_3,
    NP_PADR_4,
    NP_PADR_5,
    NP_PADR_6,
    NP_PADR_7,
    NP_PADR_8};


#endif
