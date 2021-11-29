#pragma once
#include "pin_map.h"
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <Npixel.h>

namespace feedback
{
	class NPKit
	{
	private:
		Adafruit_NeoPixel *np;

	public:
		NPKit(uint8_t dataPin, uint8_t nPixels);
		void begin();
		void handleChange(Npixel npx);
	};
} // namespace feedback
