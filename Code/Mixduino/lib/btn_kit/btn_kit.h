
#pragma once
#ifndef BTN_KIT_H
#define BTN_KIT_H

#include <Arduino.h>
#include <MIDI.h>
#include <Multiplexer4067.h>
#include <md_state.h>
#include <md_pinmap.h>
#include <sw_muxmap.h>

class BtnKit
{
	public:
		BtnKit(const uint8_t* arduinoPins, const uint8_t tPins)
		{
		    totalPins = tPins;
		    pins = new uint8_t[totalPins];
		    for (uint8_t i = 0; i < totalPins; i++)
		    {
		        pins[i] = arduinoPins[i];
		    }
		    pState = new int[totalPins]();
		    cState = new int[totalPins]();
		    lastdebouncetime = new unsigned long[totalPins]();
		}

		BtnKit() = default;

		void begin()
		{
		    for (uint8_t i = 0; i < totalPins; i++)
		    {
		        pinMode(pins[i], INPUT_PULLUP);
		    }
		}
		
		MDState::StateType read(uint8_t input_pos)
		{

		    cState[input_pos] = digitalRead(pins[input_pos]);

		    if ((millis() - lastdebouncetime[input_pos]) > debouncedelay)
		    {
		        if (cState[input_pos] != pState[input_pos])
		        {
		            lastdebouncetime[input_pos] = millis();

		            if (cState[input_pos] == LOW)
		            {
		                pState[input_pos] = cState[input_pos];
		                return MDState::StateType::TURN_OFF; // envia NoteOn(nota, velocity, canal midi)
		            }
		            else
		            {
		                pState[input_pos] = cState[input_pos];
		                return MDState::StateType::TURN_ON;
		            }
		        }
		        return MDState::StateType::SAME_STATE;
		    }
		}
	private:
		uint8_t *pins;
		uint8_t totalPins;
		int *pState;
		int *cState;

		unsigned long* lastdebouncetime;
		unsigned long debouncedelay = 20;
};

#endif // BTN_KIT_H
