#pragma once

#include "Input.h"
#include "Output.h"


namespace MD
{
  class Button
  {
  public:
    Button(Input* input, Output* output);
    Button() = default;
    void read(inCommand_t c);
    void setTo(int8_t value);
  protected:
    Input* m_input{nullptr};
    Output* m_output{nullptr};
  };
  
} // namespace MD
