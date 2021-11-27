#include "FuncFactory.h"

void FuncFactory::begin(
    NPKit *npkit,
    void (*funcOn)(uint8_t, uint8_t, uint8_t),
    void (*funcOff)(uint8_t, uint8_t, uint8_t),
    void (*funcCC)(uint8_t, uint8_t, uint8_t),
    void (*cbModeFunc)(uint8_t),
    void (*cbSelDeck)())
{
    _npkit = npkit;
    _funcOn = funcOn;
    _funcOff = funcOff;
    _funcCC = funcCC;
    _cbModeFunc = cbModeFunc;
    _cbSelDeck = cbSelDeck;
    _shfLeft = new Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1);
    _shfRight = new Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1);
    _mplexTopPots = new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, TOP_POTMUX_SIG);
    _mplexBottomPots = new Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, BOTTOM_POTMUX_SIG);

    _deckSelBtn = createFuncBtn(_npkit, NP_DECK_SEL, MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWDECK_SEL, _cbSelDeck);

    _leftController = makeLeftController();

    _rightController = makeRightController();

    _browser = makeBrowser();

    _mixer = makeMixer();

    _fxUnits = makeFXUnits();
}

ButtonFunc *FuncFactory::createFuncBtn(NPKit *npk, uint8_t outPos, uint8_t *muxPinBnd, uint8_t sigPin, uint8_t inPos, void (*cbFn)())
{
    Output *modeOut = new FBPixel(npk, outPos);
    DigitalInput *modeIn = new MuxDigitalInput(muxPinBnd, sigPin, inPos);
    return new ButtonFunc(modeIn, modeOut, cbFn);
}

ButtonFunc *FuncFactory::createModeBtn(NPKit *npk, uint8_t outPos, uint8_t *muxPinBnd, uint8_t sigPin, uint8_t inPos, void (*cbFn)(uint8_t))
{
    Output *modeOut = new FBPixel(npk, outPos);
    DigitalInput *modeIn = new MuxDigitalInput(muxPinBnd, sigPin, inPos);
    return new ButtonFunc(modeIn, modeOut, cbFn);
}

ButtonMidi *FuncFactory::createMidiBtns(
    DigitalInput **inAggr,
    Output **outAggr,
    uint8_t midiChannel,
    uint8_t *midiNotes,
    uint8_t t_btns,
    void (*funcOn)(uint8_t, uint8_t, uint8_t),
    void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    ButtonMidi *btnSet = new ButtonMidi[t_btns];
    for (uint8_t i = 0; i < t_btns; i++)
    {
        btnSet[i] = ButtonMidi(inAggr[i], outAggr[i], midiChannel, midiNotes[i], funcOn, funcOff);
    }
    return btnSet;
}

DigitalInput **FuncFactory::createMuxInputs(uint8_t *muxPinBnd, uint8_t sigPin, uint8_t *inPos, uint8_t tInputs)
{
    DigitalInput **res = new DigitalInput *[tInputs];
    for (uint8_t i = 0; i < tInputs; i++)
    {
        res[i] = new MuxDigitalInput(muxPinBnd, sigPin, inPos[i]);
    }
    return res;
}

Controller *FuncFactory::createController(Player *player, Pad *pad)
{
    return new Controller(player, pad);
}

Output **FuncFactory::createPlayerLeftOutputs()
{
    Output **res = new Output *[T_MUX_SW_PLAYER];
    res[0] = new FBLed(_shfLeft, OUT_PLAY_L);
    res[1] = new FBLed(_shfLeft, OUT_CUE_L);
    res[2] = new FBPixel(_npkit, NP_SYNC_L);
    res[3] = new FBLed(_shfLeft, OUT_LOOP_L);
    return res;
}

Output **FuncFactory::createPlayerRightOutputs()
{
    Output **res = new Output *[T_MUX_SW_PLAYER];
    res[0] = new FBLed(_shfRight, OUT_PLAY_R);
    res[1] = new FBLed(_shfRight, OUT_CUE_R);
    res[2] = new FBPixel(_npkit, NP_SYNC_R);
    res[3] = new FBLed(_shfRight, OUT_LOOP_R);
    return res;
}

MuxAnalogInput *FuncFactory::createMuxAnalogInput(uint8_t inputPos, Multiplexer4067 *mux)
{
    return new MuxAnalogInput(inputPos, mux);
}

