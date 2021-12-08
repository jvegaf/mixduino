#pragma once
#include "Player.hpp"
#include "Pad.hpp"

namespace MD
{
  class Deck
  {
  public:
    Deck(Player* player, Pad* pad);
    void setMidiCh(uint8_t midiCh);
    void read();
    void onNoteOn(uint8_t number, uint8_t value);
    void onCChange(uint8_t number, uint8_t value);
  private:
    Player* m_player{nullptr};
    Pad* m_pad{nullptr};
    uint8_t m_midiCh{0};
  };
  
} // namespace MD
