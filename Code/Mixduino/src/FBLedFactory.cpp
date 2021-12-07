#include "FBLedFactory.hpp"
#include "Shifter.h"
#include "pin_map.h"
namespace MD
{

  FBLedFactory::FBLedFactory()
    : m_fbLeft{new FBLed(new Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1))},
      m_fbRight{new FBLed(new Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1))}
  {
  }

  FBLed* FBLedFactory::getLeftFBLed()
  {
    return m_fbLeft;
  }

  FBLed* FBLedFactory::getRightFBLed()
  {
    return m_fbRight;
  }



} // namespace MD
