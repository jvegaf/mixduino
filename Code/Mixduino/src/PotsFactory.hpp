#pragma once

#include "Pot.hpp"
#include "MuxerPotsFactory.hpp"

namespace MD
{
  class PotsFactory
  {
  public:
    PotsFactory(MuxerPotsFactory* muxPotFact);
    Pot* getLeftTempoPot();
    Pot* getRightTempoPot();
    Pot* getMixerPots();
  private:
    Pot* m_leftTempoPot{nullptr};
    Pot* m_rightTempoPot{nullptr};
    Pot* m_mixerPots{nullptr};

    Pot* makeTempoPot(MuxerPots *muxer, uint8_t inputPos);
    Pot* makeMixerPots(MuxerPots *mxTop, const uint8_t* topPos, MuxerPots *mxBottom, const uint8_t* btmPos);
  };
  
} // namespace MD
