#include "Npixel.h"  

Npixel::Npixel(uint8_t pos)
{
	position = pos;
}

void Npixel::setNPObject(Adafruit_NeoPixel *aNp) {
	np = aNp;
}

void Npixel::setTo(uint32_t state) {
	np->setPixelColor(position, state);
	np->show();
}


