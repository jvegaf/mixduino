#pragma once

#include "Input.h"
#include "InputBase.hpp"
#include <Arduino.h>

namespace MD
{

  class InputMux: public Input, public InputBase
  {
  public:
    InputMux(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin);
    void read(inCommand_t c) override;

  protected:
    const uint8_t m_sigPin{0};
    const uint8_t* m_muxPins{nullptr};
    void setMuxChannel(const uint8_t channel);
    
  };  
} // namespace MD
