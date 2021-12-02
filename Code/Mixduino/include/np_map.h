
#ifndef ARDUINO_NP_MAP_H
#define ARDUINO_NP_MAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// NEOPIXELS

static const uint8_t NP_PADL1    = 0;
static const uint8_t NP_PADL2    = 1;
static const uint8_t NP_PADL3    = 2;
static const uint8_t NP_PADL4    = 3;
static const uint8_t NP_PADL5    = 4;
static const uint8_t NP_PADL6    = 5;
static const uint8_t NP_PADL7    = 6;
static const uint8_t NP_PADL8    = 7;
static const uint8_t NP_RANGE_L  = 8;
static const uint8_t NP_SYNC_L   = 9;
static const uint8_t NP_PADR_1   = 10;
static const uint8_t NP_PADR_2   = 11;
static const uint8_t NP_PADR_3   = 12;
static const uint8_t NP_PADR_4   = 13;
static const uint8_t NP_PADR_5   = 14;
static const uint8_t NP_PADR_6   = 15;
static const uint8_t NP_PADR_7   = 16;
static const uint8_t NP_PADR_8   = 17;
static const uint8_t NP_DECK_SEL = 18;
static const uint8_t NP_RANGE_R  = 19;
static const uint8_t NP_SYNC_R   = 20;

const uint8_t NPSet[] = {
    NP_PADL1,
    NP_PADL2,
    NP_PADL3,
    NP_PADL4,
    NP_PADL5,
    NP_PADL6,
    NP_PADL7,
    NP_PADL8,
    NP_RANGE_L,
    NP_SYNC_L,
    NP_PADR_1,
    NP_PADR_2,
    NP_PADR_3,
    NP_PADR_4,
    NP_PADR_5,
    NP_PADR_6,
    NP_PADR_7,
    NP_PADR_8,
    NP_DECK_SEL,
    NP_RANGE_R,
    NP_SYNC_R
};

const uint8_t nNP = 21;

#endif
