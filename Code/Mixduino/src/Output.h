#pragma once

#include <Arduino.h>

namespace MD {

class Output 
{
  public:
    virtual void setTo(uint8_t value) = 0;
};

} // namespace MD
