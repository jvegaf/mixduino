
#ifndef ARDUINO_POTS_MUXMAP_H
#define ARDUINO_POTS_MUXMAP_H
#include <Arduino.h>

#pragma once

// top pots

uint8_t const PFX1L   = 0;
uint8_t const PFX2L   = 1;
uint8_t const PFX3L   = 2;
uint8_t const PGAINL1 = 3;
uint8_t const PGAINL2 = 4;
uint8_t const PGAINL3 = 5;
uint8_t const PFX2R   = 6;
uint8_t const PFX3R   = 7;
uint8_t const TREL1   = 8;
uint8_t const TREL2   = 9;
uint8_t const TREL3   = 10;

const uint8_t topMuxpotsSet[] = {
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
const uint8_t nTopMuxpots = 11;

// BOTTOM POTS
uint8_t const FADER_L2  = 0;
uint8_t const FADER_L1  = 1;
uint8_t const PITCH_R   = 2;
uint8_t const FILTER_L3 = 3;
uint8_t const PVOL_HP   = 4;
uint8_t const BAS_L1    = 5;
uint8_t const MID_L1    = 6;
uint8_t const BAS_L2    = 7;
uint8_t const MID_L2    = 8;
uint8_t const MID_L3    = 9;
uint8_t const BAS_L3    = 10;
uint8_t const FILTER_L2 = 11;
uint8_t const FILTER_L1 = 12;
uint8_t const PITCH_L   = 13;
uint8_t const PMIX_HP   = 14;
uint8_t const FADER_L3  = 15;

const uint8_t bottomMuxpotsSet[] = {
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

const uint8_t nBottomMuxPots = 16;

#endif
