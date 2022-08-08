#pragma once

#include <Arduino.h>

class Muxer
{
private:
	uint8_t muxS0;
	uint8_t muxS1;
	uint8_t muxS2;
	uint8_t muxS3;
	uint8_t muxSIG;
	uint8_t first_note;
	uint8_t* muxPinsGroup;
	uint8_t totalMuxPins;
	int* pState;
	int* cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
	
	void setMuxChannel(uint8_t channel);

public:
	Muxer(uint8_t s0, uint8_t s1, uint8_t s2, uint8_t s3, uint8_t sig);
	void initialize(const uint8_t* pins_group, const uint8_t t_pins, uint8_t firstNote);
	void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t midiCh);
};