Pot *FuncFactory::createPot(
    AnalogInput *analogInput,
    uint8_t midiChannel,
    uint8_t midiNumber,
    void (*funCC)(uint8_t, uint8_t, uint8_t))
{
    return new Pot(analogInput, midiChannel, midiNumber, funCC);
}

Output **FuncFactory::createOutputPads(NPKit *npk, const uint8_t *positions)
{
    Output **outPads = new Output *[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        FBPixel *pix = new FBPixel(npk, positions[i]);
        outPads[i] = pix;
    }
    return outPads;
}

DigitalInput **FuncFactory::createInputPads(const uint8_t *mxPinBundle, uint8_t sigPin, const uint8_t *positions, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t))
{
    DigitalInput **muxInPads = new DigitalInput *[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        DigitalInput *inp = new MuxDigitalInput(mxPinBundle, sigPin, positions[i]);
        muxInPads[i] = inp;
    }
    return muxInPads;
}

ButtonMidi *FuncFactory::createButtonPads(DigitalInput **inAggr, Output **outAggr, uint8_t midiCh, uint8_t firstNumber, void (*funOn)(uint8_t, uint8_t, uint8_t), void (*funOff)(uint8_t, uint8_t, uint8_t))
{
    ButtonMidi *btnSet = new ButtonMidi[T_DECK_PADS];
    for (uint8_t i = 0; i < T_DECK_PADS; i++)
    {
        btnSet[i] = ButtonMidi(inAggr[i], outAggr[i], midiCh, firstNumber + i, funOn, funOff);
    }
    return btnSet;
}

Controller *FuncFactory::makeLeftController()
{
    DigitalInput **leftPlayerInputs = createMuxInputs(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, MUX_SW_PLAYER_BUNDLE_L, T_MUX_SW_PLAYER);
    Output **leftPlayerOutputs = createPlayerLeftOutputs();

    ButtonMidi *leftPlayerBtns = createMidiBtns(leftPlayerInputs, leftPlayerOutputs, DECK_A_CH, PLAYER_MIDI_BUNDLE, T_MUX_SW_PLAYER, _funcOn, _funcOff);

    MuxAnalogInput *leftTempoInput = createMuxAnalogInput(PITCH_L, _mplexBottomPots);
    Pot *leftTempoPot = createPot(leftTempoInput, DECK_A_CH, TEMPO_MIDI_NUMBER, _funcCC);

    Player *leftPlayer = new Player(leftPlayerBtns, leftTempoPot);

    DigitalInput **leftInPads = createInputPads(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SW_PADL_BUNDLE, _funcOn, _funcOff);
    Output **leftOutPads = createOutputPads(_npkit, PIXLS_PAD_L);
    ButtonMidi *leftBtnPads = createButtonPads(leftInPads, leftOutPads, DECK_A_CH, PAD_HOTCUE_NOTE, _funcOn, _funcOff);
    ButtonFunc *leftModeBtn = createModeBtn(_npkit, NP_MODE_L, MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWMODE_L, _cbModeFunc);
    Pad *leftPad = new Pad(leftBtnPads, leftModeBtn);

    return createController(leftPlayer, leftPad);
}

Controller *FuncFactory::makeRightController()
{
    DigitalInput **rightPlayerInputs = createMuxInputs(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, MUX_SW_PLAYER_BUNDLE_R, T_MUX_SW_PLAYER);
    Output **rightPlayerOutputs = createPlayerRightOutputs();
    ButtonMidi *rightPlayerBtns = createMidiBtns(rightPlayerInputs, rightPlayerOutputs, DECK_B_CH, PLAYER_MIDI_BUNDLE, T_MUX_SW_PLAYER, _funcOn, _funcOff);

    MuxAnalogInput *rightTempoInput = createMuxAnalogInput(PITCH_R, _mplexBottomPots);
    Pot *rightTempoPot = createPot(rightTempoInput, DECK_B_CH, TEMPO_MIDI_NUMBER, _funcCC);

    Player *rightPlayer = new Player(rightPlayerBtns, rightTempoPot);

    ButtonFunc *rightModeBtn = createModeBtn(_npkit, NP_MODE_R, MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWMODE_R, _cbModeFunc);
    DigitalInput **rightInPads = createInputPads(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SW_PADR_BUNDLE, _funcOn, _funcOff);
    Output **rightOutPads = createOutputPads(_npkit, PIXLS_PAD_R);
    ButtonMidi *rightBtnPads = createButtonPads(rightInPads, rightOutPads, DECK_B_CH, PAD_HOTCUE_NOTE, _funcOn, _funcOff);
    Pad *rightPad = new Pad(rightBtnPads, rightModeBtn);

    return createController(rightPlayer, rightPad);
}

