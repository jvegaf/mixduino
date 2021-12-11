#include "FBPixel.h"  
#include "pin_map.h"
#include "np_conf.h"

namespace MD
{

FBPixel::FBPixel(const uint8_t outPos, Adafruit_NeoPixel* np)
: OutputBase(outPos), m_np{np}
{
}

void FBPixel::setTo(uint8_t value)
{
    m_np->setPixelColor(m_outPos, kColors[value]);
    m_np->show();
}
  
} // namespace MD
