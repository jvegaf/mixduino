
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pin_map.h"
#include "np_map.h"

class NPKit  
{
	private:
		Adafruit_NeoPixel* _npx;
	public:
		NPKit();
		void begin();
		Adafruit_NeoPixel getNPX();
};
#endif
