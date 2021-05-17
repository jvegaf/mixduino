#include "BREncoder.h"

Encoder enc(BROWSER_A, BROWSER_B);

BREncoder::BREncoder()
{
  oldPosition = -10;
}

void BREncoder::readEnc(void (*scc_func)(byte, byte, byte))
{

  int newPosition = enc.read();

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