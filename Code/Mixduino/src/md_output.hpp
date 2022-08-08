#pragma once

#include <Arduino.h>
#include "location_enu.h"

namespace MDOutput
{
		void initialize();
		void cChange(uint8_t channel, uint8_t number, uint8_t value);
		void noteOn(uint8_t channel, uint8_t number, uint8_t value);
		void changePad(Location loc, uint32_t color);

} // namespace MDOutput
