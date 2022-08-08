#pragma once

#include <Arduino.h>
#include "midi_map.h"



namespace Pad
{

    enum Mode
    {
        HotCues = hotcues_ch,
        Loop,
        Beatjump,
        TempoRange,
    };

    Mode change(Mode selected){
        auto result = selected;
        switch (selected)
        {
        case Mode::HotCues :
            result = Mode::Loop;
            break;
        
        case Mode::Loop :
            result = Mode::Beatjump;
            break;
        case Mode::Beatjump :
            result = Mode::TempoRange;
            break;
        case Mode::TempoRange :
            result = Mode::HotCues;
            break;
        }
        return result;
    }
}