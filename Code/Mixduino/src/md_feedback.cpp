#include "md_feedback.hpp"
#include "vumeters.hpp"

#include "md_leds.hpp"

#include "md_pixels.hpp"
#include "pin_map.h"
#include "np_map.h"

namespace MDFeedback
{
    
void initialize()
{
    VUmeters::initialize();
    MDPixels::initialize();
}

void onCChange(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case 12: // VU
        VUmeters::setLevel(number, value);
        break;
    case 14: // NPixels
        MDPixels::changePixel(number, value);
        break;

    default:
        break;
    }
}

void onNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
    MDLeds::setValue(number, value);
}

void changePad(Location loc, uint32_t color){
    if(loc == Location::Left) {
        MDPixels::changeRange(NP_PADL1, 8, color);
        return;
    }
    MDPixels::changeRange(NP_PADR1, 8, color);
}


} // namespace MDFeedback



