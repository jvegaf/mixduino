#include "Muxer.h"

void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxPins[0], bitRead(channel, 0));
    digitalWrite(muxPins[1], bitRead(channel, 1));
    digitalWrite(muxPins[2], bitRead(channel, 2));
    digitalWrite(muxPins[3], bitRead(channel, 3));
}

Muxer::Muxer(uint8_t sig, const uint8_t* mPins, const uint8_t nPins, uint8_t midiCh)
{
    muxSIG = sig;
    totalMuxPins = nPins;
    muxPins = new uint8_t[totalMuxPins];
    midiChannel = midiCh;
    for (uint8_t i = 0; i < totalMuxPins; i++)
    {
        muxPins[i] = mPins[i];
    }

    pState = new int[totalMuxPins]();
    cState = new int[totalMuxPins]();
    lastdebouncetime = new unsigned long[totalMuxPins]();
}

void Muxer::begin()
{
    pinMode(muxSIG, INPUT_PULLUP);
    pinMode(muxPins[0], OUTPUT);
    pinMode(muxPins[1], OUTPUT);
    pinMode(muxPins[2], OUTPUT);
    pinMode(muxPins[3], OUTPUT);
}

void Muxer::read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    for (uint8_t i = 0; i <= totalMuxPins; i++)
    {

        setMuxChannel(i);

        cState[i] = digitalRead(muxSIG);
        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {
            if (pState[i] != cState[i])
            {
                lastdebouncetime[i] = millis();

                if (cState[i] == LOW)
                {
                    //MIDI.sendNoteOn(number , value(127) , channel);
                    funcOn(i, 127U, midiChannel);
                }
                else
                {
                    funcOff(i, 127U, midiChannel);
                    //MIDI.sendNoteOff(36 + i , 127 , 1);
                }

                pState[i] = cState[i];
            }
        }
    }
}
