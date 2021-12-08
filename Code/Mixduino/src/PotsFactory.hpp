#pragma once

#include "Pot.hpp"
#include "MuxerPotsFactory.hpp"

namespace MD
{
  class PotsFactory
  {
  public:
    PotsFactory(MuxerPotsFactory* muxPotFact);
  private:
    Pot* m_leftTempoPot{nullptr};
    Pot* m_rightTempoPot{nullptr};
    Pot* m_mixerPots{nullptr};

    Pot* makeTempoPot(MuxerPots *muxer);
    Pot* makeMixerPots(MuxerPots *mxTop, MuxerPots *mxBottom);
  };
  
} // namespace MD
