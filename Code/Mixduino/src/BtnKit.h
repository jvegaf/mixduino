#pragma once

#include <Arduino.h>

class BtnKit
{
private:
	uint8_t const *pins;
	uint8_t const *midiNotes;
	const uint8_t totalPins;
	int *pState;
	int *cState;

	unsigned long* lastdebouncetime;
	unsigned long debouncedelay = 20;
public:
	BtnKit(uint8_t* const arduinoPins, uint8_t* const notes, const uint8_t tPins); 
	void initialize();
	void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), uint8_t midiCh);
};
