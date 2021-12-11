
#pragma once

#include "Output.h"
#include "OutputBase.hpp"
#include <Adafruit_NeoPixel.h>

namespace MD
{

class FBPixel : public Output, public OutputBase
{
  private:
    Adafruit_NeoPixel* m_np;

  public:
    FBPixel(const uint8_t outPos, Adafruit_NeoPixel* np);
    void setTo(uint8_t value) override;

};
} // namespace MD