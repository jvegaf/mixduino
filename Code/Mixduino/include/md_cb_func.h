#ifndef __MD_CB_FUNC_H__
#define __MD_CB_FUNC_H__

#include <Arduino.h>

struct inputCallbacks_str
{
  void (*funcOn)(uint8_t, uint8_t, uint8_t); 
  void (*funcDeckSel)();
  void (*funcLPadMod)();
  void (*funcRPadMod)();
};

typedef struct inputCallBacks_str inCallBacks_t;

#endif // __MD_CB_FUNC_H__
