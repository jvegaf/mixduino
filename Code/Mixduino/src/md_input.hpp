#pragma once

#include <Arduino.h>

namespace MDInput
{
  void read(void (*func)(uint8_t, uint8_t));
} // namespace MDInput
