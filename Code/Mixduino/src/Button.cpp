#include "Button.hpp"

namespace MD
{
  Button::Button(Input* input, uint8_t inputPos, Output* output, uint8_t outputPos)
  : m_input {input}, m_inputPos{inputPos}, m_output {output}, m_outputPos{outputPos}
  {

  }

  void Button::read(inMidip_t p)
  {
    p.inputPos = m_inputPos;
    m_input->read(p);
  }

  void Button::setTo(int8_t value)
  {
    if (m_output == nullptr) return;
    m_output->setTo(m_outputPos, value);
  }
} // namespace MD
