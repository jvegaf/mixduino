#pragma once
#ifndef MD_DEFS_H
#define MD_DEFS_H
#include <Arduino.h>

uint8_t const HOTCUE_MODE_COLOR     = 0;
uint8_t const LOOP_MODE_COLOR       = 5;
uint8_t const FX_MODE_COLOR         = 7;

enum class State { STATE_ON, STATE_OFF };

#endif // MD_DEFS_H
