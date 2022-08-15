#include "md_mixer.hpp"
#include "midi_map.h"
#include "md_feedback.hpp"



void MDMixer::handleEvent(uint8_t id, uint8_t value)
{
    uint8_t channel = sw_in_ch;
    this->FuncPtr(id, value, channel);
}

void MDMixer::handleEvent(uint8_t channel, uint8_t number, uint8_t value)
{
    MDFeedback::setLedValue(number, value);
}