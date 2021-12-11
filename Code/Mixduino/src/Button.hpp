#pragma once

#include "Input.h"
#include "Output.h"
#include "Component.hpp"



namespace MD
{
  class Button : public Component
  {
  public:
    Button(Input* input, Output* output);
    Button() = default;
    void read(inCommand_t c) override;
    void setTo(int8_t value);
  protected:
    Input* m_input{nullptr};
    Output* m_output{nullptr};
  };
  
} // namespace MD
