
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include <Npixel.h>
#include <Align.h>
#include "SRKit.h"
#include "NPKit.h"
#include "pin_map.h"
#include "sr_map.h"
#include "np_map.h"
#include "midi_map.h"
#include <Shifter.h>

class MDCore  
{
	public:
		void begin();
		void cChange(byte channel, byte number, byte value);
		void noteOn(byte channel, byte number, byte value);
		void noteOff(byte channel, byte number, byte value);

	private:
		void vuChange(byte number, byte value);
		void npPadChange(Align al, byte position, byte value);
		void npFBChange(Align al, byte position, byte value);
		void setInitialDeckB();




};
#endif
