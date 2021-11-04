#include "NPKit.h"

const uint8_t NP_BRIGHTNESS = 32;

uint32_t const CLEAR_COL = Adafruit_NeoPixel::Color(0, 0, 0);
uint32_t const BLUE_COL = Adafruit_NeoPixel::Color(0, 0, 255);
uint32_t const GREEN_COL = Adafruit_NeoPixel::Color(0, 255, 0);
uint32_t const RED_COL = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t const YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
uint32_t const ORANGE_COL = Adafruit_NeoPixel::Color(255, 143, 0);
uint32_t const PURPLE_COL = Adafruit_NeoPixel::Color(243, 0, 255);
uint32_t const GRAY_COL = Adafruit_NeoPixel::Color(128, 128, 128);
uint32_t const MAGENTA_COL = Adafruit_NeoPixel::Color(255, 0, 255);
uint32_t const MAROON_COL = Adafruit_NeoPixel::Color(128, 0, 0);

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
uint32_t const HCCols[] = {
    CLEAR_COL,  // no hotcue
    BLUE_COL,   // cue
    ORANGE_COL, // fade in/out
    YELLOW_COL, // load
    GRAY_COL,   // grid
    GREEN_COL,  // loop
    RED_COL,
    PURPLE_COL,
    MAGENTA_COL,
    MAROON_COL};

NPKit::NPKit(uint8_t dataPin, uint8_t nPixels)
{
    _np = new Adafruit_NeoPixel(nPixels, dataPin, NEO_GRB + NEO_KHZ800);
}

void NPKit::begin()
{
    _np->setBrightness(NP_BRIGHTNESS);
    _np->begin();
    _np->clear();
}

void NPKit::handleChange(uint8_t pos, uint8_t value)
{
    _np->setPixelColor(pos, HCCols[value]);
    _np->show();
}

void NPKit::allOFF()
{
    _np->clear();
}