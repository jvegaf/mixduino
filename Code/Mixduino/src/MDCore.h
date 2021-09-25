
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include <Shifter.h>
#include <Npixel.h>
#include <Align.h>
#include "VUmeter.h"
#include "NPKit.h"
#include "pin_map.h"
#include "np_map.h"
#include "sr_fb_map.h"

class MDCore  
{
	public:
		void begin();
		void cChange(byte channel, byte number, byte value);
		void noteOn(byte channel, byte number, byte value);
		void noteOff(byte channel, byte number, byte value);

	private:
		void vuChange(byte number, byte value);
		void npChange(byte position, byte value);
		void setInitialDeckB();
};
#endif
