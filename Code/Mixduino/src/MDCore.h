
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include <Shifter.h>
#include <Align.h>
#include "VUmeter.h"
#include "NPKit.h"
#include "pin_map.h"
#include "np_map.h"

class MDCore  
{
	public:
		void begin();
		void cChange(uint8_t channel, uint8_t number, uint8_t value);
		void noteOn(uint8_t channel, uint8_t number, uint8_t value);
		void noteOff(uint8_t channel, uint8_t number, uint8_t value);

	private:
		void vuChange(uint8_t number, uint8_t value);
		void npChange(uint8_t position, uint8_t value);
};
#endif
