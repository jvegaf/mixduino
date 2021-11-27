#pragma once
#ifndef MD_PAD_H
#define MD_PAD_H
#include "ButtonMidi.h"
#include "ButtonFunc.h"
#include "md_defs.h"

class Pad
{
public:
	Pad(ButtonMidi *btnPads, ButtonFunc *btnMode)
	{
		_btnMode = btnMode;
		_btnPads = btnPads;
	}

	void setMidiChannel(uint8_t channel)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setMidiChannel(channel);
		}
	}

	void setNote(uint8_t note)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setMidiNote(note + i);
		}
	}

	void read()
	{
		_btnMode->read();
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].read();
		}
	}

	void setAllTo(uint8_t value)
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

	void setTo(uint8_t *values)
	{
		for (uint8_t i = 0; i < T_DECK_PADS; i++)
		{
			_btnPads[i].setTo(values[i]);
		}
	}

private:
	ButtonMidi *_btnPads;
	ButtonFunc* _btnMode;
};
#endif
