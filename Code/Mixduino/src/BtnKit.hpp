#pragma once
#include "pin_map.h"
#include "sw_muxmap.h"
#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>

namespace input
{
	class BtnKit
	{
	private:
		uint8_t *pins;
		uint8_t totalPins;
		int *pState;
		int *cState;

		uint8_t midiChannel;

		unsigned long *lastdebouncetime;
		unsigned long debouncedelay = 20;

	public:
		BtnKit(const uint8_t *arduinoPins, const uint8_t tPins);
		void begin(uint8_t midiCh);
		void read(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
	};

} // namespace input