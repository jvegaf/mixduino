#pragma once
#include "md_str.h"
#include "pin_map.h"
#include "sw_muxmap.h"
#include "pots_muxmap.h"

namespace mixduino
{
  muxreqs_t topMPotsReqs = { kMuxPinsBndl, S_TOP_MUXPOTS, kTopMuxpotsSet, ktTopMuxpots };

  muxreqs_t btMPotsReqs = { kMuxPinsBndl, S_BOTTOM_MUXPOTS, kBottomMuxpotsSet, ktBottomMuxPots };

  muxreqs_t lMBtnsReqs = { kMuxPinsBndl, S_LEFT_BTNS, SwMuxLeftSet, nSwMuxLeft };

  muxreqs_t rMBtnsReqs = { kMuxPinsBndl, S_RIGH_BTNS, SWMuxRightSet, nSwMuxRight};

} // namespace mixduino

