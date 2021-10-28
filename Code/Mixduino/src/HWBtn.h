
#ifndef ARDUINO_HWBTN_H
#define ARDUINO_HWBTN_H
#include <Arduino.h>
#include "md_pinmap.h"
#include "InputBase.h"
#include "MDState.h"

class HWBtn : public InputBase
{
private:
	uint8_t _arduinoPin;
	int _pState = 0;
	int _cState;
	unsigned long _lastdebouncetime;
	unsigned long _debouncedelay = 20;

public:
	HWBtn(uint8_t ardPin);
	void begin();
	MDState read();
};
#endif
