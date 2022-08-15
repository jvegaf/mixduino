#pragma once

#include <Arduino.h>
#include "md_enums.hpp"

namespace MDFeedback
{
		void initialize();
		void onCChange(uint8_t channel, uint8_t number, uint8_t value);
		void onNoteOn(uint8_t channel, uint8_t number, uint8_t value);
		void changePad(Location loc, uint32_t color);

} // namespace MDFeedback
