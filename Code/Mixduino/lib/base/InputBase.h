
#ifndef ARDUINO_BUTTON_H
#define ARDUINO_BUTTON_H
#include <Arduino.h>
#include "MDState.h"

class InputBase  
{
	public:
		virtual void begin();
		virtual MDState read(uint8_t input_pos) = 0;
};
#endif
