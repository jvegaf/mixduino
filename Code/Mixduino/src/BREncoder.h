
#ifndef ARDUINO_BRENCODER_H
#define ARDUINO_BRENCODER_H
#include <Arduino.h>
#include <Encoder.h>
#include "pin_map.h"


class BREncoder  
{
	private:
		long oldPosition;
		Encoder* enc;
	public:
		BREncoder(uint8_t pin_a, uint8_t pin_b);
		BREncoder() = default;
		void readEnc(void (*scc_func)(uint8_t, uint8_t, uint8_t));
};
#endif
