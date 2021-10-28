
#ifndef ARDUINO_NPIXEL_H
#define ARDUINO_NPIXEL_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include <OutputBase.h>
class Npixel : public OutputBase
{
	private:
		uint8_t position;
		Adafruit_NeoPixel *np;

	public:
		Npixel(uint8_t pos);
		void setNPObject(Adafruit_NeoPixel *aNp);
		void setTo(uint32_t state);
};
#endif
