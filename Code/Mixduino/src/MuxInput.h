

#pragma once
#ifndef MUXINPUT_H
#define MUXINPUT_H

#include "Input.h"
#include <Arduino.h>

class MuxInput : public Input
{

public:
	MuxInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex);
	MuxInput(const uint8_t *mxPins, uint8_t sig, uint8_t inputIndex, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
	MuxInput() = default;
	virtual void read(uint8_t midiCh, uint8_t note);

protected:
	uint8_t _mxSigPin;
	const uint8_t *_mxPins;
	void setMuxChannel(uint8_t channel);
};

#endif // MUXINPUT_H
