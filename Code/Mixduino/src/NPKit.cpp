#include "NPKit.h"

const uint8_t BRIGHTNESS = 4;

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