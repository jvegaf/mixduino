
#pragma once
#ifndef MDCORE_H
#define MDCORE_H

#include <muxer.h>
#include <sw_muxmap.h>
#include <md_shifter.h>
#include <np_kit.h>
#include <md_midi.h>
#include <md_feedback.h>
#include <Deck.h>


class MDCore
{

	private: 
		Deck deckLeft;
		Deck deckRight;
		Pad padLeft;
		Pad padRight;
		Muxer muxLeft;
		Muxer muxRight;
		MDShifter mdsLeft;
		MDShifter mdsRight;
		NPKit npKit;
		void (*funcNoteOn)(uint8_t, uint8_t, uint8_t); // number value channel
		void (*funcNoteOff)(uint8_t, uint8_t, uint8_t);
		MDPadFunc* leftPadFuncs;
		MDPadFunc* rightPadFuncs;
		Pad createLeftPad();
		Pad createRightPad();
		Deck createLeftDeck(Pad lpad);
		Deck createRightDeck(Pad rpad);
		MDPadFunc* createPadFuncs(uint8_t* inputSet, uint8_t* outputSet, uint8_t midiCh);

	public: 
		MDCore()
		{
			 muxLeft  = Muxer(MUXSW_LEFT_SIG, MUX_PINS, T_SW_MUX_LEFT);
			 muxRight = Muxer(MUXSW_RIGHT_SIG, MUX_PINS, T_SW_MUX_RIGHT);
			 mdsLeft  = MDShifter(FBL_SIG, FBL_LATCH, SRCLK, 1);
			 mdsRight = MDShifter(FBR_SIG, FBR_LATCH, SRCLK, 1);
			 npKit    = NPKit(T_NPIXELS, NP_DATA, NPK_BRIGHTNESS);
		}

		void begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
		{
		    muxLeft.begin();
		    muxRight.begin();
		    npKit.begin();
		    funcNoteOn  = funcOn;
		    funcNoteOff = funcOff;
		    padLeft     = createLeftPad();
		    padRight    = createRightPad();
		    deckLeft    = createLeftDeck(padLeft);
		    deckRight   = createRightDeck(padRight);
		};

		Deck* getDeck(MDAlign::AlignType al) {
			if (al == MDAlign::AlignType::LEFT_ALIGN)
		    {
		        return &deckLeft;
		    }
		    return &deckRight;
		}

		Pad* getPad(MDAlign::AlignType al) {
			if (al == MDAlign::AlignType::LEFT_ALIGN)
		    {
		        return &padLeft;
		    }

		    return &padRight;
		}

};


#endif // MDCORE_H
