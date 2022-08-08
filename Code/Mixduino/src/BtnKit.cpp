#include "BtnKit.h"

BtnKit::BtnKit(uint8_t* const arduinoPins, uint8_t* const notes, const uint8_t tPins)
: pins(arduinoPins), midiNotes(notes), totalPins(tPins)
{
    pState = new int[tPins]();
    cState = new int[tPins]();
    lastdebouncetime = new unsigned long[tPins]();
}

void BtnKit::initialize()
{
    for (uint8_t i = 0; i < totalPins; i++)
    {
        pinMode(pins[i], INPUT_PULLUP);
    }
}

void BtnKit::read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t midiCh)
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
                    funcOn(midiNotes[i], 127, midiCh); // envia NoteOn(nota, velocity, canal midi)
                }
                else
                {
                    funcOn(midiNotes[i], 0, midiCh);
                }

                pState[i] = cState[i];
            }
        }
    }
}
