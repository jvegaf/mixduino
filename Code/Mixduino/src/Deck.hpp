#pragma once
#include "Player.hpp"
#include "Pad.hpp"

namespace MD
{
  class Deck
  {
  public:
    Deck(Player* player, Pad* pad);
    void changePadmode();
    void read(inCommand_t c);
    void onNoteOn(uint8_t number, uint8_t value);
    void onCChange(uint8_t number, uint8_t value);
  private:
    Player* m_player{nullptr};
    Pad* m_pad{nullptr};
  };
  
} // namespace MD
