
#ifndef MDFUNC_H
#define MDFUNC_H
#include <Arduino.h>
#include "input_base.h"
#include "output_base.h"
#include "md_defs.h"

#pragma once

class MDFunc
{
	protected:
		InputBase* input;
		uint8_t inputPos;
		OutputBase* output;
		uint8_t outputPos;
		uint8_t midiCh;
		uint8_t noteNumber;

	public:
		MDFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos)
			: input(in),
			inputPos(in_pos),
			output(out),
			outputPos(out_pos)
		{

		}

		MDFunc() = default;

		void setMidi(uint8_t midiCh, uint8_t noteNum)
		{
			this->midiCh = midiCh;
			this->noteNumber = noteNum;
		}

		void read(void (*funcNoteOn)(uint8_t, uint8_t, uint8_t),void (*funcNoteOff)(uint8_t, uint8_t, uint8_t))
		{
			State state = this->input->read(this->inputPos);
			if (state == State::STATE_HIGH)
			{
				funcNoteOn(this->noteNumber, 127, this->midiCh);
			}
			if (state == State::STATE_LOW)
			{
				funcNoteOff(this->noteNumber, 127, this->midiCh);
			}
		}

		void onChange(State nState)
		{
			if (nState == State::STATE_HIGH)
			{
				this->output->setTo((OutDTO){this->outputPos, HIGH, 0});
			}
			else if (nState == State::STATE_LOW)
			{
				this->output->setTo((OutDTO){this->outputPos, LOW, 0});
			}
		}
};


#endif
