#include "md_pixels.hpp"
#include "md_colors.h"
#include "pin_map.h"
#include <Adafruit_NeoPixel.h>


namespace MDPixels
{
    
Adafruit_NeoPixel np(t_pixels, NP_DATA, NEO_GRB + NEO_KHZ800);

const uint8_t BRIGHTNESS = 32;

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
const uint32_t HCCols[] = {
    CLEAR_COL,      // no hotcue
    BLUE_COL,       // cue
    ORANGE_COL,     // fade in
    ORANGE_COL,     // fade out
    YELLOW_COL,        // load
    GRAY_COL,       // grid
    GREEN_COL,       // loop
    RED_COL,
    PURPLE_COL
};

void initialize() 
{
    np.setBrightness(BRIGHTNESS);
    np.begin();
    np.clear();
}

void changePixel(uint8_t position, uint8_t value) 
{
    np.setPixelColor(position, HCCols[value]); 
    np.show();
}

void changeRange(uint8_t position, uint8_t t_pixels, uint8_t value) {
    for (size_t i = 0 ; i < t_pixels; i++)
    {
        np.setPixelColor(position + i, HCCols[value]);
    }
    np.show();
}

} // namespace MDPixels