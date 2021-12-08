#pragma once
#include "Container.hpp"
#include "Button.hpp"

namespace MD
{
  class ButtonMode : public Button
  {
  public:
    ButtonMode(Input* input, uint8_t inPos, Output* output, uint8_t outPos);
    void read(Container* container);
  };
  
} // namespace MD
