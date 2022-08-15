#pragma once

#include <Arduino.h>
#include "pin_map.h"


namespace MD
{
  void initPins() {
    for (size_t i = 0; i < t_in_p; i++)
    {
      pinMode(in_pins[i], INPUT_PULLUP);
    }

    for (size_t i = 0; i < t_out_p; i++)
    {
      pinMode(out_pins[i], OUTPUT);
    }
  }
} // namespace MD
