#pragma once
#ifndef MD_OUTPUT_H
#define MD_OUTPUT_H
#include <Arduino.h>

class Output
{
public:
    Output(uint8_t outPosition)
    {
        _outPos = outPosition;
    }
    Output() = default;
    virtual void setTo(uint8_t value) = 0;

protected:
    uint8_t _outPos;

};


#endif // MDOUTPUT_H
