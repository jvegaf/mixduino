#include "BREncoder.h"  

Encoder brEnc(3,4);

BREncoder::BREncoder()
{
    
    this->oldPosition = -10;
}

BREncoder::~BREncoder()
{

}

int BREncoder::read () {

  int newPosition = brEnc.read();
  int encoderVal = map(newPosition, -1024, 1024, -256, 256);
  int encoderValue;

  if (encoderVal != this->oldPosition) {

    if ((encoderVal - oldPosition) > 0) {
      encoderValue = 127;
    }
    else {
      encoderValue = 1;
    }

    this->oldPosition = encoderVal;
    return encoderValue;
  }

}