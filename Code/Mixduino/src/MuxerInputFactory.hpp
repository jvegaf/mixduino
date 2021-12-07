#pragma once

#include "Muxer.h"

namespace MD
{

class MuxerInputFactory
{
public:
  MuxerInputFactory();
  Muxer* getLeftMuxer();
  Muxer* getRightMuxer();
private:
  Muxer* m_leftMuxer{nullptr};
  Muxer* m_rightMuxer{nullptr};
};
  
} // namespace MD


