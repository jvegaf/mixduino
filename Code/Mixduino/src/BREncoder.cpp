#include "BREncoder.h"

BREncoder::BREncoder(byte pin_a, byte pin_b)
{
  enc = new Encoder(pin_a, pin_b);
  oldPosition = -10;
}

void BREncoder::readEnc(void (*scc_func)(byte, byte, byte))
{

  int newPosition = enc->read();

  if (newPosition != oldPosition)
  {

    if ((newPosition - oldPosition) > 0)
    {
      scc_func(14, 127, 1);
    }
    else
    {
      scc_func(14, 1, 1);
    }

    oldPosition = newPosition;
  }
}