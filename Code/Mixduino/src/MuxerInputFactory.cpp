#include "MuxerInputFactory.hpp"
#include "pin_map.h"
#include "sw_muxmap.h"

namespace MD
{

MuxerInputFactory::MuxerInputFactory()
  : m_leftMuxer{new Muxer(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, MUX_SW_BND_L, T_MUX_SW_BND_L)},
    m_rightMuxer{new Muxer(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, MUX_SW_BND_R, T_MUX_SW_BND_R)}
{
  
}

Muxer* MuxerInputFactory::getLeftMuxer() {
  return m_leftMuxer;
}

Muxer* MuxerInputFactory::getRightMuxer() {
  return m_rightMuxer;
}
  
} // namespace MD




