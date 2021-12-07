#pragma once

#include "Output.h"
#include <Shifter.h>

namespace MD
{

class FBLed : public Output
{
  public:
    FBLed(Shifter* shf);
    FBLed() = default;
    void setTo(uint8_t pos, uint8_t value);

  private:
    Shifter* m_shft;
};
  
} // namespace MD