#include "Core.hpp"
#include "MainFactory.hpp"

namespace MD
{

Core::Core(
      void (*funcOn)(uint8_t, uint8_t, uint8_t), 
      void (*funcOff)(uint8_t, uint8_t, uint8_t), 
      void (*funcCC)(uint8_t, uint8_t, uint8_t),
      void (*cBackFn)(uint8_t),
      Adafruit_NeoPixel* np)
:m_funcOn{funcOn}, 
m_funcOff{funcOff}, 
m_funcCC{funcCC},
m_cBackFn{cBackFn},
m_playrStateDeckB{new uint8_t[kTDeckButtons]()},
m_playrStateDeckC{new uint8_t[kTDeckButtons]()},
m_hotsStateDeckB{new uint8_t[kTPadButtons]()},
m_hotsStateDeckC{new uint8_t[kTPadButtons]()}
{
  auto factory = new MainFactory(np);
    m_leftDeck = factory->getLeftDeck();
    m_rightDeck = factory->getRightDeck();
    m_deckSwitchBtn = factory->getDeckSwitcherBtn();
    executeSelection(m_playrStateDeckB, m_hotsStateDeckB, kDeckBActiveColor);
}

void Core::handleCallback(uint8_t cType)
{
  switch (cType)
  {
  case kDeckSwitcherBtnType:
    changeDeck();
    break;
  
  case kPadModeLeftBtnType:
    m_leftDeck->changePadmode();
    break;
  
  case kPadModeRightBtnType:
    m_rightDeck->changePadmode();
    break;
  }
}

void Core::changeDeck() {

  switch (m_midiChRight)
  {
  case kChDeckB :
      m_midiChRight = kChDeckC;
      executeSelection(m_playrStateDeckC, m_hotsStateDeckC, kDeckCActiveColor);
      break;
  
  case kChDeckC :
      m_midiChRight = kChDeckB;
      executeSelection(m_playrStateDeckB, m_hotsStateDeckB, kDeckBActiveColor);
      break;
  
  }
}

void Core::readDeckLeft() 
{
  inCommand_t c = { m_funcOn, m_funcOff, m_funcCC, m_cBackFn, kChDeckA, 0, 0};
  m_deckSwitchBtn->read(c.cBackFn);
  m_leftDeck->read(c);
}

void Core::readDeckRight() 
{
  inCommand_t c = { m_funcOn, m_funcOff, m_funcCC, m_cBackFn, m_midiChRight, 0, 0};
  m_deckSwitchBtn->read(c.cBackFn);
  m_rightDeck->read(c);
}

void Core::onCChange(uint8_t channel, uint8_t number, uint8_t value) {
  switch (channel)
  {
  case kChDeckA:
    m_leftDeck->onCChange(number, value);
    break;
  
  case kChDeckB:
    saveStateChange(m_hotsStateDeckB, number, value);
    runControlChange(channel, number, value);
    break;
  
  case kChDeckC:
    saveStateChange(m_hotsStateDeckC, number, value);
    runControlChange(channel, number, value);
    break;
  
  }
  
}

void Core::onNoteOn(uint8_t channel, uint8_t number, uint8_t value) {
  switch (channel)
  {
    case kChDeckA:
      m_leftDeck->onNoteOn(number, value);
      break;
    
    case kChDeckB:
      saveStateChange(m_playrStateDeckB, number, value);
      runNoteOn(channel, number, value);
      break;
    
    case kChDeckC:
      saveStateChange(m_playrStateDeckC, number, value);
      runNoteOn(channel, number, value);
      break;
  
  }
}

void Core::saveStateChange(uint8_t* storage, uint8_t number, uint8_t value)
{

    storage[number] = value;
  
}

void Core::runControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  if (channel != m_midiChRight) return;
  
  m_rightDeck->onCChange(number, value);
  
}

void Core::runNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  if (channel != m_midiChRight) return;
  
  m_rightDeck->onNoteOn(number, value);
  
}

void Core::executeSelection(uint8_t* playerState, uint8_t* padState, uint8_t btnColor)
{
  for (uint8_t i = 0; i < kTDeckButtons; i++)
  {
      m_rightDeck->onNoteOn(i, playerState[i]);
  }
  for (uint8_t i = 0; i < kTPadButtons; i++)
  {
      m_rightDeck->onCChange(i, padState[i]);
  }
  
  m_deckSwitchBtn->setTo(btnColor);
}






} // namespace MD

