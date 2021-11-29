#pragma once
#include "pin_map.h"
#include "sw_muxmap.h"
#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>
#include <EventManager.h>

namespace input
{
	class BtnKit
	{
	private:
		uint8_t *pins;
		uint8_t totalPins;
		int *pState;
		int *cState;

		unsigned long *lastdebouncetime;
		unsigned long debouncedelay = 20;

	public:
		BtnKit(const uint8_t *arduinoPins, const uint8_t tPins);
		void begin();
		void read(EventManager &em);
	};

} // namespace input
