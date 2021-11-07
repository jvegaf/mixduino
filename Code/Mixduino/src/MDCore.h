
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include "NPKit.h"
#include "VUmeter.h"
#include "FuncFactory.h"
#include "FuncMode.h"
#include "Pad.h"
#include "md_defs.h"

class MDCore
{
public:
	MDCore();
	enum Align
	{
		LEFT,
		RIGHT
	};
	void incDeckMode(uint8_t al);
	void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));
	void onCChange(uint8_t channel, uint8_t number, uint8_t value);
	void onNoteOn(uint8_t channel, uint8_t number, uint8_t value);
	void onNoteOff(uint8_t channel, uint8_t number, uint8_t value);
	void readButtons();

private:
	NPKit* _npkit;
	FuncMode* _leftFuncMode;
	FuncMode* _rightFuncMode;
	Pad* _leftPad;
	Pad* _rightPad;
	Func* _funcs;
	FuncBase* _blindFuncs;
	void handlePadNoteChange(State nState, FuncMode *deckMD, Pad* pad, uint8_t number, uint8_t value);
	void (*fnon)(uint8_t, uint8_t, uint8_t);
	void (*fnoff)(uint8_t, uint8_t, uint8_t);
	void vuChange(uint8_t number, uint8_t value);
	void readDecksMode();
	void checkDeckMode(FuncMode* fm, Pad* p);
	void onNoteChange(uint8_t channel, uint8_t number, uint8_t value);
	// void setInitialDeckB();
};
#endif
