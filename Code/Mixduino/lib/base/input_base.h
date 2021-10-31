
#pragma once
#ifndef INPUT_BASE_H
#define INPUT_BASE_H

#include <md_state.h>
#include <Arduino.h>

class InputBase  
{
	public:
		virtual void begin() = 0;
		virtual MDState::StateType read(uint8_t input_pos) = 0;
};

#endif // INPUT_BASE_H
