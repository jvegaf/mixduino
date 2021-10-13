#include "BREncoder.h"

BREncoder::BREncoder(uint8_t pin_a, uint8_t pin_b)
{
  enc = new Encoder(pin_a, pin_b);
  oldPosition = -10;
}

void BREncoder::readEnc(void (*scc_func)(uint8_t, uint8_t, uint8_t))
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