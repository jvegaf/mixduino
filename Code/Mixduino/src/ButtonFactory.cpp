#include "ButtonFactory.hpp"
#include "constans.h"
#include "sw_muxmap.h"
#include "sr_fb_map.h"

namespace MD
{

ButtonFactory::ButtonFactory(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix)
{
  auto leftmuxer = inputFact->getLeftMuxer();
  auto rightmuxer = inputFact->getRightMuxer();

  m_playerLeftBtns = makePlayerBtns(leftmuxer, leftPlayerSwBnd, ledFact->getLeftFBLed(), fbPix, playerLeftOutBndl);
  m_playerRightBtns = makePlayerBtns(rightmuxer, rightPlayerSwBnd, ledFact->getRightFBLed(), fbPix, playerRightOutBndl);
  m_padLeftBtns = makePadBtns(leftmuxer, leftPadSwBnd, fbPix, PIXLS_PAD_L);
  m_padRightBtns = makePadBtns(rightmuxer, rightPadSwBnd, fbPix, PIXLS_PAD_R);
  m_padLeftModeBtn = new ButtonMode(leftmuxer, SWMODE_L, fbPix, NP_MODE_L);
  m_padRightModeBtn = new ButtonMode(rightmuxer, SWMODE_R, fbPix, NP_MODE_R);
  m_deckSwitcherBtn = new ButtonMode(rightmuxer, SWDECK_SEL, fbPix, NP_DECK_SEL);
}

Button* ButtonFactory::getLeftPlayerBtns() { return m_playerLeftBtns; }

Button* ButtonFactory::getRightPlayerBtns() { return m_playerRightBtns; }

Button* ButtonFactory::getLeftPadBtns() { return m_padLeftBtns; }

ButtonMode* ButtonFactory::getLeftPadModeBtn() { return m_padLeftModeBtn; }

Button* ButtonFactory::getRightPadBtns() { return m_padRightBtns; }

ButtonMode* ButtonFactory::getRightPadModeBtn() { return m_padRightModeBtn; }

ButtonMode* ButtonFactory::getDeckSwitcherBtn() { return m_deckSwitcherBtn; }


Button* ButtonFactory::makePlayerBtns(
  Muxer* muxer, 
  const uint8_t* inputPos, 
  FBLed* fbled, 
  FBPixel* fbPix, 
  const uint8_t* outPos
  ) {
  auto result = new Button[kTDeckButtons];

  result[0] = Button(muxer, inputPos[0], fbled, outPos[0]);
  result[1] = Button(muxer, inputPos[1], fbled, outPos[1]);
  result[2] = Button(muxer, inputPos[2], fbled, outPos[2]);
  result[3] = Button(muxer, inputPos[3], fbPix, outPos[3]);
  
  return result;
}


Button* ButtonFactory::makePadBtns(Muxer* muxer, const uint8_t* inputPos, FBPixel* fbPix, const uint8_t* outPos) {
  auto result = new Button[kTPadButtons];
  for (auto i = 0; i < kTPadButtons; i++)
  {
    result[i] = Button(muxer, inputPos[i], fbPix, outPos[i]);
  }
  return result;
}

  
} // namespace MD



