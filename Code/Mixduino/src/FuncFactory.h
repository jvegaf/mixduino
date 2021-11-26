#pragma once
#ifndef FUNCFACTORY_H
#define FUNCFACTORY_H
#include "..\lib\npkit\NPKit.h"
#include <Shifter.h>
#include "pin_map.h"
#include "np_map.h"
#include "sr_fb_map.h"
#include "midi_map.h"
#include "MuxInput.h"
#include "FuncMode.h"
#include "FuncPad.h"
#include "DirectDigitalInput.h"
#include "sw_muxmap.h"
#include "FBLed.h"
#include "FBPixel.h"
#include "Pad.h"
#include "Funcs.h"
#include "FuncsBlind.h"


class FuncFactory
{
public:
    void begin(NPKit* npkit, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

    FuncsBlind* getBlindFuncs() const { return this->_blindFuncs; }

    Funcs* getFuncs() const { return this->_funcs; }

    Pad* getLeftPad() const { return this->_leftPad; }

    Pad* getRightPad() const { return this->_rightPad; }

    FuncMode* getFuncModeLeft() const { return this->_funcModeLeft; }

    FuncMode* getFuncModeRight() const { return this->_funcModeRight; }
    

private:
    NPKit* _npkit;
    Shifter* _shfLeft;
	Shifter* _shfRight;
    FuncMode* _funcModeLeft; 
    FuncMode* _funcModeRight;
    Funcs* _funcs;
    FuncsBlind* _blindFuncs;
    Pad* _leftPad;
    Pad* _rightPad; 
    void (*fOn)(uint8_t, uint8_t, uint8_t); 
    void (*fOff)(uint8_t, uint8_t, uint8_t);

    DigitalInput** createInputs();
    Output **createOutputs();

    DigitalInput **createInputPads(const uint8_t* mxPinBundle, uint8_t sigPin, const uint8_t* positions, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

    Output** createOutputPads(NPKit* npk, const uint8_t* positions);
    FuncMode* createLeftModeFunc();
    FuncMode* createRightModeFunc();
    DigitalInput** createBlindInputs();
    Func* createFuncs(DigitalInput **inAggr, Output **outAggr, uint8_t midiCh, uint8_t t_funcs);
    FuncBase* createBlindFuncs(DigitalInput **inAggr, uint8_t midiCh, uint8_t t_funcs);
    FuncPad* createFuncPads(DigitalInput **inAggr, Output **outAggr, uint8_t midiCh, uint8_t t_funcs);

    
};

#endif // FUNCFACTORY_H
