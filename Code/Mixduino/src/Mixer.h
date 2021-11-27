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

private:
    const ButtonMidi *m_moncue_btns{nullptr};
    const Pot *m_mixer_pots{nullptr};
    const VUmeter *m_vumeters{nullptr};
};

#endif