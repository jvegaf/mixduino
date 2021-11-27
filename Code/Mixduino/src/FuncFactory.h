#pragma once
#ifndef FUNCFACTORY_H
#define FUNCFACTORY_H
#include "..\lib\npkit\NPKit.h"
#include "ButtonFunc.h"
#include "ButtonMidi.h"
#include "Controller.h"
#include "DirectDigitalInput.h"
#include "FBLed.h"
#include "FBPixel.h"
#include "MuxAnalogInput.h"
#include "DirectAnalogInput.h"
#include "MuxDigitalInput.h"
#include "VUmeter.h"
#include "Mixer.h"
#include "Browser.h"
#include "FXUnit.h"
#include "midi_map.h"
#include "np_map.h"
#include "pin_map.h"
#include "pots_muxmap.h"
#include "sr_fb_map.h"
#include "sw_muxmap.h"
#include <Multiplexer4067.h>
#include <Shifter.h>

class FuncFactory
{
public:
    void begin(NPKit *npkit,
    void (*funcOn)(uint8_t, uint8_t, uint8_t),
    void (*funcOff)(uint8_t, uint8_t, uint8_t),
    void (*funcCC)(uint8_t, uint8_t, uint8_t),
    void (*cbModeFunc)(uint8_t),
    void (*cbSelDeck)());

    Controller* getLeftController() { return _leftController; }
    Controller* getRightController() { return _rightController; }
    Mixer* getMixer() { return _mixer; }
    FXUnit* getFxUnits() { return _fxUnits; }
    Browser* getBrowser() { return _browser; }
    ButtonFunc* getDeckSelBtn() { return _deckSelBtn; }

private:
    NPKit *_npkit { nullptr };
    Shifter *_shfLeft { nullptr };
    Shifter *_shfRight { nullptr };
    Multiplexer4067 *_mplexTopPots { nullptr };
    Multiplexer4067 *_mplexBottomPots { nullptr };
    Controller* _leftController { nullptr };
    Controller* _rightController { nullptr };
    Mixer* _mixer { nullptr };
    FXUnit* _fxUnits { nullptr };
    Browser* _browser { nullptr };
    ButtonFunc* _deckSelBtn { nullptr };
    void (*_funcOn)(uint8_t, uint8_t, uint8_t) { nullptr };
    void (*_funcOff)(uint8_t, uint8_t, uint8_t) { nullptr };
    void (*_funcCC)(uint8_t, uint8_t, uint8_t) { nullptr };
    void (*_cbModeFunc)(uint8_t) { nullptr };
    void (*_cbSelDeck)() { nullptr };

    DigitalInput **createInputs();
    Output **createOutputs();

    DigitalInput **createInputPads(const uint8_t *mxPinBundle, uint8_t sigPin, const uint8_t *positions, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

    Output **createOutputPads(NPKit *npk, const uint8_t *positions);
    ButtonFunc *createFuncBtn(NPKit *npk, uint8_t outPos, uint8_t *muxPinBnd, uint8_t sigPin, uint8_t inPos, void (*cbMFn)());

    DigitalInput **createMuxInputs(uint8_t *muxPinBnd, uint8_t sigPin, uint8_t *inPos, uint8_t tInputs);

    ButtonMidi *createMidiBtns(
        DigitalInput **inAggr,
        Output **outAggr,
        uint8_t midiChannel,
        uint8_t *midiNotes,
        uint8_t t_btns,
        void (*funcOn)(uint8_t, uint8_t, uint8_t),
        void (*funcOff)(uint8_t, uint8_t, uint8_t));

    Output **createPlayerLeftOutputs();

    Output **createPlayerRightOutputs();

    MuxAnalogInput *createMuxAnalogInput(uint8_t inputPos, Multiplexer4067 *mux);

    Pot *createPot(
        AnalogInput *analogInput,
        uint8_t midiChannel,
        uint8_t midiNumber,
        void (*funCC)(uint8_t, uint8_t, uint8_t));

    ButtonMidi *createButtonPads(
        DigitalInput **inAggr,
        Output **outAggr,
        uint8_t midiCh,
        uint8_t firstNumber,
        void (*funOn)(uint8_t, uint8_t, uint8_t),
        void (*funOff)(uint8_t, uint8_t, uint8_t));

    Controller *createController(Player *player, Pad *pad);

    Controller* makeLeftController();

    Controller* makeRightController();

    AnalogInput** createMixerAnalogInputs();

    Pot* createMixerPots(AnalogInput **inp, uint8_t midiCh, uint8_t* midiNums);

    ButtonMidi* createMixerBtns();

    VUmeter* createVuMeters();

    Mixer* makeMixer();

    Browser* makeBrowser();

    FXUnit* makeFXUnits();

    ButtonFunc *createModeBtn(NPKit *npk, uint8_t outPos, uint8_t *muxPinBnd, uint8_t sigPin, uint8_t inPos, void (*cbFn)(uint8_t));
};

#endif // FUNCFACTORY_H
