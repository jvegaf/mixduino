#include "Muxer.h"

void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(MUX_PINS[0], bitRead(channel, 0));
    digitalWrite(MUX_PINS[1], bitRead(channel, 1));
    digitalWrite(MUX_PINS[2], bitRead(channel, 2));
    digitalWrite(MUX_PINS[3], bitRead(channel, 3));
}

Muxer::Muxer(uint8_t sig, const uint8_t* mPins, const uint8_t nPins)
{
    muxSIG = sig;
    totalMuxPins = nPins;
    MUX_PINS = new uint8_t[totalMuxPins];
    for (uint8_t i = 0; i < totalMuxPins; i++)
    {
        MUX_PINS[i] = mPins[i];
    }

    pState = new int[totalMuxPins]();
    cState = new int[totalMuxPins]();
    lastdebouncetime = new unsigned long[totalMuxPins]();
}

void Muxer::begin()
{
    pinMode(muxSIG, INPUT_PULLUP);
    pinMode(MUX_PINS[0], OUTPUT);
    pinMode(MUX_PINS[1], OUTPUT);
    pinMode(MUX_PINS[2], OUTPUT);
    pinMode(MUX_PINS[3], OUTPUT);
}

MDState Muxer::read(uint8_t input_pos)
{
    setMuxChannel(input_pos);
    cState[input_pos] = digitalRead(muxSIG);
    
    for (uint8_t i = 0; i <= totalMuxPins; i++)
    {


        if ((millis() - lastdebouncetime[input_pos]) > debouncedelay)
        {
            if (pState[input_pos] != cState[input_pos])
            {
                lastdebouncetime[input_pos] = millis();

                if (cState[input_pos] == LOW)
                {
                    pState[input_pos] = cState[input_pos];
                    return MDState::TURN_OFF;
                }
                else
                {
                    pState[input_pos] = cState[input_pos];
                    return MDState::TURN_ON;
                }
            }
            return MDState::SAME;
        }
    }
}
