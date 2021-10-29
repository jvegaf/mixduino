
#ifndef ARDUINO_MUXER_H
#define ARDUINO_MUXER_H
#include <Arduino.h>
#include <InputBase.h>
#include <MDState.h>
#include "md_pinmap.h"

class Muxer : public InputBase
{
private:
	uint8_t muxSIG;
	uint8_t* MUX_PINS;
	uint8_t totalMuxPins;
	int* pState;
	int* cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
	
	void setMuxChannel(uint8_t channel);

public:
	Muxer(uint8_t sig, const uint8_t* mPins, const uint8_t nPins);
	void begin();
	MDState read(uint8_t input_pos);
};
#endif
