#pragma once
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

namespace mixduino
{
	class NPixel
	{
	private:
		Adafruit_NeoPixel *m_np;

	public:
		NPixel(uint8_t dataPin, uint8_t nPixels);
		void begin();
		void handleChange(uint8_t position, uint8_t value);
	};
} // namespace mixduino
