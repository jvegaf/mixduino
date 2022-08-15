#include "md_feedback.hpp"

#include "vumeters.hpp"
#include "md_pixels.hpp"
#include "components_def.h"

#include "md_leds_map.hpp"
#include "np_map.h"



namespace MDFeedback
{
    
void initialize()
{
    VUmeters::initialize();
    MDPixels::initialize();
}

void setVuValue(uint8_t number, uint8_t value)
{
    VUmeters::setLevel(number, value);
}

void setLedValue(uint8_t component, uint8_t value)
{
    for (size_t i = 0; i < t_leds; i++)
    {
      if (comp_leds[i] != component) { continue; }
      leds_group[i].updateValue(value);
    }
}

void setPixel(uint8_t number, uint8_t color)
{
    MDPixels::changePixel(number, color);
}

void changePad(Location loc, uint32_t mode_c){

    if(loc == Location::Left) {
        MDPixels::changeRange(NP_PADL1, 8, mode_c);
        return;
    }
    MDPixels::changeRange(NP_PADR1, 8, mode_c);
}

void changePads(Location loc, uint32_t* colors){
    if(loc == Location::Left) {
        for (size_t i = 0; i < t_pads; i++)
        {
            MDPixels::changePixel(NP_PADL1 + i, colors[i]);
        }
        return;
    }
    for (size_t i = 0; i < t_pads; i++)
    {
        MDPixels::changePixel(NP_PADR1 + i, colors[i]);
    }
}


} // namespace MDFeedback



