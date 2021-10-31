
#ifndef MDFUNC_H
#define MDFUNC_H
#include <Arduino.h>
#include <input_base.h>
#include <output_base.h>
#include <md_state.h>
#include <md_mode.h>

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
			MDState::StateType state = this->input->read(this->inputPos);
			if (state == MDState::StateType::TURN_ON)
			{
				funcNoteOn(this->noteNumber, 127, this->midiCh);
			}
			else if (state == MDState::StateType::TURN_OFF)
			{
				funcNoteOff(this->noteNumber, 127, this->midiCh);
			}
		}

		void onChange(MDState::StateType nState)
		{
			if (nState == MDState::StateType::TURN_ON)
			{
				this->output->setTo((OutDTO){this->outputPos, HIGH, 0});
			}
			else if (nState == MDState::StateType::TURN_OFF)
			{
				this->output->setTo((OutDTO){this->outputPos, LOW, 0});
			}
		}
};


#endif
