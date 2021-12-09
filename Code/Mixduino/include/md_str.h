#pragma once
#include <Arduino.h>


namespace MD
{

struct inputCommand_str
{
  void (*funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*funcOff)(uint8_t, uint8_t, uint8_t);
  void (*funcCC)(uint8_t, uint8_t, uint8_t);
  uint8_t midiCh;
  uint8_t midiNumber;
  uint8_t inputPos;
};

typedef struct inputCommand_str inCommand_t;

} // namespace MD

