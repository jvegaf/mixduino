
#ifndef ARDUINO_NP_MAP_H
#define ARDUINO_NP_MAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// NEOPIXELS

byte const NP_PADL1    = 0;
byte const NP_PADL2    = 1;
byte const NP_PADL3    = 2;
byte const NP_PADL4    = 3;
byte const NP_PADL5    = 4;
byte const NP_PADL6    = 5;
byte const NP_PADL7    = 6;
byte const NP_PADL8    = 7;
byte const NP_RANGE_L  = 8;
byte const NP_SYNC_L   = 9;
byte const NP_PADR_1   = 10;
byte const NP_PADR_2   = 11;
byte const NP_PADR_3   = 12;
byte const NP_PADR_4   = 13;
byte const NP_PADR_5   = 14;
byte const NP_PADR_6   = 15;
byte const NP_PADR_7   = 16;
byte const NP_PADR_8   = 17;
byte const NP_DECK_SEL = 18;
byte const NP_RANGE_R  = 19;
byte const NP_SYNC_R   = 20;

const byte NPSet[] = {
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

const byte nNP = 21;

#endif
