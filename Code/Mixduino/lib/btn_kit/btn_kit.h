
#pragma once
#ifndef BTN_KIT_H
#define BTN_KIT_H

#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>
#include <md_defs.h>
#include "input_base.h"
#include <md_pinmap.h>
#include <sw_muxmap.h>

class BtnKit : public InputBase
{
public:
	BtnKit(const uint8_t *arduinoPins, const uint8_t tPins)
	{
		totalPins = tPins;
		pins = new uint8_t[totalPins];
		for (uint8_t i = 0; i < totalPins; i++)
		{
			pins[i] = arduinoPins[i];
		}
		pState = new int[totalPins]();
		cState = new int[totalPins]();
		lastdebouncetime = new unsigned long[totalPins]();
	}

	void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t), uint8_t midCh)
	{
		fnon = funcOn;
		fnoff = funcOff;
		_midiChannel = midCh;
		for (uint8_t i = 0; i < totalPins; i++)
		{
			pinMode(pins[i], INPUT_PULLUP);
		}
	}

	void read(uint8_t input_pos, uint8_t noteIndex)
	{

		cState[input_pos] = digitalRead(pins[input_pos]);

		if ((millis() - lastdebouncetime[input_pos]) > debouncedelay)
		{
			if (cState[input_pos] != pState[input_pos])
			{
				lastdebouncetime[input_pos] = millis();

				if (cState[input_pos] == LOW)
				{
					fnon(noteIndex, 127, _midiChannel);
				}
				else
				{
					fnoff(noteIndex, 127, _midiChannel);
				}
				pState[input_pos] = cState[input_pos];
			}
		}
	}

private:
	uint8_t *pins;
	uint8_t totalPins;
	int *pState;
	int *cState;
	uint8_t _midiChannel;
	void (*fnon)(uint8_t, uint8_t, uint8_t);
	void (*fnoff)(uint8_t, uint8_t, uint8_t);

	unsigned long *lastdebouncetime;
	unsigned long debouncedelay = 20;
};

#endif // BTN_KIT_H
