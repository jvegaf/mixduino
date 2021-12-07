#pragma once
#include "FBLed.h"

namespace MD
{
  class FBLedFactory
  {
  public:
    FBLedFactory();
    FBLed* getLeftFBLed();
    FBLed* getRightFBLed();
  private:
    FBLed* m_fbLeft {nullptr};
    FBLed* m_fbRight {nullptr};
  };
  
} // namespace MD
