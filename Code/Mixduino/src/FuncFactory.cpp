#include "FuncFactory.h"

FuncFactory::FuncFactory(NPKit *npkit, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    _npkit = npkit;
    fOn = funcOn;
    fOff = funcOff;
    _shfLeft = new Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1);
    _shfRight = new Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1);
}

void FuncFactory::begin()
{
    Input** blindIns = createBlindInputs();
    _blindFuncs = createFuncsBase(blindIns, IN_ONLY_CH, blindMidiSet, T_MIDI_BLIND_SET);
    
    Input** ins = createInputs();
    OutputBase** outs = createOutputs();
    _funcs = createFuncs(ins, outs, IN_OUT_CH, midiSet, T_MIDI_SET);
    
    Input** leftInPads = createInputPads(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SW_PADL_BUNDLE, fOn, fOff);
    OutputBase** leftOutPads = createOutputPads(_npkit, PIXLS_PAD_L);
    _leftFuncPads = createFuncPads(leftInPads, leftOutPads, LEFT_PAD_CH, T_DECK_PADS);
    
    Input** rightInPads = createInputPads(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SW_PADR_BUNDLE, fOn, fOff);
    OutputBase** rightOutPads = createOutputPads(_npkit, PIXLS_PAD_R);
    _rightFuncPads = createFuncPads(rightInPads, rightOutPads, RIGHT_PAD_CH, T_DECK_PADS);

}

FuncMode *FuncFactory::createLeftModeFunc()
{
    ModeInput *modeLIn = new ModeInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWMODE_L);
    FBPixel *modeLOut = new FBPixel(_npkit, NP_MODE_L);
    return new FuncMode(modeLIn, modeLOut);
}

FuncMode *FuncFactory::createRightModeFunc()
{
    ModeInput *modeRIn = new ModeInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWMODE_R);
    FBPixel *modeROut = new FBPixel(_npkit, NP_MODE_R);
    return new FuncMode(modeRIn, modeROut);
}

FuncBase *FuncFactory::createFuncsBase(Input **inAggr, uint8_t midiCh, const uint8_t *notesAggr, uint8_t t_funcs)
{
    FuncBase *funcSet = new FuncBase[t_funcs];
    for (uint8_t i = 0; i < t_funcs; i++)
    {
        funcSet[i] = FuncBase(inAggr[i], midiCh, notesAggr[i]);
    }
    return funcSet;
}

Func *FuncFactory::createFuncs(Input **inAggr, OutputBase **outAggr, uint8_t midiCh, const uint8_t *notesAggr, uint8_t t_funcs)
{
    Func *funcSet = new Func[t_funcs];
    for (uint8_t i = 0; i < t_funcs; i++)
    {
        funcSet[i] = Func(inAggr[i], outAggr[i], midiCh, notesAggr[i]);
    }
    return funcSet;
}

Input **FuncFactory::createBlindInputs()
{
    Input *shiftIn = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWSHIFT, fOn, fOff);
    Input *brwsLIn = new ArduInput(SW_BROWSER_L, fOn, fOff);
    Input *brwsRIn = new ArduInput(SW_BROWSER_R, fOn, fOff);
    Input *prevIn = new ArduInput(SWBR_PREVIEW, fOn, fOff);
    Input *backIn = new ArduInput(SWBR_BACK, fOn, fOff);
    Input* res[] = {
        shiftIn,
        brwsLIn,
        brwsRIn,
        prevIn,
        backIn
    };
    return res;
}

