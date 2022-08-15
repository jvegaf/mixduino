#pragma once

#include "md_controller.h"
#include <Arduino.h>

namespace MDFeedback {
void initialize();
void setVuValue(uint8_t number, uint8_t value);
void setLedValue(uint8_t pos, uint8_t value);
void setPixel(uint8_t number, uint32_t mode_c);
void changePad(Location loc, uint32_t mode_c);
void changePads(Location loc, uint32_t *colors);

} // namespace MDFeedback
