#include "Muxer.hpp"

void Muxer::setMuxChannel(uint8_t channel)
{
    digitalWrite(muxS0, bitRead(channel, 0));
    digitalWrite(muxS1, bitRead(channel, 1));
    digitalWrite(muxS2, bitRead(channel, 2));
    digitalWrite(muxS3, bitRead(channel, 3));
}

Muxer::Muxer(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig)
:muxS0(s0),muxS1(s1),muxS2(s2),muxS3(s3),muxSIG(sig) { }

void Muxer::initialize(const uint8_t *pins_group, const uint8_t t_pins, uint8_t firstNote)
{
    first_note = firstNote;
    totalMuxPins = t_pins;
    muxPinsGroup = new uint8_t[totalMuxPins];
    for (uint8_t i = 0; i < totalMuxPins; i++)
    {
        muxPinsGroup[i] = pins_group[i];
    }

    pState = new int[totalMuxPins]();
    cState = new int[totalMuxPins]();
    lastdebouncetime = new unsigned long[totalMuxPins]();
}

void Muxer::read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t midiCh)
{
    for (uint8_t i = 0; i <= totalMuxPins; i++)
    {

        setMuxChannel(muxPinsGroup[i]);

        cState[i] = digitalRead(muxSIG);
        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {
            if (pState[i] != cState[i])
            {
                lastdebouncetime[i] = millis();

                if (cState[i] == LOW)
                {
                    //MIDI.sendNoteOn(number , value(127) , channel);
                    funcOn(first_note + i, 127U, midiCh);
                }
                else
                {
                    funcOn(first_note + i, 0, midiCh);
                    //MIDI.sendNoteOff(36 + i , 127 , 1);
                }

                pState[i] = cState[i];
            }
        }
    }
}
