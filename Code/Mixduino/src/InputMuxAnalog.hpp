#pragma once

#include "InputMux.hpp"

namespace MD
{
  class InputAnalogMux : public InputMux
  {
  public:
    InputAnalogMux(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin);
    void read(inCommand_t c) override;
  private:
    uint16_t m_cState{0}; // current state
    uint16_t m_pState{0}; // previous state
    uint16_t m_lastCcValue{0};
    uint32_t m_pTime{0};

  };
} // namespace MD
