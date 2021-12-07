#include "ButtonMode.hpp"

namespace MD
{

  ButtonMode::ButtonMode(Input* input, Output* output)
    : Button(input, output)
  {
  }

  void ButtonMode::read(uint8_t inPos, Container* container)
  {
    m_input->read(inPos, container);
  }
  
} // namespace MD
