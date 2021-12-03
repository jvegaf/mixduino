#pragma once
#include "board.h"
#include <Arduino.h>

namespace mixduino
{
  const uint16_t leftMuxBtnEvents[] = {
    Board::Event::DeckBMonCue,
    Board::Event::DeckAMonCue,
    Board::Event::Shift,
    Board::Event::LeftLoop,
    Board::Event::LeftSync,
    Board::Event::LeftMode,
    Board::Event::LeftPlay,
    Board::Event::LeftCue,
    Board::Event::LeftPad8,
    Board::Event::LeftPad4,
    Board::Event::LeftPad7,
    Board::Event::LeftPad3,
    Board::Event::LeftPad2,
    Board::Event::LeftPad6,
    Board::Event::LeftPad1,
    Board::Event::LeftPad5
  };

  const uint16_t rightMuxBtnEvents[] = {
    Board::Event::RightCue,
    Board::Event::RightPlay,
    Board::Event::RightMode,
    Board::Event::RightLoop,
    Board::Event::DeckCMonCue,
    Board::Event::RightSync,
    Board::Event::SwitchDeck,
    Board::Event::RightPad8,
    Board::Event::RightPad4,
    Board::Event::RightPad7,
    Board::Event::RightPad3,
    Board::Event::RightPad2,
    Board::Event::RightPad6,
    Board::Event::RightPad1,
    Board::Event::RightPad5
  };

  const uint16_t topMuxPotsEvents[] = {
    Board::Event::Fx1Pot1,
    Board::Event::Fx1Pot2,
    Board::Event::Fx1Pot3,
    Board::Event::DeckAGain,
    Board::Event::DeckBGain,
    Board::Event::DeckCGain,
    Board::Event::Fx2Pot2,
    Board::Event::Fx2Pot3,
    Board::Event::DeckATreb,
    Board::Event::DeckBTreb,
    Board::Event::DeckCTreb
  };

  const uint16_t bottomMuxPotsEvents[] = {
    Board::Event::DeckBVolume,
    Board::Event::DeckAVolume,
    Board::Event::RightTempo,
    Board::Event::DeckCFiltr,
    Board::Event::MonitorVol,
    Board::Event::DeckABas,
    Board::Event::DeckAMid,
    Board::Event::DeckBBas,
    Board::Event::DeckBMid,
    Board::Event::DeckCMid,
    Board::Event::DeckCBas,
    Board::Event::DeckBFiltr,
    Board::Event::DeckAFiltr,
    Board::Event::LeftTempo,
    Board::Event::MonitorMix,
    Board::Event::DeckCVolume
  };

  const uint16_t buttonsEvents[] = {
    Board::Event::Fx2Btn2,
    Board::Event::Fx2Btn3,
    Board::Event::Fx1Btn1,
    Board::Event::BrowserRightBtn,
    Board::Event::BrowserLeftBtn,
    Board::Event::Fx1Btn2,
    Board::Event::Fx1Btn3,
    Board::Event::Fx2Btn1,
    Board::Event::BrowserPrevBtn,
    Board::Event::BrowserBackBtn
  };

  const uint16_t potsEvents[] = {
    Board::Event::Fx2Pot1,
    Board::Event::MasterVol
  };
} // namespace mixduino
