#pragma once
#ifndef FUNCMODE_H
#define FUNCMODE_H
#include <Arduino.h>
#include "ModeInput.h"
#include "OutputBase.h"
#include "md_defs.h"

enum class deckMode
{
	MODE_HOTCUE,
	MODE_LOOP,
	MODE_FX
};


class FuncMode 
{
public:
	typedef void (*CallBack)();
	CallBack cb;
	FuncMode(ModeInput *input, OutputBase *output);
	deckMode getMode();
	uint8_t getModeNote();
	uint8_t getModeColor();
	uint8_t getSelectorModeColor();
	boolean isDisposed();
	void dispose();
	void incrementMode();
	void read();

private:
	ModeInput* _in;
	OutputBase* _out;
	deckMode _dMode;
	uint8_t _modeNote;
	uint8_t _modeColor;
	boolean _disposed;

};
#endif
