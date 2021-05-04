#include "NPKit.h"

const byte BRIGHTNESS = 8;

Adafruit_NeoPixel npLeft(10, NP_SIG_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel npRight(11, NP_SIG_RIGHT, NEO_GRB + NEO_KHZ800);

uint32_t CLEAR_COL  = npLeft.Color(0, 0, 0);
uint32_t BLUE_COL   = npLeft.Color(0, 0, 255);
uint32_t GREEN_COL  = npLeft.Color(0, 255, 0);
uint32_t RED_COL    = npLeft.Color(255, 0, 0);
uint32_t YELLOW_COL = npLeft.Color(255, 230, 0);
uint32_t ORANGE_COL = npLeft.Color(255, 143, 0);
uint32_t PURPLE_COL = npLeft.Color(243, 0, 255);
uint32_t GRAY_COL   = npLeft.Color(191, 201, 202);

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
uint32_t HCCols[] = {
    CLEAR_COL,      // no hotcue
    BLUE_COL,       // cue
    ORANGE_COL,     // fade in
    ORANGE_COL,     // fade out
    RED_COL,        // load
    GRAY_COL,       // grid
    GREEN_COL       // loop
};


void NPKit::begin() 
{
    npLeft.setBrightness(BRIGHTNESS);
    npRight.setBrightness(BRIGHTNESS);
    npLeft.begin();
    npRight.begin();
    npLeft.show();
    npRight.show();
}

void NPKit::handleON(byte number, byte value) 
{
    if (number < 10 )
    {
        npLeft.setPixelColor(number, HCCols[value]);
        npLeft.show();
        return;
    }
    number = number - 10;
    npRight.setPixelColor(number, HCCols[value]); 
    npRight.show();
}

void NPKit::handleOFF(byte number, byte value) 
{
    if (number < 10 )
    {
        npLeft.setPixelColor(number, CLEAR_COL);
        npLeft.show();
        return;
    }
    number = number - 10;
    npRight.setPixelColor(number, CLEAR_COL); 
    npRight.show();
}


void NPKit::clear() 
{
    npLeft.clear();
    npRight.clear();
    npLeft.show();
    npRight.show();
}