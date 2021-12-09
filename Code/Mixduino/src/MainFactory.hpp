#pragma once

#include "Deck.hpp"
#include "Player.hpp"
#include "Pad.hpp" 


namespace MD
{
  class MainFactory
  {
  public:
    MainFactory();
    Deck* getLeftDeck();
    Deck* getRightDeck();
    ButtonMode* getDeckSwitcherBtn();
  private:
    Deck* m_leftDeck{nullptr};
    Deck* m_rightDeck{nullptr};
    ButtonMode* m_deckSwBtn{nullptr};
  };
} // namespace MD
