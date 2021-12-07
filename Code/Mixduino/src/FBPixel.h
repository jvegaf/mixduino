
#pragma once

#include "Output.h"
#include <Adafruit_NeoPixel.h>

namespace MD
{

class FBPixel : public Output
{
  private:
    Adafruit_NeoPixel* m_np;

  public:
    FBPixel();
    void setTo(uint8_t pos, uint8_t value) override;

};
} // namespace MD