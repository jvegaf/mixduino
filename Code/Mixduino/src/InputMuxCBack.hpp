#pragma once
#include "InputMux.hpp"

namespace MD
{
  class InputMuxCBack : public InputMux
  {
  public:
    InputMuxCBack(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin);
    void read(void(*cbFunc)(uint8_t), const uint8_t cType);

  };
  
} // namespace MD
