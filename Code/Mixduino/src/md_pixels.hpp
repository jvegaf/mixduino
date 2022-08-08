#pragma once

#include <Arduino.h>

namespace MDPixels
{
		void initialize();
		void changePixel( uint8_t position, uint8_t value);
		void changeRange( uint8_t position, uint8_t t_pixels, uint8_t value);
	
} // namespace Pixels
