#include "ArduInput.h"

ArduInput::ArduInput(uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
    : Input(inputIndex, funcOn, funcOff)
{
}

void ArduInput::read(uint8_t midiCh, uint8_t note)
{
    _cState = digitalRead(_inPos);
    if ((millis() - _lastdebouncetime) > DEBOUNCE_DELAY)
    {

        if (_cState != _pState)
        {
            _lastdebouncetime = millis();

            if (_cState == LOW)
            {
                _funOn(note, 127, midiCh); // envia NoteOn(nota, velocity, canal midi)
            }
            else
            {
                _funOff(note, 127, midiCh);
            }

            _pState = _cState;
        }
    }
}
