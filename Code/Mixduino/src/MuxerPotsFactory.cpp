#include "MuxerPotsFactory.hpp"
#include "pin_map.h"
#include "pots_muxmap.h"
MuxerPotsFactory::MuxerPotsFactory()
  : m_topMuxer{new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, TOP_POTMUX_SIG)},
    m_bottomMuxer{new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, BOTTOM_POTMUX_SIG)}
{
  
}

Multiplexer4067* MuxerPotsFactory::getBottomMuxer() 
{
  return m_bottomMuxer;
}

Multiplexer4067* MuxerPotsFactory::getTopMuxer()
{
  return m_topMuxer;
}