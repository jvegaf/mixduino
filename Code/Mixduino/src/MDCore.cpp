#include "MDCore.h"


void MDCore::initPins()
{
    for(uint8_t i=0;i < T_MUXPIN_BUNDLE;i++) {
        pinMode(MUXPIN_BUNDLE[i], OUTPUT);
    }
    for (uint8_t i = 0; i < T_ARD_SW_BUNDLE; i++)
    {
        pinMode(ARD_SW_BUNDLE[i], INPUT_PULLUP);
    }
}

void MDCore::vuChange(uint8_t number, uint8_t value)
{
    // _vuSet[number].setLevel(value);
}

ModeSelector MDCore::incrementPadMode(ModeSelector mode) {
	switch (mode)
    {
    case ModeSelector::HOTCUE_MODE:
        return ModeSelector::LOOP_MODE;

    case ModeSelector::LOOP_MODE:
        return ModeSelector::FX_MODE;

    case ModeSelector::FX_MODE:
        return ModeSelector::HOTCUE_MODE;
    
    default:
        return ModeSelector::HOTCUE_MODE;
    }
}

