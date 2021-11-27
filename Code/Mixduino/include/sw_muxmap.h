
#ifndef ARDUINO_SW_MUXMAP_H
#define ARDUINO_SW_MUXMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// MUX LEFT BUTTONS

uint8_t const SWPCUEL2  = 0;
uint8_t const SWPCUEL1  = 1;
uint8_t const SWSHIFT   = 2;
uint8_t const SWLOOP_L  = 3;
uint8_t const SWSYNC_L  = 4;
uint8_t const SWMODE_L  = 5;
uint8_t const SWPLAY_L  = 6;
uint8_t const SWCUE_L   = 7;
uint8_t const SWPADL8   = 8;
uint8_t const SWPADL4   = 9;
uint8_t const SWPADL7   = 10;
uint8_t const SWPADL3   = 11;
uint8_t const SWPADL2   = 12;
uint8_t const SWPADL6   = 13;
uint8_t const SWPADL1   = 14;
uint8_t const SWPADL5   = 15;

uint8_t MUX_SW_PLAYER_BUNDLE_L[] = {
    SWPLAY_L,
    SWCUE_L,
    SWSYNC_L,
    SWLOOP_L
    };

uint8_t MUX_SW_PLAYER_BUNDLE_R[] = {
    SWPLAY_R,
    SWCUE_R,
    SWSYNC_R,
    SWLOOP_R
    };

uint8_t const T_MUX_SW_PLAYER = 4;

const uint8_t SW_PADL_BUNDLE[] = {
    SWPADL1,
    SWPADL2,
    SWPADL3,
    SWPADL4,
    SWPADL5,
    SWPADL6,
    SWPADL7,
    SWPADL8
};

//////////////////////////////////////
// MUX RIGHT BUTTONS

uint8_t const SWCUE_R    = 0;
uint8_t const SWPLAY_R   = 1;
uint8_t const SWMODE_R   = 2;
uint8_t const SWLOOP_R   = 3;
uint8_t const SWPCUEL3   = 5;
uint8_t const SWSYNC_R   = 6;
uint8_t const SWDECK_SEL = 7;
uint8_t const SWPADR8    = 8;
uint8_t const SWPADR4    = 9;
uint8_t const SWPADR7    = 10;
uint8_t const SWPADR3    = 11;
uint8_t const SWPADR2    = 12;
uint8_t const SWPADR6    = 13;
uint8_t const SWPADR1    = 14;
uint8_t const SWPADR5    = 15;


const uint8_t MUX_SW_BUNDLE_R[] = {
    SWPLAY_R,
    SWCUE_R,
    SWLOOP_R,
    SWPCUEL3
};

const uint8_t T_MUX_SW_R = 4;

const uint8_t SW_PADR_BUNDLE[] = {
    SWPADR1,
    SWPADR2,
    SWPADR3,
    SWPADR4,
    SWPADR5,
    SWPADR6,
    SWPADR7,
    SWPADR8,
};

#endif
