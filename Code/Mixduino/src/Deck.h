
#ifndef ARDUINO_DECK_H
#define ARDUINO_DECK_H
#include <Arduino.h>
#include "base.h"
#include "Mode.h"

class Deck  
{
	private:
		MuxBtn* buttons;
		MuxBtn modeBtn;
		Led* leds;
		Npixel* npixels;
		int totalButtons;
		int totalLeds;
		int totalNpxls;
		Mode mode;

	public:
		Deck(MuxBtnSet bset, LedSet lset, NPxSet npSet);
		begin();
};
#endif
