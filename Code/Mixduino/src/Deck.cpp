#include "Deck.hpp"

namespace MD
{

Deck::Deck(Player* player, Pad* pad)
  : m_player{player},m_pad{pad}
{
  
}

void Deck::read(inCommand_t c) {
  m_player->read(c);
  m_pad->read(c);
}

void Deck::onNoteOn(uint8_t number, uint8_t value) {
  m_player->setTo(number, value);
}

void Deck::onCChange(uint8_t number, uint8_t value) {
  m_pad->setHotCueColor(number, value);
}


} // namespace MD

