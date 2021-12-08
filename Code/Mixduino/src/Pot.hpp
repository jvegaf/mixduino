#pragma once

#include "MuxerPots.hpp"

namespace MD
{
  class Pot
  {
  public:
    Pot(InputPot* input, uint8_t inputPos);
    Pot() = default;
    void read(inPotMidip_t p);
  private:
    InputPot* m_input{nullptr};
    uint8_t m_inputPos{0};
  };
  
} // namespace MD
