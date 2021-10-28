
#ifndef ARDUINO_DECK_H
#define ARDUINO_DECK_H
#include <Arduino.h>
#include "modules.h"
#include "Mode.h"

class Deck  
{
	public:
		Deck(DeckAggregate aggr);
		void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t), Adafruit_NeoPixel *aNP);
		void read();
		void onNoteOn(uint8_t channel, uint8_t number, uint8_t value); 
		void onNoteOff(uint8_t channel, uint8_t number, uint8_t value);

	private:
		Mode deckMode = Mode::HOTCUE;
		MDFunc* modeFunc;
		MDFunc* dFuncs;
		void (*funcNoteOn)(uint8_t, uint8_t, uint8_t); // number value channel
		void (*funcNoteOff)(uint8_t, uint8_t, uint8_t);
		void readPadMode();
		Mode incrementMode(Mode pMode);
};

#endif
