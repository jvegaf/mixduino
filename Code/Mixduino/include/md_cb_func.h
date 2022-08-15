#ifndef MD_CB_FUNC_H_
#define MD_CB_FUNC_H_

#include <Arduino.h>
#include "md_enums.hpp"

struct compoment_str
{
  void (*funcPad)(Location, uint8_t);
  void (*funcDeckSel)();
  void (*funcPadMod)(Location);
};

typedef struct inputCallBacks_str inCallBacks_t;

#endif // MD_CB_FUNC_H_

