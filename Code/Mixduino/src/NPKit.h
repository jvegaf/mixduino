
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "md_pinmap.h"
#include "feedback.h"

class NPKit  
{
	private:
		Adafruit_NeoPixel* _npx;
	public:
		NPKit();
		void begin();
		Adafruit_NeoPixel* getNPX();
};
#endif
