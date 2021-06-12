#include <Arduino.h>
#include "NPKit.h"
#include "Npixel.h"

/////////////////////////////////////////////
// NeoPixels Module
int nplTotal = 10;
int nprTotal = 11;
NPKit npLeft(2, nplTotal);   // first number to receive changes (in this case is equals to lowest midi note)
NPKit npRight(23, nprTotal); // first number to receive changes (in this case is equals to lowest midi note)

void handleNoteOn(byte channel, byte number, byte value);
void handleNoteOff(byte channel, byte number, byte value);

void setup()
{
  npLeft.begin();
  npRight.begin();
  Serial.begin(115200); // 115200 for hairless - 31250 for MOCO lufa
}

void loop()
{
  for (size_t i = 0; i < nplTotal; i++)
  {
    Npixel pixel(i, 1);
    npLeft.handleChange(pixel);
    delay(500);
    npLeft.clear();
    delay(500);
  }
  for (size_t i = 0; i < nprTotal; i++)
  {
    Npixel pixel(i, 1);
    npRight.handleChange(pixel);
    delay(500);
    npRight.clear();
  }
}
