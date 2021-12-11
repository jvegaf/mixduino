#pragma once

#include <Arduino.h>

namespace MD
{
  class OutputBase
  {
  public:
    OutputBase(const uint8_t outPos)
    : m_outPos{outPos}
    {
      
    }

  protected:
    const uint8_t m_outPos;
  };
  
} // namespace MD
