#include <MDFunc.h>

MDFunc::MDFunc(InputBase *in, uint8_t in_pos, OutputBase *out, uint8_t out_pos)
    : _input(in),
      _inputPos(in_pos),
      _output(out),
      _outputPos(out_pos)
{
}

void MDFunc::setMidi(uint8_t midiCh, uint8_t noteNum)
{
    this->_midiCh = midiCh;
    this->_noteNumber = noteNum;
}

void MDFunc::read(void (*funcNoteOn)(uint8_t, uint8_t, uint8_t), void (*funcNoteOff)(uint8_t, uint8_t, uint8_t))
{
    MDState state = this->_input->read(this->_inputPos);
    if (state == MDState::TURN_ON)
    {
        funcNoteOn(this->_noteNumber, 127, this->_midiCh);
    }
    else if (state == MDState::TURN_OFF)
    {
        funcNoteOff(this->_noteNumber, 127, this->_midiCh);
    }
}

void MDFunc::onChange(MDState nState)
{
    if (nState == MDState::TURN_ON)
    {
        this->_output->setTo(this->_outputPos, HIGH);
    }
    else if (nState == MDState::TURN_OFF)
    {
        this->_output->setTo(this->_outputPos, LOW);
    }
}
