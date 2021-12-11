#pragma once

#include "Input.h"
#include "InputAnalogBase.hpp"

namespace MD
{
  class InputAnalogMux : public Input, public InputAnalogBase
  {
  public:
    InputAnalogMux(const uint8_t inPos, const uint8_t* muxPins, const uint8_t sigPin);
    void read(inCommand_t c) override;
  private:
    const uint8_t* m_muxPins{nullptr};
    const uint8_t m_sigPin{0};
    uint16_t m_cState{0}; // current state
    uint16_t m_pState{0}; // previous state
    uint16_t m_lastCcValue{0};
    uint32_t m_pTime{0};

    void setMuxChannel(const uint8_t channel);

  };
} // namespace MD
