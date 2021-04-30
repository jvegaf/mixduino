#include "NPKit.h"

const uint8_t BRIGHTNESS = 16;

// LEDS AMOUNT
const uint8_t NUMPX_L = 10;
const uint8_t NUMPX_R = 11;

Adafruit_NeoPixel leftNP(NUMPX_L, NP_SIG_LEFT, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel rightNP(NUMPX_R, NP_SIG_RIGHT, NEO_GRB + NEO_KHZ800);

uint32_t BLUE = Adafruit_NeoPixel::Color(0, 0, 255);
uint32_t GREEN = Adafruit_NeoPixel::Color(0, 255, 0);
uint32_t YELLOW = Adafruit_NeoPixel::Color(255, 230, 0);
uint32_t ORANGE = Adafruit_NeoPixel::Color(255, 153, 51);
uint32_t RED = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t CLEAR = Adafruit_NeoPixel::Color(0, 0, 0);


uint32_t colors[] = {
    CLEAR,
    YELLOW,
    ORANGE,
    RED,
    BLUE,
    GREEN
};

///////////////////////////////////////////////////
// HOT CUE COLORS
// Range: -1 to 5 MAPED TO 0-6 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
uint32_t HCCols[] = {
    CLEAR,
    YELLOW, 
    ORANGE,
    ORANGE,
    RED,
    BLUE,
    GREEN
};


void NPKit::begin() 
{
    leftNP.begin();
    leftNP.show();
    leftNP.setBrightness(BRIGHTNESS); // 0 - 255
}

void NPKit::handleLeft(uint8_t number, uint8_t value) 
{
    leftNP.setPixelColor(number, colors[number]);
    leftNP.show();
}

void NPKit::handleRight(uint8_t number, uint8_t value) 
{
    rightNP.setPixelColor(number, colors[number]);
    rightNP.show();
}

void NPKit::clear()
{
    leftNP.clear();
    rightNP.clear();
}
