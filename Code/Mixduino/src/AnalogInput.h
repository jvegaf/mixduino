#pragma once
#ifndef MD_ANALOG_INPUT_H
#define MD_ANALOG_INPUT_H
#include "Input.h"

class AnalogInput : public Input
{
public:
	AnalogInput(uint8_t inputPos)
		: _inPos{inputPos}
	{
	}

	AnalogInput() = default;

	virtual void read(inputStr_t in) = 0;

protected:
	uint8_t _inPos{0};
	uint16_t _cState{0}; // current state
	uint16_t _pState{0}; // previous state
	uint16_t _potVar{0}; // prev/current variation
	uint16_t _lastCcValue{0};

	const uint8_t TIMEOUT = 50;
	const uint8_t VAR_THRESHOLD = 8;
	bool _potMoving{true};
	uint32_t _pTime{0};
	uint32_t _timer{0};
};
#endif
