#include "ButtonFactory.hpp"
#include "constans.h"

namespace MD
{

ButtonFactory::ButtonFactory(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix)
{
  makePlayerLeftBtns(inputFact, ledFact, fbPix);
  makePlayerRightBtns(inputFact, ledFact, fbPix);
  makePadLeftBtns(inputFact, fbPix);
  makePadRightBtns(inputFact, fbPix);
}

Button* ButtonFactory::getLeftPlayerBtns() {
  return m_playerLeftBtns;
}

Button* ButtonFactory::getRightPlayerBtns() {
  return m_playerRightBtns;
}

Button* ButtonFactory::getLeftPadBtns() {
  return m_padLeftBtns;
}

ButtonMode* ButtonFactory::getLeftPadModeBtn() {
  return m_padLeftModeBtn;
}

Button* ButtonFactory::getRightPadBtns() {
  return m_padRightBtns;
}

ButtonMode* ButtonFactory::getRightPadModeBtn() {
  return m_padRightModeBtn;
}



void ButtonFactory::makePlayerLeftBtns(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix) {
  auto muxer = inputFact->getLeftMuxer();
  auto fbLed = ledFact->getLeftFBLed();
  m_playerLeftBtns = new Button[kTDeckButtons];
  m_playerLeftBtns[0] = Button(muxer, fbLed);
  m_playerLeftBtns[1] = Button(muxer, fbLed);
  m_playerLeftBtns[2] = Button(muxer, fbLed);
  m_playerLeftBtns[3] = Button(muxer, fbPix);
}

void ButtonFactory::makePlayerRightBtns(MuxerInputFactory* inputFact, FBLedFactory* ledFact, FBPixel* fbPix) {
  auto muxer = inputFact->getRightMuxer();
  auto fbLed = ledFact->getRightFBLed();
  m_playerRightBtns = new Button[kTDeckButtons];
  m_playerRightBtns[0] = Button(muxer, fbLed);
  m_playerRightBtns[1] = Button(muxer, fbLed);
  m_playerRightBtns[2] = Button(muxer, fbLed);
  m_playerRightBtns[3] = Button(muxer, fbPix);
}

void ButtonFactory::makePadLeftBtns(MuxerInputFactory* inputFact, FBPixel* fbPix) {
  auto muxer = inputFact->getLeftMuxer();
  m_padLeftBtns = new Button[kTPadButtons];
  for (auto i = 0; i < kTPadButtons; i++)
  {
    m_padLeftBtns[i] = Button(muxer, fbPix);
  }
  m_padLeftModeBtn = new ButtonMode(muxer, fbPix);
}

void ButtonFactory::makePadRightBtns(MuxerInputFactory* inputFact, FBPixel* fbPix) {
  auto muxer = inputFact->getRightMuxer();
  m_padRightBtns = new Button[kTPadButtons];
  for (auto i = 0; i < kTPadButtons; i++)
  {
    m_padRightBtns[i] = Button(muxer, fbPix);
  }
  m_padRightModeBtn = new ButtonMode(muxer, fbPix);
}
  
} // namespace MD



