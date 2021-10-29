#include "MDPadFunc.h"  

MDPadFunc::MDPadFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos )
	: MDFunc(in, in_pos, out, out_pos)
{
	
}

void MDPadFunc::setMidi(uint8_t midiCh, uint8_t noteNum) {
	this->_midiCh = midiCh;
    this->_prevNoteNumber = noteNum;
}

void MDPadFunc::setMode(Mode m) {
	switch (m)
    {
    case Mode::HOTCUE :
        this->_noteNumber = _prevNoteNumber;
        break;
    
    case Mode::LOOP :
        this->_noteNumber = _prevNoteNumber + 8U;
        break;
    
    case Mode::FX :
        this->_noteNumber = _prevNoteNumber + 16U;
        break;
    
    default:
        break;
    }
}


