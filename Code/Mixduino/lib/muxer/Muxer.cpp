#include "Muxer.h"

void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxS0, bitRead(channel, 0));
    digitalWrite(muxS1, bitRead(channel, 1));
    digitalWrite(muxS2, bitRead(channel, 2));
    digitalWrite(muxS3, bitRead(channel, 3));
}

Muxer::Muxer(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig)
{
    muxS0 = s0;
    muxS1 = s1;
    muxS2 = s2;
    muxS3 = s3;
    muxSIG = sig;
}

void Muxer::begin(uint8_t *mPins, uint8_t nPins, uint8_t midiCh)
{
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

    pinMode(muxSIG, INPUT_PULLUP);
    pinMode(muxS0, OUTPUT);
    pinMode(muxS1, OUTPUT);
    pinMode(muxS2, OUTPUT);
    pinMode(muxS3, OUTPUT);
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
