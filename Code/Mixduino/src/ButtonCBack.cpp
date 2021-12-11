#include "ButtonCBack.hpp"
#include "InputMuxCBack.hpp"

namespace MD
{

  ButtonCBack::ButtonCBack(Input* input, Output* output, const uint8_t cType)
    : Button(input, output), m_cType{cType}
  {
  }

  void ButtonCBack::read(void(*cbFunc)(uint8_t)) {
    InputMuxCBack* in = static_cast<InputMuxCBack*>(m_input);
    in->read(cbFunc, m_cType);
  }


  
} // namespace MD
