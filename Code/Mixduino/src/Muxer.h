#pragma once
#include "md_str.h"
#include "Input.h"
#include "Container.hpp"

namespace MD
{
  class Muxer : public Input
  {

  public:
    Muxer(const uint8_t* mxPins, uint8_t sigPin, const uint8_t* swPositions, const uint8_t totalSw);
    void read(inMidip_t p) override;
    void read(uint8_t inPos, Container* container) override;

  protected:
    const uint8_t m_sigPin{0};
    const uint8_t* m_mxPins { nullptr };
    const uint8_t* m_Positions { nullptr };
    const uint8_t m_tPositions { 0 };
    uint16_t* m_pState { nullptr };
    uint16_t* m_cState { nullptr };

    uint32_t* m_lastdebouncetime;
    
    void setMuxChannel(uint8_t channel);
  };
} // namespace MD

