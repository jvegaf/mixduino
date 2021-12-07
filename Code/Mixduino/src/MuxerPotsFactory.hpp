#pragma once

#include "Multiplexer4067.h"

class MuxerPotsFactory
{
public:
  MuxerPotsFactory();
  Multiplexer4067* getTopMuxer();
  Multiplexer4067* getBottomMuxer();
private:
  Multiplexer4067* m_topMuxer { nullptr };
  Multiplexer4067* m_bottomMuxer { nullptr };
};
