#include "BtnKit.h"

BtnKit::BtnKit(uint8_t *arduinoPins, uint8_t tPins)
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

void BtnKit::begin(uint8_t midiCh)
{
    for (uint8_t i = 0; i < totalPins; i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }

    midiChannel = midiCh;
}

void BtnKit::read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{

    for (uint8_t i = 0; i < totalPins; i++)
    {
        cState[i] = digitalRead(pins[i]);
    }

    for (uint8_t i = 0; i < totalPins; i++)
    {

        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {

            if (cState[i] != pState[i])
            {
                lastdebouncetime[i] = millis();

                if (cState[i] == LOW)
                {
                    funcOn(i, 127, midiChannel); // envia NoteOn(nota, velocity, canal midi)
                }
                else
                {
                    funcOff(i, 127, midiChannel);
                }

                pState[i] = cState[i];
            }
        }
    }
}
