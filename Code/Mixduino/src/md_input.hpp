#pragma once

#include <Arduino.h>
#include "md_enums.hpp"


namespace MDInput
{
  void read(void (*func)(uint8_t, State));
} // namespace MDInput
