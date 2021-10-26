
#ifndef ARDUINO_BUTTON_H
#define ARDUINO_BUTTON_H
#include <Arduino.h>
#include "BtnState.h"

class ButtonBase  
{
	private:
		int _pState = 0;
		int _cState;
		unsigned long _lastdebouncetime;
		unsigned long _debouncedelay = 20;

	public:
		virtual void begin() = 0;
		virtual BtnState read() = 0;
};
#endif
