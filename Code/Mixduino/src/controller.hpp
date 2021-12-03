#pragma once
#include <Arduino.h>

namespace mixduino {
enum class DeckOption {
  DECK_B,
  DECK_C
};

DeckOption changeDeck(DeckOption deck) {
  switch (deck)
  {
  case DeckOption::DECK_B :
    return DeckOption::DECK_C;

  case DeckOption::DECK_C :
    return DeckOption::DECK_B;

  }
}


class Controller {
public:
  Controller();

  DeckOption deck() const { return m_deck; }
  void switchDeck() { m_deck = changeDeck(m_deck); }

private:
  DeckOption m_deck { DeckOption::DECK_B };
};
} // namespace mixduino
