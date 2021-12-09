#pragma once
#include "Button.hpp"
#include "Pot.hpp"

namespace MD
{
  class Player
  {
  public:
    Player(Button* btns, Pot* tempo, const uint8_t* midiNumbers);
    void read(inCommand_t c);
    void setTo(uint8_t pos, uint8_t value);

  private:
    Button* m_btns{nullptr};
    Pot* m_tempo;
    const uint8_t* m_midiNumbers{nullptr};
  };
  
} // namespace MD
