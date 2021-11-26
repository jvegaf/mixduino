#pragma once
#ifndef MD_BUTTON_H
#define MD_BUTTON_H
#include "DigitalInput.h"
#include "Output.h"

class Button  
{
	public:

		Button(DigitalInput* input, Output* output)
		{
			_input = input;
			_output = output;
		}

		Button(DigitalInput* input)
		{
			_input = input;
			_output = NULL;
		}

		virtual void read() = 0;

		void setTo(uint8_t value)
		{
			if (_output != NULL)
			{
				_output->setTo(value);
			}
		}

	protected:

		DigitalInput* _input;
		Output* _output;
};
#endif
