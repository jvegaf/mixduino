#pragma once
#ifndef MD_PAD_H
#define MD_PAD_H
#include "ButtonPad.h"
#include "md_defs.h"
#include <Arduino.h>

class Pad
{
public:
	Pad(ButtonPad *btnPads)
	{
		_btnPads = btnPads;
	}

	void setNote(uint8_t note)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setNote(note + i);
		}
	}

	void read()
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].read();
		}
	}

	void setTo(uint8_t value)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setTo(value);
		}
	}

	void setTo(uint8_t position, uint8_t value)
	{
		_btnPads[position].setTo(value);
	}

	void setTo(uint8_t* values)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setTo(values[i]);
		}
	}

private:
	ButtonPad *_btnPads;
};
#endif
