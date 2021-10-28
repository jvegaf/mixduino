
#ifndef ARDUINO_BUTTON_H
#define ARDUINO_BUTTON_H
#include <Arduino.h>
#include "MDState.h"

class InputBase  
{
	public:
		virtual void begin();
		virtual MDState read();
};
#endif
