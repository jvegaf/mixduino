#pragma once
#include <Arduino.h>


// top pots

static const uint8_t PFX1L   = 0;
static const uint8_t PFX2L   = 1;
static const uint8_t PFX3L   = 2;
static const uint8_t PGAINL1 = 3;
static const uint8_t PGAINL2 = 4;
static const uint8_t PGAINL3 = 5;
static const uint8_t PFX2R   = 6;
static const uint8_t PFX3R   = 7;
static const uint8_t TREL1   = 8;
static const uint8_t TREL2   = 9;
static const uint8_t TREL3   = 10;

const uint8_t kTopMuxpotsSet[] = {
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
const uint8_t ktTopMuxpots = 11;

// BOTTOM POTS
static const uint8_t FADER_L2  = 0;
static const uint8_t FADER_L1  = 1;
static const uint8_t PITCH_R   = 2;
static const uint8_t FILTER_L3 = 3;
static const uint8_t PVOL_HP   = 4;
static const uint8_t BAS_L1    = 5;
static const uint8_t MID_L1    = 6;
static const uint8_t BAS_L2    = 7;
static const uint8_t MID_L2    = 8;
static const uint8_t MID_L3    = 9;
static const uint8_t BAS_L3    = 10;
static const uint8_t FILTER_L2 = 11;
static const uint8_t FILTER_L1 = 12;
static const uint8_t PITCH_L   = 13;
static const uint8_t PMIX_HP   = 14;
static const uint8_t FADER_L3  = 15;

const uint8_t kBottomMuxpotsSet[] = {
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

const uint8_t ktBottomMuxPots = 16;

