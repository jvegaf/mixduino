#include "md_pad.hpp"
#include "md_feedback.hpp"

void Pad::changeMode(Location loc) {

  switch (this->pad_mode)
  {
    case Mode::HotCues :
        this->pad_mode = Mode::Loop;
        this->draw(loc, MDColor::LoopColorMode);
        break;

    case Mode::Loop :
        this->pad_mode = Mode::Beatjump;
        this->draw(loc, MDColor::BeJumpColorMode);
        break;

    case Mode::Beatjump :
        this->pad_mode = Mode::TempoRange;
        this->draw(loc, MDColor::TRangeColorMode);
        break;

    case Mode::TempoRange :
        this->pad_mode = Mode::HotCues;
        this->draw(loc, this->hc_cols);
        break;
  }
}

void Pad::setHotCueType(uint8_t number, uint8_t type) {
  for (size_t i = 0; i < t_pads; i++) {
    if (midi_notes[i] == number) {
      this->hotcueTypes[i] = type;
    }
  }
}

void Pad::handleEvent(uint8_t id, uint8_t value) {
  if (!idExists(id)) {
    return;
  }
  uint8_t channel = static_cast<uint8_t>(this->pad_mode);
  this->noteFunc(id, value, channel);
}

void Pad::handleEvent(uint8_t channel, uint8_t number, uint8_t value) {
  if (channel == hotcues_ch) {
    this->setHotCueType(number, value);
  }
}

bool Pad::idExists(uint8_t id) {
  for (size_t i = 0; i < t_pads; i++) {
    if (midi_notes[i] == id) {
      return true;
    }
  }
  return false;
}

void Pad::draw(Location l, uint32_t color) {
  if (this->is_active) {
    MDFeedback::changePad(l, color);
  }
}

void Pad::draw(Location l, uint32_t *colors) {
  if (this->is_active) {
    MDFeedback::changePads(l, colors);
  }
}
