#include "np_kit.h"

NPKit::NPKit(uint8_t totalPix, uint8_t dataPin, uint8_t brightness)
{
	_npx = new Adafruit_NeoPixel(totalPix, dataPin, NEO_GBR + NEO_KHZ800);
    _brightness = brightness;
}

void NPKit::begin()
{
    _npx->begin();
    _npx->setBrightness(this->_brightness);
    _npx->clear();
}

void NPKit::setTo(OutDTO od) {
	_npx->setPixelColor(od.position, od.color);
    _npx->show();
}

void NPKit::clearAll() {
	this->_npx->clear();
}

