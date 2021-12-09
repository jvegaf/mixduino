#include "Player.hpp"
#include "constans.h"

namespace MD
{

  Player::Player(Button* btns, Pot* tempo, const uint8_t* midiNumbers)
    : m_btns{btns}, m_tempo{tempo}, m_midiNumbers{midiNumbers}
  {
  }

  void Player::read(inCommand_t c) {
    for (auto i = 0; i < kTDeckButtons; i++)
    {
      c.midiNumber = m_midiNumbers[i];
      m_btns[i].read(c);
    }
    c.midiNumber = m_midiNumbers[kTDeckButtons];
    m_tempo->read(c);
  }

  void Player::setTo(uint8_t pos, uint8_t value) {
    m_btns[pos].setTo(value);
  }
  

} // namespace MD
