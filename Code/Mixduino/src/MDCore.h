
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include "SRKit.h"
#include "NPKit.h"
#include "pin_map.h"
#include "sr_map.h"
#include "midi_map.h"

class MDCore  
{
	public:
		MDCore();
		void begin();
		void cChange(uint8_t number, uint8_t value);
		void noteOn(uint8_t channel, uint8_t number, uint8_t value);
		void noteOff(uint8_t channel, uint8_t number);

	private:
		void fbOn(uint8_t number, uint8_t value);
		uint8_t getIdx(uint8_t* controlSet, uint8_t controlNum);
		uint8_t getIdx(uint16_t* controlSet, uint8_t controlNum);
		void send(uint16_t dataSet)

};
#endif
