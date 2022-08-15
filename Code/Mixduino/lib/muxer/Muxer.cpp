#include "Muxer.hpp"
#include "md_enums.hpp"
#include "controller.h"
#include "mux_map.h"



void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(mux_pins[0], bitRead(channel, 0));
    digitalWrite(mux_pins[1], bitRead(channel, 1));
    digitalWrite(mux_pins[2], bitRead(channel, 2));
    digitalWrite(mux_pins[3], bitRead(channel, 3));
}

void Muxer::read(void (*func)(uint8_t, State))
{
    for (uint8_t i = 0; i <= t_elements; i++)
    {
        if (elements[i] == kEmptyEl) continue; // this mux position is empty
        
        setMuxChannel(i);

        c_state[i] = digitalRead(sig_pin);
        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {
            if (p_state[i] != c_state[i])
            {
                lastdebouncetime[i] = millis();

                if (c_state[i] == LOW)
                {
                    func(elements[i], State::Triggered);
                }
                else
                {
                    func(elements[i], State::Idle);
                }

                p_state[i] = c_state[i];
            }
        }
    }
}
