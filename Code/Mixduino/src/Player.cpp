#include "Player.hpp"
#include "constans.h"
#include "Button.hpp"

namespace MD
{

  Player::Player(Component* comps, const uint8_t* midiNumbers)
    : m_comps{comps}, m_midiNumbers{midiNumbers}
  {
  }

  void Player::read(inCommand_t c) {
    for (uint8_t i = 0; i < kTPlayerComponents; i++)
    {
      c.midiNumber = m_midiNumbers[i];
      m_comps[i].read(c);
    }
  }

  void Player::setTo(uint8_t pos, uint8_t value) {
    Button* btns = static_cast<Button*>(m_comps);
    btns[pos].setTo(value);

  }
  

} // namespace MD
