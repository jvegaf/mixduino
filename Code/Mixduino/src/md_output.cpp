#include "md_output.hpp"
#include "vumeters.hpp"

#include "md_leds.hpp"

#include <Npixel.h>
#include <Align.h>
#include "md_pixels.hpp"
#include "pin_map.h"
#include "np_map.h"

namespace MDOutput
{
    
void initialize()
{
    VUmeters::initialize();
    MDPixels::initialize();
}

void cChange(uint8_t channel, uint8_t number, uint8_t value)
{
    switch (channel)
    {
    case 12: // VU
        VUmeters::setLevel(number, value);
        break;
    case 14: // NPixels
        MDPixels::handleChange(number, value);
        break;

    default:
        break;
    }
}

void noteOn(uint8_t channel, uint8_t number, uint8_t value)
{
    MDLeds::setValue(number, value);
}


} // namespace MDOutput



