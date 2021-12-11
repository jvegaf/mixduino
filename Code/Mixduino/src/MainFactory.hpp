#pragma once

#include <Adafruit_NeoPixel.h>
#include "Deck.hpp"
#include "Player.hpp"
#include "Pad.hpp" 


namespace MD
{
  class MainFactory
  {
  public:
    MainFactory(Adafruit_NeoPixel* np);
    Deck* getLeftDeck();
    Deck* getRightDeck();
    ButtonCBack* getDeckSwitcherBtn();
  private:
    Deck* m_leftDeck{nullptr};
    Deck* m_rightDeck{nullptr};
    ButtonCBack* m_deckSwBtn{nullptr};
  };
} // namespace MD
