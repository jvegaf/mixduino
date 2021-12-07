#include "Player.hpp"
#include "constans.h"

namespace MD
{

  Player::Player(Button* btns, const uint8_t* inPositions, const uint8_t* outPositions, const uint8_t* midiNumbers)
    : m_btns{btns}, m_inPositions{inPositions}, m_outPositions{outPositions}, m_midiNumbers{midiNumbers}
  {
  }

  void Player::setMidiChannel(uint8_t midiCh)
  {
    m_midiCh = midiCh;
  }

  void Player::read() {
    for (auto i = 0; i < kTDeckButtons; i++)
    {
      inMidip_t p = {m_inPositions[i], m_midiCh, m_midiNumbers[i], m_funcOn, m_funcOff};
      m_btns[i].read(p);
    }
  }

  void Player::setTo(uint8_t pos, uint8_t value) {
    m_btns[pos].setTo(m_outPositions[pos], value);
  }
  

} // namespace MD
