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

private:
	Pot *m_pots;
	ButtonMidi *m_btns;
};
#endif
