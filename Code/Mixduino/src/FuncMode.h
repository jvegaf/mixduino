#pragma once
#ifndef FUNCMODE_H
#define FUNCMODE_H
#include <Arduino.h>
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
	FuncMode(const uint8_t *mxPins, uint8_t muxSig, uint8_t inPos, OutputBase *output);
	deckMode getMode();
	uint8_t getModeNote();
	uint8_t getModeColor();
	uint8_t getSelectorModeColor();
	boolean isDisposed();
	void dispose();
	void incrementMode();
	void read();

private:
	const uint8_t* _mxPins;
	uint8_t _muxSig;
	uint8_t _inPos;
	int _pState;
    int _cState;
    unsigned long _lastdebouncetime;
	const unsigned long DEBOUNCE_DELAY = 20;
	OutputBase* _out;
	deckMode _dMode;
	uint8_t _modeNote;
	uint8_t _modeColor;
	boolean _disposed;

	void setMuxChannel(uint8_t channel);

};
#endif
