#pragma once
#ifndef MD_OUTPUT_H
#define MD_OUTPUT_H
#include <Arduino.h>

class OutputBase
{
protected:
    uint8_t _outPos;

public:
    OutputBase(uint8_t outPosition)
    {
        _outPos = outPosition;
    }
    OutputBase() = default;
    virtual void setTo(uint8_t value) = 0;
};


#endif // MDOUTPUT_H
