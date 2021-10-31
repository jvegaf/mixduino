

#pragma once
#ifndef DECK_H
#define DECK_H

#include <md_mode.h>
#include <Arduino.h>
#include <deck_str.h>

#include <Adafruit_NeoPixel.h>
class Deck
{

	private:
		Pad* padp;
		MDMode::ModeType _deckMode = MDMode::ModeType::HOTCUE;
		MDModeFunc* modeFunc;
		MDFunc* dFuncs;
		uint8_t midiChannel;
		
		void (*funcNoteOn)(uint8_t, uint8_t, uint8_t); // number value channel
		void (*funcNoteOff)(uint8_t, uint8_t, uint8_t);
		
		void readPadMode();
		MDMode::ModeType incrementMode(MDMode::ModeType pMode);

	public:
		Deck(DeckAggr aggr)
		{
		    padp = aggr.pp;
		    modeFunc = aggr.modeFunc;
		    dFuncs = aggr.funcs;
		    funcNoteOn = aggr.funcOn;
		    funcNoteOff = aggr.funcOff;
		}

		Deck() = default;

		void read()
		{
		    readPadMode();
		    for (uint8_t i = 0; i < 4U; i++)
		    {
		        this->dFuncs[i].read(funcNoteOn, funcNoteOff);
		    }
		}
		void onNoteOn(uint8_t number, uint8_t value)
		{
		    this->dFuncs[number].onChange(MDState::StateType::TURN_ON);
		} 
		void onNoteOff(uint8_t number, uint8_t value)
		{
		    this->dFuncs[number].onChange(MDState::StateType::TURN_OFF);
		}
};



#endif // DECK_H
