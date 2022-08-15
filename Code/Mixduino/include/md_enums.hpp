#pragma once

#include <Arduino.h>
#include "midi_map.h"


enum class Mode : uint8_t
{
    HotCues = hotcues_ch,
    Loop = loop_size_ch,
    Beatjump = beatjump_ch,
    TempoRange = tempo_range_ch
};

enum class State: uint8_t 
{
  Idle = 0,
  Triggered = 127U
};

enum class Location {
  Left,
  Right
 };

 enum class ActiveDeck
 {
  Deck_B, 
  Deck_C
 };