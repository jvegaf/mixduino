#pragma once
#include "pin_map.h"
#include "pots_muxmap.h"
#include <Arduino.h>
#include <Multiplexer4067.h>

namespace input
{
	class PotKit
	{
	private:
	public:
		void begin();
		void read(void (*scc_func)(uint8_t, uint8_t, uint8_t));
	};

} // namespace input
