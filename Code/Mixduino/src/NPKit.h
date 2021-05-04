
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "pin_map.h"

class NPKit  
{
	private:

	public:
		void clear();
		void begin();
		void handleON(byte number, byte value);
		void handleOFF(byte number, byte value);
};
#endif
