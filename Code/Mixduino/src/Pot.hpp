#pragma once

#include "MuxerPots.hpp"

namespace MD
{
  class Pot
  {
  public:
    Pot(InputPot* input);
    Pot() = default;
    void read(inPotMidip_t p);
  private:
    InputPot* m_input{nullptr};
  };
  
} // namespace MD
