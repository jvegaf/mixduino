#include "Button.hpp"

namespace MD
{
  Button::Button(Input* input, Output* output)
  : m_input {input},  
  m_output {output}
  {

  }

  void Button::read(inCommand_t c)
  {
    m_input->read(c);
  }

  void Button::setTo(int8_t value)
  {
    if (m_output == nullptr) return;
    m_output->setTo(value);
  }
} // namespace MD
