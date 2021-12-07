#pragma once
#include <Arduino.h>


namespace MD
{

struct inMidiParam_str
{
  uint8_t inputPos;
  uint8_t midiCh;
  uint8_t midiNumber;
  void (*funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*funcOff)(uint8_t, uint8_t, uint8_t);
};

typedef struct inMidiParam_str inMidip_t;

struct inPotMidiParam_str
{
  uint8_t inputPos;
  uint8_t midiCh;
  uint8_t midiNumber;
  void (*funcCC)(uint8_t, uint8_t, uint8_t); 
};

typedef struct inPotMidiParam_str inPotMidip_t;

  
} // namespace MD

