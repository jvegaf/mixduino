

#pragma once
#ifndef MD_INPUT_H
#define MD_INPUT_H

#include "InputBase.h"
#include <Arduino.h>

class Input : public InputBase
{

public:
	Input(uint8_t inputIndex);
	Input(uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
	Input() = default;

	virtual void read(uint8_t midiCh, uint8_t note) const;

protected:
	void (*_funOn)(uint8_t, uint8_t, uint8_t);
	void (*_funOff)(uint8_t, uint8_t, uint8_t);
};

#endif // MUXINPUT_H
