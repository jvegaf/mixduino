
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

class NPKit  
{
	private:
		Adafruit_NeoPixel* _np;
	public:
		NPKit(uint8_t dataPin, uint8_t nPixels);
		void begin();
		void handleChange(uint8_t pos, uint8_t value);
		void fill(uint8_t colorValue, uint8_t* pixAggr, uint8_t count);

		void allOFF();
};
#endif