AnalogInput **FuncFactory::createMixerAnalogInputs()
{
    AnalogInput **mixerInputs = new AnalogInput *[T_MIDI_MIXER_POTS];

    for (uint8_t i = 0; i < T_MIXER_TOP_MUX; i++)
    {
        mixerInputs[i] = new MuxAnalogInput(MIXER_TOP_MUX_SET[i], _mplexTopPots);
    }
    for (uint8_t i = 0; i < T_MIXER_BOTTOM_MUX; i++)
    {
        mixerInputs[T_MIXER_TOP_MUX + i] = new MuxAnalogInput(MIXER_BOTTOM_MUX_SET[i], _mplexBottomPots);
    }
    mixerInputs[T_MIXER_TOP_MUX + T_MIXER_BOTTOM_MUX] = new DirectAnalogInput(PMASTER);

    return mixerInputs;
}

Pot *FuncFactory::createMixerPots(AnalogInput **inp, uint8_t midiCh, uint8_t *midiNums)
{
    Pot *pots = new Pot[T_MIDI_MIXER_POTS];
    for (uint8_t i = 0; i < T_MIDI_MIXER_POTS; i++)
    {
        pots[i] = Pot(inp[i], midiCh, midiNums[i], _funcCC);
    }
    return pots;
}

ButtonMidi *FuncFactory::createMixerBtns()
{
    ButtonMidi *btns = new ButtonMidi[T_MIDI_MIXER_BTNS];
    MuxDigitalInput *mcueA = new MuxDigitalInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWPCUEL1);
    MuxDigitalInput *mcueB = new MuxDigitalInput(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, SWPCUEL2);
    MuxDigitalInput *mcueC = new MuxDigitalInput(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, SWPCUEL3);
    Output *cueOutA = new FBLed(_shfLeft, OUT_PCUEL1);
    Output *cueOutB = new FBLed(_shfLeft, OUT_PCUEL2);
    Output *cueOutC = new FBLed(_shfRight, OUT_PCUEL3);
    btns[0] = ButtonMidi(mcueA, cueOutA, MIXER_CH, 0, _funcOn, _funcOff);
    btns[1] = ButtonMidi(mcueB, cueOutB, MIXER_CH, 1, _funcOn, _funcOff);
    btns[2] = ButtonMidi(mcueC, cueOutC, MIXER_CH, 2, _funcOn, _funcOff);
    return btns;
}
VUmeter *FuncFactory::createVuMeters()
{
    VUmeter* vuSet = new VUmeter[T_VUMETER_SET];
    vuSet[0] = VUmeter(L1VU_SIG, L1VU_LATCH, SRCLK);
    vuSet[1] = VUmeter(L2VU_SIG, L2VU_LATCH, SRCLK);
    vuSet[2] = VUmeter(L3VU_SIG, L3VU_LATCH, SRCLK);
    vuSet[3] = VUmeter(MLVU_SIG, MLVU_LATCH, SRCLK);
    vuSet[4] = VUmeter(MRVU_SIG, MRVU_LATCH, SRCLK);
    return vuSet;
}

Mixer* FuncFactory::makeMixer() {
    auto mixerButtons = createMixerBtns();
    auto mixerPots = createMixerPots(createMixerAnalogInputs(), MIXER_CH, MIDI_MIXER_POTS_BNDL);
    auto vuMeters = createVuMeters();

    return new Mixer(mixerButtons, mixerPots, vuMeters);
}

