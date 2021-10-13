
#ifndef ARDUINO_POTS_MUXMAP_H
#define ARDUINO_POTS_MUXMAP_H
#include <Arduino.h>

#pragma once

// top pots

byte const PFX1L   = 0;
byte const PFX2L   = 1;
byte const PFX3L   = 2;
byte const PGAINL1 = 3;
byte const PGAINL2 = 4;
byte const PGAINL3 = 5;
byte const PFX2R   = 6;
byte const PFX3R   = 7;
byte const TREL1   = 8;
byte const TREL2   = 9;
byte const TREL3   = 10;

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
const byte nTopMuxpots = 11;

// BOTTOM POTS
byte const FADER_L2  = 0;
byte const FADER_L1  = 1;
byte const PITCH_R   = 2;
byte const FILTER_L3 = 3;
byte const PVOL_HP   = 4;
byte const BAS_L1    = 5;
byte const MID_L1    = 6;
byte const BAS_L2    = 7;
byte const MID_L2    = 8;
byte const MID_L3    = 9;
byte const BAS_L3    = 10;
byte const FILTER_L2 = 11;
byte const FILTER_L1 = 12;
byte const PITCH_L   = 13;
byte const PMIX_HP   = 14;
byte const FADER_L3  = 15;

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

const byte nBottomMuxPots = 16;

#endif
