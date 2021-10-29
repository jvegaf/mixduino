#include "BtnKit.h"

BtnKit::BtnKit(const uint8_t *arduinoPins, const uint8_t tPins)
{
    totalPins = tPins;
    pins = new uint8_t[totalPins];
    for (uint8_t i = 0; i < totalPins; i++)
    {
        pins[i] = arduinoPins[i];
    }
    pState = new int[totalPins]();
    cState = new int[totalPins]();
    lastdebouncetime = new unsigned long[totalPins]();
}

void BtnKit::begin()
{
    for (uint8_t i = 0; i < totalPins; i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }
}

MDState BtnKit::read(uint8_t input_pos)
{

    cState[input_pos] = digitalRead(pins[input_pos]);

    if ((millis() - lastdebouncetime[input_pos]) > debouncedelay)
    {
        if (cState[input_pos] != pState[input_pos])
        {
            lastdebouncetime[input_pos] = millis();

            if (cState[input_pos] == LOW)
            {
                pState[input_pos] = cState[input_pos];
                return MDState::TURN_OFF; // envia NoteOn(nota, velocity, canal midi)
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
