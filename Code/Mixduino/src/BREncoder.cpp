#include "BREncoder.h"

int encodersTotal = 2;
Encoder encoders[] = {Encoder(L_BROWSER_A, L_BROWSER_B), Encoder(R_BROWSER_A, R_BROWSER_B)};
long oldPositions[] = { -999, -999 };

BREncoder::BREncoder() {}

void BREncoder::readEnc(void (*scc_func)(byte, byte, byte))
{
  for (int i = 0; i < encodersTotal; i++)
  {
    long newPosition = encoders[i].read();

    if (newPosition == oldPositions[i]) { return; }

    if (newPosition - oldPositions[i] > 0)
    {
      scc_func(14, 127, 6);
    }
    else
    {
      scc_func(14, 1, 6);
    }
    oldPositions[i] = newPosition;
  }
}