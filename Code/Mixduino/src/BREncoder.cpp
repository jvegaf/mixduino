#include "BREncoder.h"

Encoder encL();
int encodersTotal = 2;
Encoder encoders[] = {Encoder(L_BROWSER_A, L_BROWSER_B), Encoder (R_BROWSER_A, R_BROWSER_B)};
long oldPositions[] = { -999, -999 };

BREncoder::BREncoder() { }

void BREncoder::readEnc(void (*scc_func)(byte, byte, byte))
{
  for (int i = 0; i < encodersTotal; i++)
  {
    long newPosition = encoders[i].read();

    if (newPosition == oldPositions[i]) { continue; }

    if (newPosition - oldPositions[i] > 0)
    {
      scc_func(14, 127, 1);
    }
    else
    {
      scc_func(14, 1, 1);
    }
    oldPositions[i] = newPosition;
  }
}