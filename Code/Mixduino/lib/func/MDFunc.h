
#ifndef ARDUINO_MDFUNC_H
#define ARDUINO_MDFUNC_H
#include <Arduino.h>
#include <InputBase.h>
#include <OutputBase.h>
#include <MDState.h>
#include <Mode.h>

#pragma once

class MDFunc
{
public:
	MDFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos );
	void setMidi(uint8_t midiCh, uint8_t noteNum);
	void read(void (*funcNoteOn)(uint8_t, uint8_t, uint8_t),void (*funcNoteOff)(uint8_t, uint8_t, uint8_t));
	void onChange(MDState nState);
	
protected:
	InputBase* _input;
	uint8_t _inputPos;
	OutputBase* _output;
	uint8_t _outputPos;
	uint8_t _midiCh;
	uint8_t _noteNumber;
};


#endif
