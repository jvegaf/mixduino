#include "Led.h"

Led::Led(Shifter shifter, uint8_t position)
{
    _reg = &shifter;
    _pos = position;
}

void Led::setTo(uint32_t state)
{
    _reg->setPin(_pos, state);
    _reg->write();
}
