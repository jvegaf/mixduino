#include "Npixel.h"  

Npixel::Npixel(uint8_t pos)
{
	position = pos;
}

void Npixel::setNPObject(Adafruit_NeoPixel aNp) {
	np = aNp;
}

void Npixel::setColor(uint32_t color) {
	np->setPixelColor(position, color);
	np->show();
}


