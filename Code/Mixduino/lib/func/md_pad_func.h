
#ifndef MDPADFUNC_H
#define MDPADFUNC_H
#include <Arduino.h>
#include <md_func.h>

class MDPadFunc : public MDFunc
{
	private:
		uint8_t _prevNoteNumber;

	public:
		MDPadFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos )
		: MDFunc(in, in_pos, out, out_pos)
		{

		}

		MDPadFunc() = default;

		void setMidi(uint8_t midiCh, uint8_t noteNum) {
			this->midiCh = midiCh;
		    this->_prevNoteNumber = noteNum;
		}

		void setMode(MDMode::ModeType m) {
			switch (m)
		    {
		    case MDMode::ModeType::HOTCUE :
		        this->noteNumber = _prevNoteNumber;
		        break;
		    
		    case MDMode::ModeType::LOOP :
		        this->noteNumber = _prevNoteNumber + 8U;
		        break;
		    
		    case MDMode::ModeType::FX :
		        this->noteNumber = _prevNoteNumber + 16U;
		        break;
		    
		    default:
		        break;
		    }
		}

		void onChange(uint8_t valueColor) {
			this->output->setTo((OutDTO){this->outputPos, 0, valueColor});
		}
};
#endif
