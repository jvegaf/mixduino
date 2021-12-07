#pragma once

#include "Input.h"
#include "Output.h"
#include "md_str.h"



namespace MD
{
  class Button
  {
  public:
    Button(Input* input, Output* output);
    Button() = default;
    void read(inMidip_t p);
    void setTo(uint8_t pos, int8_t value);
  protected:
    Input* m_input{nullptr};
    Output* m_output{nullptr};
  };
  
} // namespace MD
