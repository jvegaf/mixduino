#include "Deck.hpp"

namespace MD
{

Deck::Deck(Player* player, Pad* pad)
  : m_player{player},m_pad{pad}
{
  
}

void Deck::setMidiCh(uint8_t midiCh) {
  m_midiCh = midiCh;
  m_player->setMidiChannel(midiCh);
  m_pad->setMidiCh(midiCh);
}

void Deck::read() {
  m_player->read();
  m_pad->read();
}

void Deck::onNoteOn(uint8_t number, uint8_t value) {
  m_player->setTo(number, value);
}

void Deck::onCChange(uint8_t number, uint8_t value) {
  m_pad->setHotCueColor(number, value);
}


} // namespace MD

