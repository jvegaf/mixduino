
#pragma once
#ifndef MUXERPAD_H
#define MUXERPAD_H

#include <Arduino.h>
#include "Muxer.h"

class MuxerPad : public Muxer
{
private:
	uint8_t _firstNumber;

public:
	MuxerPad(const uint8_t* mxPins, uint8_t sigPin);
	void begin(const uint8_t* swPositions, const uint8_t totalSw, uint8_t midiCh);
	void setNoteNum(uint8_t number);
	void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
};


#endif // MUXERPAD_H
