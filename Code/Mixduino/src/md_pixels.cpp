#include "md_pixels.hpp"
#include "np_map.h"
#include "pin_map.h"
#include "md_colors.h"
#include <Adafruit_NeoPixel.h>


namespace MDPixels
{
    
Adafruit_NeoPixel np(MDColor::t_pixels, NP_DATA, NEO_GRB + NEO_KHZ800);

void initialize() 
{
    np.setBrightness(MDColor::BRIGHTNESS);
    np.begin();
    np.clear();
}

void changePixel(uint8_t position, uint32_t color) 
{
    np.setPixelColor(position, color); 
    np.show();
}

void changeRange(uint8_t position, uint8_t t_pixels, uint32_t color) {
    for (size_t i = 0 ; i < t_pixels; i++)
    {
        np.setPixelColor(position + i, color);
    }
    np.show();
}

} // namespace MDPixels