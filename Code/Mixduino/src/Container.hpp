#pragma once

#include <Arduino.h>

namespace MD
{
  class Container
  {
  public:
    Container();
    virtual void changeMode()=0;
  };
} // namespace MD
