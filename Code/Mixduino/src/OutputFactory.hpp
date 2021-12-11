#pragma once
#include "FBLed.h"
#include "FBPixel.h"

namespace MD
{
  class OutputFactory
  {
  public:
    OutputFactory(Adafruit_NeoPixel* np);

    Output** getlPlayerOuts();
    Output** getrPlayerOuts();
    Output** getlPadOuts();
    Output** getrPadOuts();
    
  private:
    Output** m_lplayerOuts{nullptr};
    Output** m_lpadOuts{nullptr};
    Output** m_rplayerOuts{nullptr};
    Output** m_rpadOuts{nullptr};

    Output** makePlayerOuts(const uint8_t* outPositions, Shifter* shf, Adafruit_NeoPixel* np);
    Output** makePadOuts(const uint8_t* outPositions, Adafruit_NeoPixel* np);
  };

} // namespace MD
