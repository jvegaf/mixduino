#pragma once
#include "Container.hpp"
#include "Button.hpp"

namespace MD
{
  class ButtonMode : public Button
  {
  public:
    ButtonMode(Input* input, Output* output);
    void read(uint8_t inPos, Container* container);
  };
  
} // namespace MD
