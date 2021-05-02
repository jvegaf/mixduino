#include "BREncoder.h"

Encoder enc(BROWSER_A, BROWSER_B);

BREncoder::BREncoder()
{
  this->oldPosition = -10;
}

int BREncoder::readEnc()
{

  int newPosition = enc.read();
  int encoderVal = map(newPosition, -1024, 1024, -256, 256);
  int encoderValue = 0;

  if (encoderVal != this->oldPosition)
  {

    if ((encoderVal - oldPosition) > 0)
    {
      encoderValue = 127;
    }
    else
    {
      encoderValue = 1;
    }

    this->oldPosition = encoderVal;
  }
  return encoderValue;
}