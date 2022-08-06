#pragma once

#include <Arduino.h>

namespace MDTouch
{
  void initialize();
  void read(void (*scc_func)(uint8_t, uint8_t, uint8_t));

} // namespace MDTouch
