#pragma once
#ifndef MD_BUTTON_H
#define MD_BUTTON_H
#include "Input.h"
#include "Output.h"

class Button  
{
	public:

		Button(Input* input, Output* output)
		{
			_input = input;
			_output = output;
		}

		Button(Input* input)
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

		Input* _input;
		Output* _output;
};
#endif
