#include "MuxerPotsFactory.hpp"
#include "pin_map.h"
#include "pots_muxmap.h"

namespace MD
{
  MuxerPotsFactory::MuxerPotsFactory()
    : m_top4067{new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, TOP_POTMUX_SIG)},
      m_bottom4067{new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, BOTTOM_POTMUX_SIG)}
  {
    m_topMuxer = makeMuxerPots(m_top4067, topMuxpotsSet, nTopMuxpots);
    m_bottomMuxer = makeMuxerPots(m_bottom4067, bottomMuxpotsSet, nBottomMuxPots);
  }

  MuxerPots* MuxerPotsFactory::makeMuxerPots(Multiplexer4067* m, const uint8_t* muxPositions, const uint8_t totalPots)
  {
    return new MuxerPots(m, muxPositions, totalPots);
  }

  MuxerPots* MuxerPotsFactory::getBottomMuxer() 
  {
    return m_bottomMuxer;
  }

  MuxerPots* MuxerPotsFactory::getTopMuxer()
  {
    return m_topMuxer;
  }
  
} // namespace MD

