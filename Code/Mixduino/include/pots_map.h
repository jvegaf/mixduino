
#ifndef ARDUINO_POTS_MAP_H
#define ARDUINO_POTS_MAP_H
#include <Arduino.h>

#pragma once

// mux pots

byte const PITCH_R         = 12;
byte const PMIX_HP         = 14;
byte const PVOL_HP         = 13;
byte const FADER_C         = 15;
byte const FADER_B         = 0;
byte const FADER_A         = 1;
byte const PITCH_L         = 2;
byte const FILTER_A        = 3;
byte const FILTER_B        = 4;
byte const FILTER_C        = 9;
byte const BAS_A           = 5;
byte const BAS_B           = 7;
byte const BAS_C           = 10;
byte const MID_A           = 6;
byte const MID_B           = 8;
byte const MID_C           = 9;

// MP-BTNS
byte const SWPRECUE_L1    = 1;
byte const SWPRECUE_L2    = 0;
byte const SWSHIFT        = 2;
byte const SWRANGE_L      = 5;
byte const SWLOOP_L       = 3;
byte const SWSYNC_L       = 4;
byte const SWCUE_L        = 7;
byte const SWPLAY_L       = 6;
byte const SWPADL_1       = 9;
byte const SWPADL_2       = 11;
byte const SWPADL_3       = 13;
byte const SWPADL_4       = 14;
byte const SWPADL_5       = 8;
byte const SWPADL_6       = 10;
byte const SWPADL_7       = 12;
byte const SWPADL_8       = 15;

#endif
