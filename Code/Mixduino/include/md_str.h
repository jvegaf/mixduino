#pragma once
#include <Arduino.h>


namespace MD
{

struct inMidiParam_str
{
  void (*funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*funcOff)(uint8_t, uint8_t, uint8_t);
  uint8_t midiCh;
  uint8_t midiNumber;
  uint8_t inputPos;
};

typedef struct inMidiParam_str inMidip_t;

struct inPotMidiParam_str
{
  uint8_t midiCh;
  uint8_t midiNumber;
  uint8_t inputPos;
};

typedef struct inPotMidiParam_str inPotMidip_t;

struct cbFunctions_str
{
  void (*funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*funcOff)(uint8_t, uint8_t, uint8_t);
  void (*funcCC)(uint8_t, uint8_t, uint8_t);
};

typedef struct cbFunctions_str cbFuncs_t;

  
} // namespace MD

