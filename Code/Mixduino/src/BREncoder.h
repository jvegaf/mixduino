
#ifndef ARDUINO_BRENCODER_H
#define ARDUINO_BRENCODER_H
#include <Arduino.h>
#define ENCODER_DO_NOT_USE_INTERRUPTS
#include <Encoder.h>
#include "pin_map.h"


class BREncoder  
{
	private:
		
	public:
		BREncoder();
		void readEnc(void (*scc_func)(byte, byte, byte));
};
#endif
