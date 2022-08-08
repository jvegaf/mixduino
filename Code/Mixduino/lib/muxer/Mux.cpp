#include "Mux.hpp"

void Mux::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxS0, bitRead(channel, 0));
    digitalWrite(muxS1, bitRead(channel, 1));
    digitalWrite(muxS2, bitRead(channel, 2));
    digitalWrite(muxS3, bitRead(channel, 3));
}

Mux::Mux(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig)
:muxS0(s0),muxS1(s1),muxS2(s2),muxS3(s3),muxSIG(sig) { }

void Mux::initialize(uint8_t pos)
{
    position = pos;
}

void Mux::read(void (*func)())
{
    setMuxChannel(position);
    cState = digitalRead(muxSIG);
    
    if ((millis() - lastdebouncetime) > debouncedelay)
    {
        if (pState != cState)
        {
            lastdebouncetime = millis();

            if (cState == LOW)
            {
                func();
            }

            pState = cState;
        }
    }
}
