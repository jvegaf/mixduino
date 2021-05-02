
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "np_colors.h"

class NPKit  
{
	private:
		Adafruit_NeoPixel adaPx;

	public:
		void clear();
		NPKit(uint8_t dataPin, uint8_t nPixels);
		void begin();
		void handleON(uint8_t number, uint8_t value);
		void handleOFF(uint8_t number);
};
#endif
