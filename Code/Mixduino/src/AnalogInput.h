#pragma once
#ifndef MD_ANALOG_INPUT_H
#define MD_ANALOG_INPUT_H
#include "Input.h"

class AnalogInput: public Input
{
public: 
	AnalogInput(uint8_t inputPos)
	{
		_inPos     = inputPos;
		_potMoving = true;
	}

	virtual void read(inputStr_t in) = 0;

protected: 
	uint8_t _inPos;
	uint16_t _cState; // current state
	uint16_t _pState; // previous state
	uint16_t _potVar; // prev/current variation
	uint16_t _lastCcValue;

	const uint8_t TIMEOUT       = 50;
	const uint8_t VAR_THRESHOLD = 8;
	bool _potMoving;
	uint32_t _pTime;
	uint32_t _timer;
};
#endif
