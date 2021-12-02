#pragma once
#include "board.h"
#include <Arduino.h>

namespace mixduino
{
  const uint16_t leftMuxBtnEvents[] = {
    Board::Event::evDeckBMonCue,
    Board::Event::evDeckAMonCue,
    Board::Event::evShift,
    Board::Event::evLeftLoop,
    Board::Event::evLeftSync,
    Board::Event::evLeftMode,
    Board::Event::evLeftPlay,
    Board::Event::evLeftCue,
    Board::Event::evLeftPad8,
    Board::Event::evLeftPad4,
    Board::Event::evLeftPad7,
    Board::Event::evLeftPad3,
    Board::Event::evLeftPad2,
    Board::Event::evLeftPad6,
    Board::Event::evLeftPad1,
    Board::Event::evLeftPad5
  };

  const uint16_t rightMuxBtnEvents[] = {
    Board::Event::evRightCue,
    Board::Event::evRightPlay,
    Board::Event::evRightMode,
    Board::Event::evRightLoop,
    Board::Event::evDeckCMonCue,
    Board::Event::evRightSync,
    Board::Event::evSwitchDeck,
    Board::Event::evRightPad8,
    Board::Event::evRightPad4,
    Board::Event::evRightPad7,
    Board::Event::evRightPad3,
    Board::Event::evRightPad2,
    Board::Event::evRightPad6,
    Board::Event::evRightPad1,
    Board::Event::evRightPad5
  };

  const uint16_t topMuxPotsEvents[] = {
    Board::Event::evFx1Pot1,
    Board::Event::evFx1Pot2,
    Board::Event::evFx1Pot3,
    Board::Event::evDeckAGain,
    Board::Event::evDeckBGain,
    Board::Event::evDeckCGain,
    Board::Event::evFx2Pot2,
    Board::Event::evFx2Pot3,
    Board::Event::evDeckATreb,
    Board::Event::evDeckBTreb,
    Board::Event::evDeckCTreb
  };

  const uint16_t bottomMuxPotsEvents[] = {
    Board::Event::evDeckBVolume,
    Board::Event::evDeckAVolume,
    Board::Event::evRightTempo,
    Board::Event::evDeckCFiltr,
    Board::Event::evMonitorVol,
    Board::Event::evDeckABas,
    Board::Event::evDeckAMid,
    Board::Event::evDeckBBas,
    Board::Event::evDeckBMid,
    Board::Event::evDeckCMid,
    Board::Event::evDeckCBas,
    Board::Event::evDeckBFiltr,
    Board::Event::evDeckAFiltr,
    Board::Event::evLeftTempo,
    Board::Event::evMonitorMix,
    Board::Event::evDeckCVolume
  };

  const uint16_t buttonsEvents[] = {
    Board::Event::evFx2Btn2,
    Board::Event::evFx2Btn3,
    Board::Event::evFx1Btn1,
    Board::Event::evBrwsRightBtn,
    Board::Event::evBrwsLeftBtn,
    Board::Event::evFx1Btn2,
    Board::Event::evFx1Btn3,
    Board::Event::evFx2Btn1,
    Board::Event::evBrwsPrevBtn,
    Board::Event::evBrwsBackBtn
  };

  const uint16_t potsEvents[] = {
    Board::Event::evFx2Pot1,
    Board::Event::evMasterVol
  };
} // namespace mixduino
