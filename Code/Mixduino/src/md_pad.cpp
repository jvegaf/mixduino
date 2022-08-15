#include "md_pad.hpp"
#include "controller.h"
#include "midi_map.h"
#include "md_enums.hpp"


void Pad::changeMode()
{
  switch (this->pad_mode)
  {
    case Mode::HotCues :
        this->pad_mode = Mode::Loop;
        break;

    case Mode::Loop :
        this->pad_mode = Mode::Beatjump;
        break;

    case Mode::Beatjump :
        this->pad_mode = Mode::TempoRange;
        break;

    case Mode::TempoRange :
        this->pad_mode = Mode::HotCues;
        break;
  }
}

void Pad::setHotCueType(uint8_t pos, uint8_t type)
{
  this->hotcues[pos] = type;
}

void Pad::sendNote(uint8_t element, State el_state)
{
  uint8_t value = static_cast<uint8_t>(el_state);
  uint8_t channel = static_cast<uint8_t>(this->pad_mode);
  this->noteFunc(this->midi_notes[element], value, channel);
}