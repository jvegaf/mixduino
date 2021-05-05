
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pin_map.h"
#include <Npixel.h>

class NPKit  
{
	private:
		Adafruit_NeoPixel np;
	public:
		NPKit(byte dataPin, byte nPixels);
		void begin();
		void clear();
		void handleChange(Npixel npx);
};
#endif
