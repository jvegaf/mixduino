#include "NPKit.h"

const byte BRIGHTNESS = 32;

uint32_t CLEAR_COL  = Adafruit_NeoPixel::Color(0, 0, 0);
uint32_t BLUE_COL   = Adafruit_NeoPixel::Color(0, 0, 255);
uint32_t GREEN_COL  = Adafruit_NeoPixel::Color(0, 255, 0);
uint32_t RED_COL    = Adafruit_NeoPixel::Color(255, 0, 0);
uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 143, 0);
uint32_t PURPLE_COL = Adafruit_NeoPixel::Color(243, 0, 255);
uint32_t GRAY_COL   = Adafruit_NeoPixel::Color(191, 201, 202);

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
uint32_t HCCols[] = {
    CLEAR_COL,      // no hotcue
    BLUE_COL,       // cue
    ORANGE_COL,     // fade in
    ORANGE_COL,     // fade out
    YELLOW_COL,        // load
    GRAY_COL,       // grid
    GREEN_COL       // loop
};

NPKit::NPKit(byte dataPin, byte nPixels)
{
	np = Adafruit_NeoPixel(nPixels, dataPin, NEO_GRB + NEO_KHZ800);
}

void NPKit::begin() 
{
    np.setBrightness(BRIGHTNESS);
    np.begin();
    np.clear();
}

void NPKit::handleChange(Npixel npx) 
{
    np.setPixelColor(npx.position(), HCCols[npx.value()]); 
    np.show();
}

void NPKit::clear() 
{
    np.clear();
    np.show();
}