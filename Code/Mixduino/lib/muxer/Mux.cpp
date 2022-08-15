#include "Mux.hpp"

void Mux::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxpins[0], bitRead(channel, 0));
    digitalWrite(muxpins[1], bitRead(channel, 1));
    digitalWrite(muxpins[2], bitRead(channel, 2));
    digitalWrite(muxpins[3], bitRead(channel, 3));
}

Mux::Mux(const uint8_t* m_pins, const uint8_t sig, const uint8_t pos, const uint8_t id)
:muxpins(m_pins),muxSIG(sig), position(pos), element_id(id) { }



void Mux::read(void (*func)(uint8_t, uint8_t))
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
                func(element_id, 127U);
            }
            else
            {
                func(element_id, 0U);
            }

            pState = cState;
        }
    }
}
