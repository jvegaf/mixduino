
#ifndef ARDUINO_POTKIT_H
#define ARDUINO_POTKIT_H
#include <Arduino.h>
#include <Multiplexer4067.h>
#include "pin_map.h"
#include "pots_muxmap.h"

class PotKit  
{
	private:

	public:
		void begin();
		void read(void (*scc_func)(uint8_t, uint8_t, uint8_t));

};
#endif
