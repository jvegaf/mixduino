#pragma once
#include <Multiplexer4067.h>
#include "md_str.h"
#include "Input.h"

namespace MD
{
  class MuxerPots : public InputPot
  {
  public:
    MuxerPots(Multiplexer4067* muxer, const uint8_t* muxPositions, const uint8_t totalPots);
    void read(inPotMidip_t p) override;
    
  private:
    Multiplexer4067* m_muxer{nullptr};
    const uint8_t* m_muxPositions{nullptr};
    const uint8_t m_totalPots{0};
    uint16_t* m_cState{nullptr}; // current state
    uint16_t* m_pState{nullptr}; // previous state
    uint16_t* m_lastCcValue{nullptr};
    uint32_t* m_pTime{nullptr};
  };

} // namespace MD
