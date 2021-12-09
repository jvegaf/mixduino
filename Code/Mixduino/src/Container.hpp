#pragma once

#include <Arduino.h>

namespace MD
{
  class Container
  {
  public:
    virtual void changeMode()=0;
  };
} // namespace MD
