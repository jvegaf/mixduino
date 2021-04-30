
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pinMap.h"

class NPKit  
{
	private:


	public:
		void begin();
		void handleLeft(uint8_t number, uint8_t value);
		void handleRight(uint8_t number, uint8_t value);
		void clear();

};
#endif
