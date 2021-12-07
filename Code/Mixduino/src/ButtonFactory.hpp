#pragma once

#include "Button.hpp"
#include "ButtonMode.hpp"
#include "MuxerInputFactory.hpp"
#include "FBLedFactory.hpp"
#include "FBPixel.h"

namespace MD
{
  class ButtonFactory
  {
  public:
    ButtonFactory(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix);
    Button* getLeftPlayerBtns();
    Button* getRightPlayerBtns();
    Button* getLeftPadBtns();
    ButtonMode* getLeftPadModeBtn(); 
    Button* getRightPadBtns();
    ButtonMode* getRightPadModeBtn(); 
  private:
    Button* m_playerLeftBtns{nullptr};
    Button* m_playerRightBtns{nullptr};
    Button* m_padLeftBtns{nullptr};
    ButtonMode* m_padLeftModeBtn{nullptr};
    Button* m_padRightBtns{nullptr};
    ButtonMode* m_padRightModeBtn{nullptr};

    void makePlayerLeftBtns(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix);
    void makePlayerRightBtns(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix);
    void makePadLeftBtns(MuxerInputFactory* inputFact, FBPixel* fbPix);
    void makePadRightBtns(MuxerInputFactory* inputFact, FBPixel* fbPix);
    
    
  };

} // namespace MD
