#pragma once
#ifndef MD_DEFS_H
#define MD_DEFS_H
#include <Arduino.h>

////////////////////////////////////
// STATES

enum class State
{
    STATE_LOW,
    STATE_HIGH,
    STATE_SAME
};

enum class DeckMode
{
    MODE_HOTCUE,
    MODE_LOOP,
    MODE_FX
};

#endif // MD_DEFS_H
