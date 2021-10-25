
#ifndef ARDUINO_NPIXEL_H
#define ARDUINO_NPIXEL_H
#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
class Npixel  
{
	private:
		uint8_t position;
		Adafruit_NeoPixel* np;

	public:
		Npixel(uint8_t pos);
		void setNPObject(Adafruit_NeoPixel aNp);
		void setColor(uint32_t color);
};
#endif
