#include "MuxerPad.h"


MuxerPad::MuxerPad(const uint8_t* mxPins, uint8_t sig)
: Muxer(mxPins, sig)
{
    
}

void MuxerPad::begin(const uint8_t *swPositions, const uint8_t totalSw, uint8_t midiCh)
{
    _swPositions = swPositions;
    _tMxSwitches = totalSw;
    _midiChannel = midiCh;

    pState = new int[_tMxSwitches]();
    cState = new int[_tMxSwitches]();
    lastdebouncetime = new unsigned long[_tMxSwitches]();

    pinMode(_mxSigPin, INPUT_PULLUP);
    pinMode(_mxPins[0], OUTPUT);
    pinMode(_mxPins[1], OUTPUT);
    pinMode(_mxPins[2], OUTPUT);
    pinMode(_mxPins[3], OUTPUT);
}

void MuxerPad::setNoteNum(uint8_t number) {
	_firstNumber = number;
}

void MuxerPad::read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    for (uint8_t i = 0; i <= _tMxSwitches; i++)
    {

        setMuxChannel(_swPositions[i]);

        cState[i] = digitalRead(_mxSigPin);
        if ((millis() - lastdebouncetime[i]) > debouncedelay)
        {
            if (pState[i] != cState[i])
            {
                lastdebouncetime[i] = millis();

                if (cState[i] == LOW)
                {
                    //MIDI.sendNoteOn(number , value(127) , channel);
                    funcOn(_firstNumber + i, 127U, _midiChannel);
                }
                else
                {
                    funcOff(_firstNumber + i, 127U, _midiChannel);
                    //MIDI.sendNoteOff(36 + i , 127 , 1);
                }

                pState[i] = cState[i];
            }
        }
    }
}