Input **FuncFactory::createInputs()
{
    Input *playLIn = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWPLAY_L, fOn, fOff);
    Input *cueLIn = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWCUE_L, fOn, fOff);
    Input *loopLIn = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWLOOP_L, fOn, fOff);
    Input *syncLIn = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWSYNC_L, fOn, fOff);
    Input *playRIn = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWPLAY_R, fOn, fOff);
    Input *cueRIn = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWCUE_R, fOn, fOff);
    Input *loopRIn = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWLOOP_R, fOn, fOff);
    Input *syncRIn = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWSYNC_R, fOn, fOff);
    Input *deckSelIn = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWDECK_SEL, fOn, fOff);
    Input *cueL1In = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWPCUEL1, fOn, fOff);
    Input *cueL2In = new MuxInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWPCUEL2, fOn, fOff);
    Input *cueL3In = new MuxInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWPCUEL3, fOn, fOff);
    Input *fx1LIn = new ArduInput(SWFXL_1, fOn, fOff);
    Input *fx2LIn = new ArduInput(SWFXL_2, fOn, fOff);
    Input *fx3LIn = new ArduInput(SWFXL_3, fOn, fOff);
    Input *fx1RIn = new ArduInput(SWFXR_1, fOn, fOff);
    Input *fx2RIn = new ArduInput(SWFXR_2, fOn, fOff);
    Input *fx3RIn = new ArduInput(SWFXR_3, fOn, fOff);
    Input *res[] = {
        playLIn,cueLIn,loopLIn,syncLIn,playRIn,cueRIn,
        loopRIn,syncRIn,deckSelIn,cueL1In,cueL2In,cueL3In,
        fx1LIn,fx2LIn,fx3LIn,fx1RIn,fx2RIn,fx3RIn};
    return res;
}

OutputBase **FuncFactory::createOutputs()
{
    OutputBase *playLOut = new FBLed(_shfLeft, OUT_PLAY_L);
    OutputBase *syncLOut = new FBPixel(_npkit, NP_SYNC_L);
    OutputBase *syncROut = new FBPixel(_npkit, NP_SYNC_R);
    OutputBase *deckSelOut = new FBPixel(_npkit, NP_DECK_SEL);
    OutputBase *cueLOut = new FBLed(_shfLeft, OUT_CUE_L);
    OutputBase *loopLOut = new FBLed(_shfLeft, OUT_LOOP_L);
    OutputBase *fx1LOut = new FBLed(_shfLeft, OUT_FX1_L);
    OutputBase *fx2LOut = new FBLed(_shfLeft, OUT_FX2_L);
    OutputBase *fx3LOut = new FBLed(_shfLeft, OUT_FX3_L);
    OutputBase *playROut = new FBLed(_shfRight, OUT_PLAY_R);
    OutputBase *cueROut = new FBLed(_shfRight, OUT_CUE_R);
    OutputBase *loopROut = new FBLed(_shfRight, OUT_LOOP_R);
    OutputBase *fx1ROut = new FBLed(_shfRight, OUT_FX1_R);
    OutputBase *fx2ROut = new FBLed(_shfRight, OUT_FX2_R);
    OutputBase *fx3ROut = new FBLed(_shfRight, OUT_FX3_R);
    OutputBase* res[] = {
        playLOut,
        syncLOut,
        syncROut,
        deckSelOut,
        cueLOut,
        loopLOut,
        fx1LOut,
        fx2LOut,
        fx3LOut,
        playROut,
        cueROut,
        loopROut,
        fx1ROut,
        fx2ROut,
        fx3ROut
    };
    return res;
}

OutputBase** FuncFactory::createOutputPads(NPKit *npk, const uint8_t *positions)
{
    OutputBase **outPads = new OutputBase*[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        FBPixel *pix = new FBPixel(npk, positions[i]);
        outPads[i] = pix;
    }
    return outPads;
}

Input **FuncFactory::createInputPads(const uint8_t *mxPinBundle, uint8_t sigPin, const uint8_t *positions, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    Input **muxInPads = new Input*[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        MuxInput *mux = new MuxInput(mxPinBundle, sigPin, positions[i], funcOn, funcOff);
        muxInPads[i] = mux;
    }
    return muxInPads;
}

FuncPad* FuncFactory::createFuncPads(Input **inAggr, OutputBase **outAggr, uint8_t midiCh, uint8_t t_funcs)
{
    FuncPad funcSet[t_funcs];
    for (uint8_t i = 0; i < t_funcs; i++)
    {
        funcSet[i] = Func(inAggr[i], outAggr[i], midiCh, i);
    }
    return funcSet;
}