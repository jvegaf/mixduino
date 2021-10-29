#include "NPKit.h"

const uint8_t BRIGHTNESS = 32;

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
// uint32_t HCCols[] = {
//     CLEAR_COL,      // no hotcue
//     BLUE_COL,       // cue
//     ORANGE_COL,     // fade in
//     ORANGE_COL,     // fade out
//     YELLOW_COL,        // load
//     GRAY_COL,       // grid
//     GREEN_COL,       // loop
//     RED_COL,
//     PURPLE_COL
// };

NPKit::NPKit(uint8_t totalPix, uint8_t dataPin)
{
    _npx = new Adafruit_NeoPixel(totalPix, dataPin, NEO_GBR + NEO_KHZ800);
}

void NPKit::begin()
{
    _npx->begin();
    _npx->setBrightness(BRIGHTNESS);
    _npx->clear();
}

void NPKit::setTo(uint8_t pos, uint32_t color) {
	this->_npx->setPixelColor(pos, color);
    this->_npx->show();
}

void NPKit::clearAll() {
	this->_npx->clear();
}
