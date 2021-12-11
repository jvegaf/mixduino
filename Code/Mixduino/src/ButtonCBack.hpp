#pragma once
#include "Button.hpp"

namespace MD
{
  class ButtonCBack : public Button
  {
  public:
    ButtonCBack(Input* input, Output* output, const uint8_t cType);
    void read(void(*cbFunc)(uint8_t));
  private:
    const uint8_t m_cType;
  };
  
} // namespace MD
