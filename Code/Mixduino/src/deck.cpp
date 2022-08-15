#include "deck.hpp"
#include "midi_map.h"
#include "md_feedback.hpp"

void Deck::handleEvent(uint8_t id, uint8_t value)
{
    uint8_t channel = sw_in_ch;
    this->FuncPtr(id, value, channel);
}

void Deck::handleEvent(uint8_t channel, uint8_t number, uint8_t value)
{
  if (this->is_active)
  {
    MDFeedback::setLedValue(number, value);
  }
}