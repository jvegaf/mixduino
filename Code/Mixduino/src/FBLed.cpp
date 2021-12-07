#include "FBLed.h"  

namespace MD
{

FBLed::FBLed(Shifter* shf)
: m_shft{shf}
{

}

void FBLed::setTo(uint8_t pos, uint8_t value) {
  m_shft->setPin(pos, value);
  m_shft->write();
}

} // namespace MD

