#pragma once

#include "Container.hpp"
#include "Deck.hpp"
#include "ButtonMode.hpp"
#include "constans.h"
namespace MD
{

class Core : public Container
{
public:
  Core(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t), void (*funcCC)(uint8_t, uint8_t, uint8_t));

  void changeMode() override;

  void readDeckLeft();
  void readDeckRight();

  void onCChange(uint8_t channel, uint8_t number, uint8_t value);

  void onNoteOn(uint8_t channel, uint8_t number, uint8_t value);

private:
  void (*m_funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*m_funcOff)(uint8_t, uint8_t, uint8_t);
  void (*m_funcCC)(uint8_t, uint8_t, uint8_t);

  uint8_t m_midiChRight{kChDeckB};

  uint8_t* m_playrStateDeckB{nullptr};
  uint8_t* m_playrStateDeckC{nullptr};
  uint8_t* m_hotsStateDeckB{nullptr};
  uint8_t* m_hotsStateDeckC{nullptr};

  Deck* m_leftDeck{nullptr};
  Deck* m_rightDeck{nullptr};
  ButtonMode* m_deckSwitchBtn{nullptr};

  void executeSelection(uint8_t* playerState, uint8_t* padState, uint8_t btnColor);

  void saveStateChange(uint8_t channel, uint8_t number, uint8_t value);

  void saveStateChange(uint8_t* storage, uint8_t number, uint8_t value);

  void runControlChange(uint8_t channel, uint8_t number, uint8_t value);

  void runNoteOn(uint8_t channel, uint8_t number, uint8_t value);

};
} // namespace MD