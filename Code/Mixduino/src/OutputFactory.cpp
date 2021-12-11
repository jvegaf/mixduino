#include "OutputFactory.hpp"
#include "sr_fb_map.h"
#include "constans.h"
#include "pin_map.h"

namespace MD
{

  OutputFactory::OutputFactory(Adafruit_NeoPixel* np)
  : m_np{np}
  {
    auto shfLeft = new Shifter(FBL_SIG, FBL_LATCH, SRCLK, 1);
    auto shfRight = new Shifter(FBR_SIG, FBR_LATCH, SRCLK, 1);
    m_lplayerOuts = makePlayerOuts(playerLeftOutBndl, shfLeft, np);
    m_rplayerOuts = makePlayerOuts(playerRightOutBndl, shfRight, np);
    m_lpadOuts = makePadOuts(PIXLS_PAD_L, np);
    m_rpadOuts = makePadOuts(PIXLS_PAD_R, np);
  }

  Output** OutputFactory::getlPlayerOuts() { return m_lplayerOuts; }
  Output** OutputFactory::getrPlayerOuts() { return m_rplayerOuts; }
  Output** OutputFactory::getlPadOuts() { return m_lpadOuts; }
  Output** OutputFactory::getrPadOuts() { return m_rpadOuts; }
  Output* OutputFactory::getDeckSwitchOutput() { return new FBPixel(NP_DECK_SEL, m_np);}

  Output** OutputFactory::makePlayerOuts(const uint8_t* outPositions, Shifter* shf, Adafruit_NeoPixel* np) 
  {
    auto result = new Output*[kTDeckButtons];

    for (uint8_t i = 0; i < kTDeckLeds; i++)
    {
      result[i] = new FBLed(outPositions[i], shf);
    }
    result[kTDeckLeds] = new FBPixel(outPositions[kTDeckLeds], np);

    return result;
  }

  Output** OutputFactory::makePadOuts(const uint8_t* outPositions, Adafruit_NeoPixel* np)
  {
    auto result = new Output*[kTPadComponents];
    for (uint8_t i = 0; i < kTPadComponents; i++)
    {
      result[i] = new FBPixel(outPositions[i], np);
    }
    
    return result;
  }
  

} // namespace MD
