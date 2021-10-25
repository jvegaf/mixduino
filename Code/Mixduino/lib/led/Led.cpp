#include "Led.h"

Led::Led(Shifter register, uint8_t position)
{
    reg = register;
    pos = position;
}

void Led::setTo(int state)
{
    reg->setPin(pos, state);
    reg->write();
}