Browser* FuncFactory::makeBrowser() {
    BREncoder* encoders = new BREncoder[T_BROWSER_ENCODERS];
    encoders[0] = BREncoder(L_BROWSER_A, L_BROWSER_B);
    encoders[1] = BREncoder(R_BROWSER_A, R_BROWSER_B);

    ButtonMidi* browser_btns = new ButtonMidi[T_BROWSER_BTNS];
    DigitalInput* brPrevInput = new DirectDigitalInput(SWBR_PREVIEW);
    DigitalInput* brBackInput = new DirectDigitalInput(SWBR_BACK);
    DigitalInput* leftBrInput = new DirectDigitalInput(SW_BROWSER_L);
    DigitalInput* rightBrInput = new DirectDigitalInput(SW_BROWSER_R);
    browser_btns[0] = ButtonMidi(brPrevInput, BROWSER_CH, 0, _funcOn, _funcOff);
    browser_btns[1] = ButtonMidi(brBackInput, BROWSER_CH, 1, _funcOn, _funcOff);
    browser_btns[2] = ButtonMidi(leftBrInput, BROWSER_CH, 2, _funcOn, _funcOff);
    browser_btns[3] = ButtonMidi(rightBrInput, BROWSER_CH, 3, _funcOn, _funcOff);

    return new Browser(encoders, browser_btns);
}

FXUnit* FuncFactory::makeFXUnits() {
 
    DigitalInput** fx1_ins = new DigitalInput*[T_FX_BTNS];
    DigitalInput** fx2_ins = new DigitalInput*[T_FX_BTNS];
    fx1_ins[0] = new DirectDigitalInput(SWFXL_1);
    fx1_ins[1] = new DirectDigitalInput(SWFXL_2);
    fx1_ins[2] = new DirectDigitalInput(SWFXL_3);
    fx2_ins[0] = new DirectDigitalInput(SWFXR_1);
    fx2_ins[1] = new DirectDigitalInput(SWFXR_2);
    fx2_ins[2] = new DirectDigitalInput(SWFXR_3);
    Output** fx1_leds = new Output*[T_FX_BTNS];
    Output** fx2_leds = new Output*[T_FX_BTNS];
    fx1_leds[0]= new FBLed(_shfLeft, OUT_FX1_L);
    fx1_leds[1]= new FBLed(_shfLeft, OUT_FX2_L);
    fx1_leds[2]= new FBLed(_shfLeft, OUT_FX3_L);
    fx2_leds[0]= new FBLed(_shfRight, OUT_FX1_R);
    fx2_leds[1]= new FBLed(_shfRight, OUT_FX2_R);
    fx2_leds[2]= new FBLed(_shfRight, OUT_FX3_R);
    ButtonMidi* fx1_btns = new ButtonMidi[T_FX_BTNS];
    for (uint8_t i = 0; i < T_FX_BTNS; i++) {
        fx1_btns[i] = ButtonMidi(fx1_ins[i], fx1_leds[i], FX1_CH, i, _funcOn, _funcOff);
    }
    ButtonMidi* fx2_btns = new ButtonMidi[T_FX_BTNS];
    for (uint8_t i = 0; i < T_FX_BTNS; i++) {
        fx2_btns[i] = ButtonMidi(fx2_ins[i], fx2_leds[i], FX2_CH, i, _funcOn, _funcOff);
    }
    AnalogInput** fx1_pot_ins = new AnalogInput*[T_FX_POTS];
    for (uint8_t i = 0; i < T_FX_POTS; i++)
    {
        fx1_pot_ins[i] = new MuxAnalogInput(FX1_POTS_SET[i], _mplexTopPots);
    }

    AnalogInput** fx2_pot_ins = new AnalogInput*[T_FX_POTS];
    fx2_pot_ins[0] = new DirectAnalogInput(PFXR_1);
    fx2_pot_ins[1] = new MuxAnalogInput(FX2_POTS_SET[0], _mplexTopPots);
    fx2_pot_ins[2] = new MuxAnalogInput(FX2_POTS_SET[1], _mplexTopPots);

    Pot* fx1_pots = new Pot[T_FX_POTS];
    for (uint8_t i = 0; i < T_FX_POTS; i++)
    {
        fx1_pots[i] = Pot(fx1_pot_ins[i], FX1_CH, i, _funcCC);
    }
    Pot* fx2_pots = new Pot[T_FX_POTS];
    for (uint8_t i = 0; i < T_FX_POTS; i++)
    {
        fx2_pots[i] = Pot(fx2_pot_ins[i], FX2_CH, i, _funcCC);
    }

    FXUnit* fxUnits = new FXUnit[T_FX_UNITS];
    fxUnits[0] = FXUnit(fx1_pots, fx1_btns);
    fxUnits[1] = FXUnit(fx2_pots, fx2_btns);

    return fxUnits;
}



