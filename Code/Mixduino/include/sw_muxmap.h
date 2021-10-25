
#ifndef ARDUINO_SW_MUXMAP_H
#define ARDUINO_SW_MUXMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// MUX LEFT BUTTONS

uint8_t const MUXSW_LEFT_SIG = MPLEX_A3;

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

const uint8_t SwMuxLeftSet[] = {
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
    SWPADL5};

const uint8_t nSwMuxLeft = 16;


//////////////////////////////////////
// MUX RIGHT BUTTONS
uint8_t const MUXSW_RIGHT_SIG = MPLEX_A2;

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


const uint8_t SWMuxRightSet[] = {
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

const uint8_t nSwMuxRight = 15;

#endif
