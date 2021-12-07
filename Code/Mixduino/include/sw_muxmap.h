
#ifndef ARDUINO_SW_MUXMAP_H
#define ARDUINO_SW_MUXMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// MUX LEFT BUTTONS

static const uint8_t SWPCUEL2  = 0;
static const uint8_t SWPCUEL1  = 1;
static const uint8_t SWSHIFT   = 2;
static const uint8_t SWLOOP_L  = 3;
static const uint8_t SWSYNC_L  = 4;
static const uint8_t SWMODE_L  = 5;
static const uint8_t SWPLAY_L  = 6;
static const uint8_t SWCUE_L   = 7;
static const uint8_t SWPADL8   = 8;
static const uint8_t SWPADL4   = 9;
static const uint8_t SWPADL7   = 10;
static const uint8_t SWPADL3   = 11;
static const uint8_t SWPADL2   = 12;
static const uint8_t SWPADL6   = 13;
static const uint8_t SWPADL1   = 14;
static const uint8_t SWPADL5   = 15;

static const uint8_t MUX_SW_BND_L[] = {
    SWPCUEL2,
    SWPCUEL1,
    SWSHIFT,
    SWLOOP_L,
    SWSYNC_L,
    SWMODE_L,
    SWPLAY_L,
    SWCUE_L,
    SWPADL8,
    SWPADL4,
    SWPADL7,
    SWPADL3,
    SWPADL2,
    SWPADL6,
    SWPADL1,
    SWPADL5
};

static const uint8_t T_MUX_SW_BND_L = 16;


//////////////////////////////////////
// MUX RIGHT BUTTONS

static const uint8_t SWCUE_R    = 0;
static const uint8_t SWPLAY_R   = 1;
static const uint8_t SWMODE_R   = 2;
static const uint8_t SWLOOP_R   = 3;
static const uint8_t SWPCUEL3   = 5;
static const uint8_t SWSYNC_R   = 6;
static const uint8_t SWDECK_SEL = 7;
static const uint8_t SWPADR8    = 8;
static const uint8_t SWPADR4    = 9;
static const uint8_t SWPADR7    = 10;
static const uint8_t SWPADR3    = 11;
static const uint8_t SWPADR2    = 12;
static const uint8_t SWPADR6    = 13;
static const uint8_t SWPADR1    = 14;
static const uint8_t SWPADR5    = 15;


static const uint8_t MUX_SW_BND_R[] = {
    SWCUE_R,
    SWPLAY_R,
    SWMODE_R,
    SWLOOP_R,
    SWPCUEL3,
    SWSYNC_R,
    SWDECK_SEL,
    SWPADR8,
    SWPADR4,
    SWPADR7,
    SWPADR3,
    SWPADR2,
    SWPADR6,
    SWPADR1,
    SWPADR5
};

static const uint8_t T_MUX_SW_BND_R = 15;

#endif
