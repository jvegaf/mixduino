#include "MDCore.h"

uint8_t npPadLeftSet[] = {
    NP_PADL1,
    NP_PADL2,
    NP_PADL3,
    NP_PADL4,
    NP_PADL5,
    NP_PADL6,
    NP_PADL7,
    NP_PADL8
};

uint8_t npPadRightSet[] = {
    NP_PADR1,
    NP_PADR2,
    NP_PADR3,
    NP_PADR4,
    NP_PADR5,
    NP_PADR6,
    NP_PADR7,
    NP_PADR8
};

uint8_t muxPadLeftSet[] = {
    SWPADL1,
    SWPADL2,
    SWPADL3,
    SWPADL4,
    SWPADL5,
    SWPADL6,
    SWPADL7,
    SWPADL8};

uint8_t muxPadRightSet[] = {
    SWPADR1,
    SWPADR2,
    SWPADR3,
    SWPADR4,
    SWPADR5,
    SWPADR6,
    SWPADR7,
    SWPADR8
};

Deck MDCore::createLeftDeck(Pad lefPad) {
    MDFunc cueLeftFunc( &muxLeft, SWCUE_L, &mdsLeft, OUT_CUE_DECK_A);
    MDFunc playLeftFunc(&muxLeft, SWPLAY_L, &mdsLeft, OUT_PLAY_DECK_A);
    MDFunc loopLeftFunc(&muxLeft, SWLOOP_L, &mdsLeft, OUT_LOOP_DECK_A);
    MDFunc syncLeftFunc(&muxLeft, SWSYNC_L, &npKit, NP_SYNC_L);
    MDFunc lfuncs[] = {cueLeftFunc, playLeftFunc, loopLeftFunc, syncLeftFunc};
    MDModeFunc modeLeftFunc(&muxLeft, SWMODE_L, &npKit, NP_MODE_L);
    Deck dl = Deck((DeckAggr){&lefPad, &modeLeftFunc, lfuncs, DECK_LEFT_FUNCS_MIDI_CH, funcNoteOn, funcNoteOff });
    return dl;
};

Deck MDCore::createRightDeck(Pad rpad) {
	MDFunc cueRightFunc(&muxRight, SWCUE_R, &mdsRight, OUT_CUE_DECK_B);
    MDFunc playRightFunc(&muxRight, SWPLAY_R, &mdsRight, OUT_PLAY_DECK_B);
    MDFunc loopRightFunc(&muxRight, SWLOOP_R, &mdsRight, OUT_LOOP_DECK_B);
    MDFunc syncRightFunc(&muxRight, SWSYNC_R, &npKit, NP_SYNC_R);
    MDFunc rFuncs[] = {cueRightFunc, playRightFunc, loopRightFunc, syncRightFunc};
    MDModeFunc modeRightFunc(&muxRight, SWMODE_R, &npKit, NP_MODE_R);
    Deck dr = Deck((DeckAggr){&rpad, &modeRightFunc, rFuncs, DECK_RIGHT_FUNCS_MIDI_CH, funcNoteOn, funcNoteOff});
    return dr;
};

Pad MDCore::createLeftPad() {
    MDPadFunc* pfuncs = createPadFuncs(muxPadLeftSet, npPadLeftSet, DECK_LEFT_PAD_FUNCS_MIDI_CH);
	Pad lpad = Pad((PadAggr){pfuncs, DECK_LEFT_PAD_FUNCS_MIDI_CH, funcNoteOn, funcNoteOff});
    return lpad; 
}

    
Pad MDCore::createRightPad() {
	MDPadFunc* pfuncs = createPadFuncs(muxPadRightSet, npPadRightSet, DECK_RIGHT_PAD_FUNCS_MIDI_CH);
    Pad rpad = Pad((PadAggr){pfuncs, DECK_RIGHT_PAD_FUNCS_MIDI_CH, funcNoteOn, funcNoteOff});
    return rpad;
}



MDPadFunc* MDCore::createPadFuncs(uint8_t* inputSet, uint8_t* outPutSet, uint8_t midiCh)
{
    MDPadFunc* ppfuncs = new MDPadFunc[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        MDPadFunc padFunc(&muxLeft, inputSet[i], &npKit, outPutSet[i]);
        padFunc.setMidi(midiCh, i);
        ppfuncs[i] = padFunc;
    }
    return ppfuncs;
};
