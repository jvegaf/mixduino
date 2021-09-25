
#ifndef ARDUINO_SW_MUXMAP_H
#define ARDUINO_SW_MUXMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// MUX LEFT BUTTONS

byte const SWPCUEL2  = 1;
byte const SWPCUEL1  = 2;
byte const SWSHIFT   = 3;
byte const SWLOOP_L  = 4;
byte const SWSYNC_L  = 5;
byte const SWRANGE_L = 6;
byte const SWPLAY_L  = 7;
byte const SWCUE_L   = 8;
byte const SWPADL8   = 9;
byte const SWPADL4   = 10;
byte const SWPADL7   = 11;
byte const SWPADL3   = 12;
byte const SWPADL2   = 13;
byte const SWPADL6   = 14;
byte const SWPADL1   = 15;
byte const SWPADL5   = 16;

//////////////////////////////////////
// MUX RIGHT BUTTONS

byte const SWCUE_R    = 1;
byte const SWPLAY_R   = 2;
byte const SWRANGE_R  = 3;
byte const SWLOOP_R   = 4;
byte const SWPCUEL3   = 6;
byte const SWSYNC_R   = 7;
byte const SWDECK_SEL = 8;
byte const SWPADR8    = 9;
byte const SWPADR4    = 10;
byte const SWPADR7    = 11;
byte const SWPADR3    = 12;
byte const SWPADR2    = 13;
byte const SWPADR6    = 14;
byte const SWPADR1    = 15;
byte const SWPADR5    = 16;

const byte SWMuxLeftSet[] = {
    SWPCUEL2,
    SWPCUEL1,
    SWSHIFT,
    SWLOOP_L,
    SWSYNC_L,
    SWRANGE_L,
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

const byte SWMuxRightSet[] = {
    SWCUE_R,
    SWPLAY_R,
    SWRANGE_R,
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
    SWPADR5};

#endif
