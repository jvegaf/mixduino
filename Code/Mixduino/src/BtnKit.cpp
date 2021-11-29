#include "BtnKit.hpp"

namespace input
{

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

    void BtnKit::read(EventManager &em)
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
                        em.queueEvent(EventManager::kEventKeyPress, i);
                        //funcOn(i, 127, midiChannel); // envia NoteOn(nota, velocity, canal midi)
                    }
                    else
                    {
                        em.queueEvent(EventManager::kEventKeyRelease, i);
                        // funcOff(i, 127, midiChannel);
                    }

                    pState[i] = cState[i];
                }
            }
        }
    }
} // namespace input
