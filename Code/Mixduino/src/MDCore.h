
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include <Shifter.h>
#include "Muxer.h"
#include "BtnKit.h"
#include "VUmeter.h"
#include "NPKit.h"
#include "pin_map.h"
#include "np_map.h"
#include "sr_fb_map.h"

class MDCore  
{
	private:
		void (*fnon)(uint8_t, uint8_t, uint8_t);
		void (*fnoff)(uint8_t, uint8_t, uint8_t);
		void vuChange(uint8_t number, uint8_t value);
		void npChange(uint8_t position, uint8_t value);
		void setInitialDeckB();
	
	public:
		void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
		void onCChange(uint8_t channel, uint8_t number, uint8_t value);
		void onNoteOn(uint8_t channel, uint8_t number, uint8_t value);
		void onNoteOff(uint8_t channel, uint8_t number, uint8_t value);
		void readButtons();

};
#endif
