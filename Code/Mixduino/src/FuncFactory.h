#pragma once
#ifndef FUNCFACTORY_H
#define FUNCFACTORY_H
#include "NPKit.h"
#include <Shifter.h>
#include "pin_map.h"
#include "np_map.h"
#include "sr_fb_map.h"
#include "midi_map.h"
#include "ModeInput.h"
#include "FuncMode.h"
#include "FuncPad.h"
#include "ArduInput.h"
#include "sw_muxmap.h"
#include "FBLed.h"
#include "FBPixel.h"


class FuncFactory
{
public:
    void begin(NPKit* npkit, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

    FuncBase* getBlindFuncs() const { return this->_blindFuncs; }

    Func* getFuncs() const { return this->_funcs; }

    FuncPad* getLeftFuncPads() const { return this->_leftFuncPads; }

    FuncPad* getRightFuncPads() const { return this->_rightFuncPads; }

    FuncMode* getFuncModeLeft() const { return this->_funcModeLeft; }

    FuncMode* getFuncModeRight() const { return this->_funcModeRight; }
    

private:
    NPKit* _npkit;
    Shifter* _shfLeft;
	Shifter* _shfRight;
    FuncMode* _funcModeLeft; 
    FuncMode* _funcModeRight;
    FuncBase* _blindFuncs;
    Func* _funcs;
    FuncPad* _leftFuncPads;
    FuncPad* _rightFuncPads; 
    void (*fOn)(uint8_t, uint8_t, uint8_t); 
    void (*fOff)(uint8_t, uint8_t, uint8_t);

    Input** createInputs();
    OutputBase **createOutputs();

    Input **createInputPads(const uint8_t* mxPinBundle, uint8_t sigPin, const uint8_t* positions, void (*funcOn)(uint8_t, uint8_t, uint8_t), void (*funcOff)(uint8_t, uint8_t, uint8_t));

    OutputBase** createOutputPads(NPKit* npk, const uint8_t* positions);
    FuncMode* createLeftModeFunc();
    FuncMode* createRightModeFunc();
    Input** createBlindInputs();
    Func* createFuncs(Input **inAggr, OutputBase **outAggr, uint8_t midiCh, const uint8_t *notesAggr, uint8_t t_funcs);
    FuncBase* createFuncsBase(Input **inAggr, uint8_t midiCh, const uint8_t *notesAggr, uint8_t t_funcs);
    FuncPad* createFuncPads(Input **inAggr, OutputBase **outAggr, uint8_t midiCh, uint8_t t_funcs);

    
};

#endif // FUNCFACTORY_H
