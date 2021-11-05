
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include "BtnKit.h"
#include "MDMode.h"
#include "Muxer.h"
#include "MuxerPad.h"
#include "NPKit.h"
#include "PixGroup.h"
#include "VUmeter.h"
#include "np_map.h"
#include "pin_map.h"
#include "sr_fb_map.h"
#include "sw_muxmap.h"
#include "Feedback.h"

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
	Shifter* _shfLeft;
	Shifter* _shfRight;
	NPKit* _npkit;
	PixGroup* _pgLeftPad;
	PixGroup* _pgRightPad;
	MDMode* _deckLeftMode;
	MDMode* _deckRightMode;
	MuxerPad* _leftPadBtns;
	MuxerPad* _rightPadBtns;
	Muxer* _leftBtns;
	Feedback* _leftFB;
	Muxer* _rightBtns;
	Feedback* _rightFB;
	void (*fnon)(uint8_t, uint8_t, uint8_t);
	void (*fnoff)(uint8_t, uint8_t, uint8_t);
	void vuChange(uint8_t number, uint8_t value);
	void npChange(uint8_t position, uint8_t value);
	void setInitialDeckB();

	void checkDeckMode(Align al);
	void readDecksMode();
};
#endif
