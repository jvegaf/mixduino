#pragma once

#include "Output.h"
#include "OutputBase.hpp"
#include <Shifter.h>

namespace MD
{

class FBLed : public Output, public OutputBase
{
  public:
    FBLed(const uint8_t outPos, Shifter* shf);
    void setTo(uint8_t value) override;

  private:
    Shifter* m_shft;
};
  
} // namespace MD