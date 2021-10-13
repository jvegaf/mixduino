
#ifndef ARDUINO_SW_MUXMAP_H
#define ARDUINO_SW_MUXMAP_H
#include <Arduino.h>

#pragma once

//////////////////////////////////////
// MUX LEFT BUTTONS

byte const SWPCUEL2  = 0;
byte const SWPCUEL1  = 1;
byte const SWSHIFT   = 2;
byte const SWLOOP_L  = 3;
byte const SWSYNC_L  = 4;
byte const SWRANGE_L = 5;
byte const SWPLAY_L  = 6;
byte const SWCUE_L   = 7;
byte const SWPADL8   = 8;
byte const SWPADL4   = 9;
byte const SWPADL7   = 10;
byte const SWPADL3   = 11;
byte const SWPADL2   = 12;
byte const SWPADL6   = 13;
byte const SWPADL1   = 14;
byte const SWPADL5   = 15;

const byte SwMuxLeftSet[] = {
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

const byte nSwMuxLeft = 16;


//////////////////////////////////////
// MUX RIGHT BUTTONS

byte const SWCUE_R    = 0;
byte const SWPLAY_R   = 1;
byte const SWRANGE_R  = 2;
byte const SWLOOP_R   = 3;
byte const SWPCUEL3   = 5;
byte const SWSYNC_R   = 6;
byte const SWDECK_SEL = 7;
byte const SWPADR8    = 8;
byte const SWPADR4    = 9;
byte const SWPADR7    = 10;
byte const SWPADR3    = 11;
byte const SWPADR2    = 12;
byte const SWPADR6    = 13;
byte const SWPADR1    = 14;
byte const SWPADR5    = 15;


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
    SWPADR5
};

const byte nSwMuxRight = 15;

#endif
