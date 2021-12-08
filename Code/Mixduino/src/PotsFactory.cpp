#include "PotsFactory.hpp"
#include "pots_muxmap.h"

namespace MD
{

  PotsFactory::PotsFactory(MuxerPotsFactory* muxPotFact)
  {
    auto muxTop = muxPotFact->getTopMuxer();
    auto muxBtm = muxPotFact->getBottomMuxer();
    m_leftTempoPot = makeTempoPot(muxBtm, PITCH_L);
    m_rightTempoPot = makeTempoPot(muxBtm, PITCH_R);
    m_mixerPots = makeMixerPots(muxTop, muxTopMixerPots, muxBtm, muxBtmMixerPots);
  }

  Pot* PotsFactory::getLeftTempoPot() {
    return m_leftTempoPot;
  }

  Pot* PotsFactory::getRightTempoPot() {
    return m_rightTempoPot;
  }

  Pot* PotsFactory::getMixerPots() {
    return m_mixerPots;
  }



  Pot* PotsFactory::makeMixerPots(MuxerPots *mxTop, const uint8_t* topPos, MuxerPots *mxBottom, const uint8_t* btmPos) {
    auto mixerPots = new Pot[tMixerMuxPots];
    for (uint8_t i = 0; i < tMuxTopMixerPots; i++)
    {
      mixerPots[i] = Pot(mxTop, topPos[i]);
    }
    for (uint8_t i = 0; i < tMuxBtmMixerPots; i++)
    {
      mixerPots[tMuxTopMixerPots + i] = Pot(mxBottom, btmPos[i]);
    }
    
    return mixerPots;
  }

  Pot* PotsFactory::makeTempoPot(MuxerPots *muxer, uint8_t inputPos) {
    return new Pot(muxer, inputPos);
  }



  
} // namespace MD
