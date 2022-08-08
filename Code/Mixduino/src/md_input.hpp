#pragma once

#include <Arduino.h>
#include "location_enu.h"


namespace MDInput
{
  void initialize();
  void readSelector(void(*selFunc)());
  void readPadMode(void(*pModesFunc)(),Location loc);
  void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t padl_ch, uint8_t padr_ch);
} // namespace MDInput
