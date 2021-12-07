#pragma once
#include "Player.hpp"
#include "Pad.hpp"

namespace MD
{
  class Controller
  {
  public:
    Controller(Player* player, Pad* pad);
    void setMidiCh(uint8_t midiCh);
    void read();
    void onNoteOn(uint8_t number, uint8_t value);
    void onCChange(uint8_t number, uint8_t value);
  private:
    Player* m_player;
    Pad* m_pad;
    uint8_t m_midiCh;
  };
  
} // namespace MD
