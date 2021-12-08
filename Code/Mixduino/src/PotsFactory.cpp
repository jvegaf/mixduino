#include "PotsFactory.hpp"
#include "pots_muxmap.h"

namespace MD
{

  PotsFactory::PotsFactory(MuxerPotsFactory* muxPotFact)
  {
    auto muxTop = muxPotFact->getTopMuxer();
    auto muxBtm = muxPotFact->getBottomMuxer();
    m_leftTempoPot = makeTempoPot(muxBtm);
    m_rightTempoPot = makeTempoPot(muxBtm);
    m_mixerPots = makeMixerPots(muxTop, muxBtm);
  }

  Pot* PotsFactory::makeMixerPots(MuxerPots *mxTop, MuxerPots *mxBottom) {
    auto mixerPots = new Pot[tMixerMuxPots];
    for (uint8_t i = 0; i < tMuxTopMixerPots; i++)
    {
      mixerPots[i] = Pot(mxTop);
    }
    for (uint8_t i = tMuxTopMixerPots; i < tMixerMuxPots; i++)
    {
      mixerPots[i] = Pot(mxBottom);
    }
    
    return mixerPots;
  }

  Pot* PotsFactory::makeTempoPot(MuxerPots *muxer) {
    return new Pot(muxer);
  }



  
} // namespace MD
