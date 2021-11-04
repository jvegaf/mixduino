
#pragma once
#ifndef MUXERPAD_H
#define MUXERPAD_H

#include <Arduino.h>

class MuxerPad
{
private:
	uint8_t _mxSigPin;
	const uint8_t* _mxPins;
	const uint8_t* _swPositions;
	uint8_t _tMxSwitches;
	int* pState;
	int* cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
	
	uint8_t _midiChannel;
	uint8_t _firstNumber;
	void setMuxChannel(uint8_t channel);

public:
	MuxerPad(const uint8_t* mxPins, uint8_t sigPin);
	void begin(const uint8_t* swPositions, const uint8_t totalSw, uint8_t midiCh);
	void setNoteNum(uint8_t number);
	void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
};


#endif // MUXERPAD_H
