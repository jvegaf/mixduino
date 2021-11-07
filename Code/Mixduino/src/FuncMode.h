#pragma once
#ifndef FUNCMODE_H
#define FUNCMODE_H
#include "Func.h"
#include "ModeInput.h"
#include "md_defs.h"
#include <Arduino.h>

enum class deckMode
{
	MODE_HOTCUE,
	MODE_LOOP,
	MODE_FX
};

class FuncMode : public Func
{
public:
	FuncMode(ModeInput *input, OutputBase *output);
	void read();
	deckMode getMode();
	uint8_t getModeNote();
	uint8_t getModeColor();
	uint8_t getSelectorModeColor();
	boolean isDisposed();
	void dispose();

private:
	ModeInput* _in;
	deckMode _dMode;
	uint8_t _modeNote;
	uint8_t _modeColor;
	boolean _disposed;

	void incrementMode();
};
#endif
