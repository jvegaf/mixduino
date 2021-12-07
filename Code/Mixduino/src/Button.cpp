#include "Button.hpp"

namespace MD
{
  Button::Button(Input* input, Output* output)
  : m_input {input}, m_output {output}
  {

  }

  void Button::read(inMidip_t p)
  {
    m_input->read(p);
  }

  void Button::setTo(uint8_t pos, int8_t value)
  {
    if (m_output == nullptr) return;
    m_output->setTo(pos, value);
  }
} // namespace MD
