#include "ButtonMode.hpp"

namespace MD
{

  ButtonMode::ButtonMode(Input* input, uint8_t inPos, Output* output, uint8_t outPos)
    : Button(input, inPos, output, outPos)
  {
  }

  void ButtonMode::read(Container* container) {
    m_input->read(m_inputPos, container);
  }


  
} // namespace MD
