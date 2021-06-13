
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
		BREncoder(byte pin_a, byte pin_b);
		void readEnc(void (*scc_func)(byte, byte, byte));
};
#endif
