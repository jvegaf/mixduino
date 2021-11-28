#pragma once
#ifndef MD_FXUNIT_H
#define MD_FXUNIT_H
#include "ButtonMidi.h"
#include "Pot.h"

class FXUnit
{

public:
	FXUnit(Pot *pots, ButtonMidi *btns)
		: m_pots{pots}, m_btns{btns}
	{
	}

	FXUnit() = default;

	void readButtons()
	{
		for (uint8_t i = 0; i < T_FX_BTNS; i++) {
			m_btns[i].read();
		}
	}

	void readPots()
	{
		for (uint8_t i = 0; i < T_FX_POTS; i++) {
			m_pots[i].read();
		}
	}

	void setTo(uint8_t number, uint8_t value)
	{
		m_btns[number].setTo(value);
	}

private:
	Pot *m_pots;
	ButtonMidi *m_btns;
};
#endif
