#pragma once
#include "Button.hpp"

namespace MD
{
  class Player
  {
  public:
    Player(Button* btns, const uint8_t* midiNumbers);
    void read(inMidip_t p);
    void setTo(uint8_t pos, uint8_t value);

  private:
    Button* m_btns{nullptr};
    const uint8_t* m_midiNumbers{nullptr};
  };
  
} // namespace MD
