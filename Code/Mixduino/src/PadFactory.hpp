#pragma once

#include "Pad.hpp"
#include "ButtonFactory.hpp"

namespace MD
{
  class PadFactory
  {
  public:
    PadFactory(ButtonFactory* bFactory);
    Pad* getLeftPad();
    Pad* getRightPad();
  private:
    Pad* m_leftPad{nullptr};
    Pad* m_rightPad{nullptr};
  };
  
} // namespace MD
