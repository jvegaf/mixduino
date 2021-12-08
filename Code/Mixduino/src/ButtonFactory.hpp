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
    
    
    

    

    Button* makePlayerBtns(Muxer* muxer, const uint8_t* inputPos, FBLed* fbled, FBPixel* fbPix, const uint8_t* outPos);

    Button* makePadBtns(Muxer* muxer, const uint8_t* inputPos, FBPixel* fbPix, const uint8_t* outPos);
    
    
  };

} // namespace MD
