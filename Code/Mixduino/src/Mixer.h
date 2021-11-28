#pragma once
#ifndef MD_MIXER_H
#define MD_MIXER_H

#include "ButtonMidi.h"
#include "Pot.h"
#include "VUmeter.h"

class Mixer
{
public:
    Mixer(ButtonMidi *moncue_btns, Pot *mixer_pots, VUmeter *vumeters)
        : m_moncue_btns{moncue_btns}, m_mixer_pots{mixer_pots}, m_vumeters{vumeters}
    {
    }

    void readButtons() {
        for (uint8_t i = 0; i < T_MIDI_MIXER_BTNS; i++) {
            m_moncue_btns[i].read();
        }
    }

    void readPots() {
        for (uint8_t i = 0; i < T_MIDI_MIXER_POTS; i++) {
            m_mixer_pots[i].read();
        }
    }

    void setLevel(uint8_t number, uint8_t value)
    {
        m_vumeters[number].setLevel(value);
    }

    void setTo(uint8_t number, uint8_t value)
    {
        m_moncue_btns[number].setTo(value);
    }

private:
    ButtonMidi *m_moncue_btns{nullptr};
    Pot *m_mixer_pots{nullptr};
    VUmeter *m_vumeters{nullptr};
};

#endif