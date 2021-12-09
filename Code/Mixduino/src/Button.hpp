#pragma once

#include "Input.h"
#include "Output.h"
#include "md_str.h"



namespace MD
{
  class Button
  {
  public:
    Button(Input* input, uint8_t inputPos, Output* output, uint8_t outputPos);
    Button() = default;
    void read(inCommand_t c);
    void setTo(int8_t value);
  protected:
    Input* m_input{nullptr};
    uint8_t m_inputPos{0};
    Output* m_output{nullptr};
    uint8_t m_outputPos{0};
  };
  
} // namespace MD
