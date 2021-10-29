
#ifndef ARDUINO_MDCORE_H
#define ARDUINO_MDCORE_H
#include <Arduino.h>
#include <MDShifter.h>
#include <Muxer.h>
#include <MDFunc.h>
#include <MDPadFunc.h>
#include <MDModeFunc.h>
#include "midi_map.h"
#include "sw_muxmap.h"
#include "md_pinmap.h"
#include "feedback.h"

class MDCore
{
public:
	MDCore();
	void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

private:
	void (*funcNoteOn)(uint8_t, uint8_t, uint8_t); // number value channel
	void (*funcNoteOff)(uint8_t, uint8_t, uint8_t);
	MDPadFunc _leftPadFuncs[T_DECK_PADS];
	MDPadFunc _rightPadFuncs[T_DECK_PADS];
	void createLeftFuncs();
	void createRightFuncs();

	void createPadFuncs(uint8_t* swPads, uint8_t* npPads, MDPadFunc* pSet, uint8_t midiCh);
};
#endif
