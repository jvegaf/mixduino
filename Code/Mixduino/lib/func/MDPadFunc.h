
#ifndef ARDUINO_MDPADFUNC_H
#define ARDUINO_MDPADFUNC_H
#include <Arduino.h>
#include <MDFunc.h>

class MDPadFunc : public MDFunc
{
	public:
		MDPadFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos );
		void setMidi(uint8_t midiCh, uint8_t noteNum); 
		void setMode(Mode m);
	private:
		uint8_t _prevNoteNumber;

};
#endif
