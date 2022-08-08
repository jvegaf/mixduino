#pragma once

#include <Arduino.h>

namespace MDPixels
{
		void initialize();
		void changePixel( uint8_t position, uint32_t color);
		void changeRange( uint8_t position, uint8_t t_pixels, uint32_t color);
} // namespace Pixels
