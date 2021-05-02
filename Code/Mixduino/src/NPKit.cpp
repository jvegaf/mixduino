#include "NPKit.h"

const uint8_t BRIGHTNESS = 4;

uint32_t BLUE_COL   = Adafruit_NeoPixel::Color(0, 0, 255);
uint32_t GREEN_COL  = Adafruit_NeoPixel::Color(0, 255, 0);
uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 153, 51);
uint32_t RED_COL    = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t CLEAR_COL  = Adafruit_NeoPixel::Color(0, 0, 0);

// Range: -1 to 5 MAPED TO 0-6 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
uint32_t HCCols[] = {
    CLEAR_COL,
    YELLOW_COL, 
    ORANGE_COL,
    ORANGE_COL,
    RED_COL,
    BLUE_COL,
    GREEN_COL
};


NPKit::NPKit(uint8_t dataPin, uint8_t nPixels)
{
	adaPx.setPin(dataPin);
    adaPx.updateLength(nPixels);
    adaPx.updateType(NEO_GRB + NEO_KHZ800);
}

void NPKit::begin() 
{
    adaPx.begin();
    adaPx.show();
    adaPx.setBrightness(BRIGHTNESS);
}

void NPKit::handleON(uint8_t number, uint8_t value) 
{
    adaPx.setPixelColor(number, HCCols[value]); 
    adaPx.show();
}

void NPKit::handleOFF(uint8_t number) 
{
    adaPx.setPixelColor(number, CLEAR_COL);
    adaPx.show();
}


void NPKit::clear() 
{
    adaPx.clear();
    adaPx.show();
}