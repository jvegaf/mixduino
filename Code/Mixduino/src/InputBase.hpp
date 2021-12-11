#pragma once
#include <Arduino.h>


namespace MD
{
  class InputBase
  {
  public:
    InputBase(const uint8_t inPos)
      : m_inPos{inPos}
    {
      
    }
  protected:
    const uint8_t m_inPos{0};
    uint16_t m_pState{0};
    uint32_t m_lastdebouncetime{0};
  };
  
} // namespace MD
