#pragma once

#include <Arduino.h>

namespace MD
{
  class InputAnalogBase
  {
  public:
    InputAnalogBase(uint8_t inputPos)
      : m_inPos{inputPos}
    {
      
    }
  protected:
    const uint8_t m_inPos{0};
    uint16_t m_pState{0}; // previous state
    uint16_t m_lastCcValue{0};
    uint32_t m_pTime{0};
  };
  
} // namespace MD
