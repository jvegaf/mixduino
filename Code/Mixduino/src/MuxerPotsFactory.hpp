#pragma once

#include "MuxerPots.hpp"

namespace MD
{

class MuxerPotsFactory
{
public:
  MuxerPotsFactory();
  MuxerPots* getTopMuxer();
  MuxerPots* getBottomMuxer();

private:
  Multiplexer4067* m_top4067 { nullptr };
  Multiplexer4067* m_bottom4067 { nullptr };
  MuxerPots* m_topMuxer{nullptr};
  MuxerPots* m_bottomMuxer{nullptr};

  MuxerPots* makeMuxerPots(Multiplexer4067* m, const uint8_t* muxPositions, const uint8_t totalPots);
};
  
} // namespace MD
