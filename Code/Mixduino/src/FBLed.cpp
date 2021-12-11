#include "FBLed.h"  

namespace MD
{

FBLed::FBLed(const uint8_t outPos, Shifter* shf)
: OutputBase(outPos), m_shft{shf}
{

}

void FBLed::setTo(uint8_t value) {
  m_shft->setPin(m_outPos, value);
  m_shft->write();
}

} // namespace MD

