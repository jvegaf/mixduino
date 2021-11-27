#pragma once
#ifndef MD_DEFS_H
#define MD_DEFS_H
#include <Arduino.h>

uint8_t const HOTCUE_MODE_COLOR = 0;
uint8_t const LOOP_MODE_COLOR   = 6;
uint8_t const FX_MODE_COLOR     = 7;

uint8_t const T_DECK_PADS        = 8;
uint8_t const T_PLAYER_BTNS      = 4;
uint8_t const T_VUMETER_SET      = 5;
uint8_t const T_BROWSER_BTNS     = 4;
uint8_t const T_BROWSER_ENCODERS = 2;
uint8_t const T_FX_UNITS         = 2;
uint8_t const T_FX_BTNS          = 3;
uint8_t const T_FX_POTS          = 3;

uint8_t const ALIGN_LEFT         = 0;
uint8_t const ALIGN_RIGHT        = 1;

#endif // MD_DEFS_H
