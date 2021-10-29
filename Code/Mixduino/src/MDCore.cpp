#include "MDCore.h"

Muxer muxLeft(MUXSW_LEFT_SIG, MUX_PINS, T_SW_MUX_LEFT);
Muxer muxRight(MUXSW_RIGHT_SIG, MUX_PINS, T_SW_MUX_RIGHT);
MDShifter mdsLeft(FBL_SIG, FBL_LATCH, SRCLK, 1);
MDShifter mdsRight(FBR_SIG, FBR_LATCH, SRCLK, 1);
NPKit npKit(T_NPIXELS, NP_DATA);


void MDCore::begin(void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    muxLeft.begin();
    muxRight.begin();
    npKit.begin();
    funcNoteOn = funcOn;
    funcNoteOff = funcOff;
};

void MDCore::createLeftFuncs() {
    MDFunc cueLeftFunc(&muxLeft, SWCUE_L, &mdsLeft, OUT_CUE_DECK_A);
    MDFunc playLeftFunc(&muxLeft, SWPLAY_L, &mdsLeft, OUT_PLAY_DECK_A);
    MDFunc loopLeftFunc(&muxLeft, SWLOOP_L, &mdsLeft, OUT_LOOP_DECK_A);
    MDFunc syncLeftFunc(&muxLeft, SWSYNC_L, &npKit, NP_SYNC_L);
    MDModeFunc modeLeftFunc(&muxLeft, SWMODE_L, &npKit, NP_MODE_L);
    createPadFuncs(MuxPadLeftSet, npPadLeftSet, _leftPadFuncs, DECK_LEFT_PAD_FUNCS_MIDI_CH);
};

void MDCore::createRightFuncs() {
	MDFunc cueRightFunc(&muxRight, SWCUE_R, &mdsRight, OUT_CUE_DECK_B);
    MDFunc playRightFunc(&muxRight, SWPLAY_R, &mdsRight, OUT_PLAY_DECK_B);
    MDFunc loopRightFunc(&muxRight, SWLOOP_R, &mdsRight, OUT_LOOP_DECK_B);
    MDFunc syncRightFunc(&muxRight, SWSYNC_R, &npKit, NP_SYNC_R);
    MDModeFunc modeRightFunc(&muxRight, SWMODE_R, &npKit, NP_MODE_R);
    createPadFuncs(MuxPadRightSet, npPadRightSet, _rightPadFuncs, DECK_RIGHT_PAD_FUNCS_MIDI_CH);
};

void MDCore::createPadFuncs(uint8_t* swPads, uint8_t* npPads, MDPadFunc* pSet, uint8_t midiCh)
{
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        MDPadFunc padFunc(&muxLeft, swPads[i], &npKit, npPads[i]);
        padFunc.setMidi(midiCh, i);
        pSet[i] = padFunc;
    }
};
