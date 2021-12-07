#include "FBPixel.h"  
#include "pin_map.h"
#include "np_conf.h"

namespace MD
{

FBPixel::FBPixel()
: m_np{new Adafruit_NeoPixel(T_PIXELS, NP_DATA, NEO_GRB + NEO_KHZ800)}
{
	m_np->setBrightness(kBrigthness);
	m_np->begin();
	m_np->clear();
}

void FBPixel::setTo(uint8_t pos, uint8_t value)
{
    m_np->setPixelColor(pos, kColors[value]);
		m_np->show();
}
	
} // namespace MD
