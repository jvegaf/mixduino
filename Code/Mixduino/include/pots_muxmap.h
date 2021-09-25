
#ifndef ARDUINO_POTS_MUXMAP_H
#define ARDUINO_POTS_MUXMAP_H
#include <Arduino.h>

#pragma once

// top pots

byte const PFX1L = 1;
byte const PFX2L = 2;
byte const PFX3L = 3;
byte const PGAINL1 = 4;
byte const PGAINL2 = 5;
byte const PGAINL3 = 6;
byte const PFX2R = 7;
byte const PFX3R = 8;
byte const TREL1 = 9;
byte const TREL2 = 10;
byte const TREL3 = 11;

const byte topMuxpotsSet[] = {
    PFX1L,
    PFX2L,
    PFX3L,
    PGAINL1,
    PGAINL2,
    PGAINL3,
    PFX2R,
    PFX3R,
    TREL1,
    TREL2,
    TREL3
};

// BOTTOM POTS
byte const FADER_L2 = 1;
byte const FADER_L1 = 2;
byte const PITCH_R = 3;
byte const FILTER_L3 = 4;
byte const PVOL_HP = 5;
byte const BAS_L1 = 6;
byte const MID_L1 = 7;
byte const BAS_L2 = 8;
byte const MID_L2 = 9;
byte const MID_L3 = 10;
byte const BAS_L3 = 11;
byte const FILTER_L2 = 12;
byte const FILTER_L1 = 13;
byte const PITCH_L = 14;
byte const PMIX_HP = 15;
byte const FADER_L3 = 16;

const byte bottomMuxpotsSet[] = {
    FADER_L2,
    FADER_L1,
    PITCH_R,
    FILTER_L3,
    PVOL_HP,
    BAS_L1,
    MID_L1,
    BAS_L2,
    MID_L2,
    MID_L3,
    BAS_L3,
    FILTER_L2,
    FILTER_L1,
    PITCH_L,
    PMIX_HP,
    FADER_L3
};

#endif
