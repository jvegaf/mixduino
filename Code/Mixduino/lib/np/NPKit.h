
#ifndef ARDUINO_NPKIT_H
#define ARDUINO_NPKIT_H
#include <Arduino.h>
#include <OutputBase.h>
#include <Adafruit_NeoPixel.h>
#include "feedback.h"

class NPKit : public OutputBase 
{
	private:
		Adafruit_NeoPixel* _npx;
	public:
		NPKit(uint8_t totalPix, uint8_t dataPin);
		void begin();
		void setTo(uint8_t output_pos, uint32_t color);
		void clearAll();
};
#endif
