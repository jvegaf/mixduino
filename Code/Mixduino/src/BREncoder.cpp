#include "BREncoder.h"

Encoder lEnc(L_BROWSER_A, L_BROWSER_B);
Encoder rEnc(R_BROWSER_A, R_BROWSER_B);
long oldLeft = -999;
long oldRight = -999;

BREncoder::BREncoder() {}

void BREncoder::readEnc(void (*scc_func)(byte, byte, byte))
{
  long newPLeft = lEnc.read();

  if (newPLeft != oldLeft)
  {
    if (newPLeft - oldLeft > 0)
    {
      scc_func(14, 127, 6);
    }
    if (newPLeft - oldLeft < 0)
    {
      scc_func(14, 1, 6);
    }
    oldLeft = newPLeft;
  }

  long newPRight = rEnc.read();

  if (newPRight != oldRight)
  {
    if (newPRight - oldRight > 0)
    {
      scc_func(15, 127, 6);
    }
    if (newPRight - oldRight < 0)
    {
      scc_func(15, 1, 6);
    }
    oldRight = newPRight;
  }

}