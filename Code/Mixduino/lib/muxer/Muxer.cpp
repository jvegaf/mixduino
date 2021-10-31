#include "muxer.h"

void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(_muxPins[0], bitRead(channel, 0));
    digitalWrite(_muxPins[1], bitRead(channel, 1));
    digitalWrite(_muxPins[2], bitRead(channel, 2));
    digitalWrite(_muxPins[3], bitRead(channel, 3));
}