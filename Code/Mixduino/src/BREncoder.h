
#ifndef ARDUINO_BRENCODER_H
#define ARDUINO_BRENCODER_H
#include <Arduino.h>
#include <Encoder.h>
#include "pin_map.h"


class BREncoder  
{
	private:
		long oldPositionL;
		long oldPositionR;
		void read();
	public:
		BREncoder();
		void readEnc(void (*scc_func)(byte, byte, byte));
};
#endif
