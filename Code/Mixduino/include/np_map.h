
#ifndef ARDUINO_NP_MAP_H
#define ARDUINO_NP_MAP_H
#include <Arduino.h>
#include "md_colors.h"

#pragma once

//////////////////////////////////////
// NEOPIXELS

const uint8_t NP_PADL1    = 0;
const uint8_t NP_PADL2    = 1;
const uint8_t NP_PADL3    = 2;
const uint8_t NP_PADL4    = 3;
const uint8_t NP_PADL5    = 4;
const uint8_t NP_PADL6    = 5;
const uint8_t NP_PADL7    = 6;
const uint8_t NP_PADL8    = 7;
const uint8_t NP_RANGE_L  = 8;
const uint8_t NP_SYNC_L   = 9;
const uint8_t NP_PADR1   = 10;
const uint8_t NP_PADR2   = 11;
const uint8_t NP_PADR3   = 12;
const uint8_t NP_PADR4   = 13;
const uint8_t NP_PADR5   = 14;
const uint8_t NP_PADR6   = 15;
const uint8_t NP_PADR7   = 16;
const uint8_t NP_PADR8   = 17;
const uint8_t NP_DECK_SEL = 18;
const uint8_t NP_RANGE_R  = 19;
const uint8_t NP_SYNC_R   = 20;

uint8_t const px_padl_set[] = {
    NP_PADL1,
    NP_PADL2,
    NP_PADL3,
    NP_PADL4,
    NP_PADL5,
    NP_PADL6,
    NP_PADL7,
    NP_PADL8
};

uint8_t const px_padr_set[] = {
    NP_PADR1,
    NP_PADR2,
    NP_PADR3,
    NP_PADR4,
    NP_PADR5,
    NP_PADR6,
    NP_PADR7,
    NP_PADR8
};

const uint32_t hotcues_padmode_color = MDColor::CLEAR_COL;
const uint32_t loop_padmode_color = MDColor::loop_color;
const uint32_t beatj_padmode_color = MDColor::ORANGE_COL;
const uint32_t temposel_padmode_color = MDColor::PURPLE_COL;


// const uint8_t NPSet[] = {
//     NP_PADL1,
//     NP_PADL2,
//     NP_PADL3,
//     NP_PADL4,
//     NP_PADL5,
//     NP_PADL6,
//     NP_PADL7,
//     NP_PADL8,
//     NP_RANGE_L,
//     NP_SYNC_L,
//     NP_PADR_1,
//     NP_PADR_2,
//     NP_PADR_3,
//     NP_PADR_4,
//     NP_PADR_5,
//     NP_PADR_6,
//     NP_PADR_7,
//     NP_PADR_8,
//     NP_DECK_SEL,
//     NP_RANGE_R,
//     NP_SYNC_R
// };

#endif
