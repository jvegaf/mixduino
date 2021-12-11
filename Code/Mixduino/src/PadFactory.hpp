#pragma once

#include "Pad.hpp"
#include "InputFactory.hpp"
#include "OutputFactory.hpp"

namespace MD
{
  class PadFactory
  {
  public:
    PadFactory(InputFactory* inFact, OutputFactory* outFact);
    Pad* getLeftPad();
    Pad* getRightPad();
  private:
    Pad* m_leftPad{nullptr};
    Pad* m_rightPad{nullptr};
    Pad* makePad(Input** ins, Output** outs, uint8_t cType);

  };
  
} // namespace MD
