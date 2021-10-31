
#pragma once
#ifndef PAD_H
#define PAD_H

#include <pad_str.h>
#include <md_feedback.h>

class Pad  
{
	private:
		MDPadFunc* pfuncs;
		uint8_t midiChannel;
		void (*fnon)(uint8_t, uint8_t, uint8_t);
		void (*fnoff)(uint8_t, uint8_t, uint8_t);

	public:

		Pad(PadAggr aggr)
		{
			pfuncs = aggr.funcs;
		    midiChannel = aggr.midiChannel;
		    fnon = aggr.funcOn;
		    fnoff = aggr.funcOff;
		}

		Pad() = default;

		void read() {
			for (uint8_t i = 0; i < T_DECK_PADS; i++)
		    {
		        MDFunc* fnc = &this->pfuncs[i];
		        fnc->read(fnon, fnoff);
		    }
		    
		}

		void onNoteOn(uint8_t number, uint8_t value) {
			this->pfuncs[number].onChange(value);
		} 

		void onNoteOff(uint8_t number, uint8_t value) {
			this->pfuncs[number].onChange(0);
		}

		void updateMode(MDMode::ModeType m) {
			for (uint8_t i = 0; i < T_DECK_PADS; i++)
		    {
		        this->pfuncs[i].setMode(m);
		    }
		    
		}

};


#endif // PAD_H
