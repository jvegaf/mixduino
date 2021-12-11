#include "InputFactory.hpp"
#include "InputMux.hpp"
#include "InputMuxAnalog.hpp"
#include "pin_map.h"
#include "constans.h"
#include "sw_muxmap.h"

namespace MD
{

InputFactory::InputFactory()
{
  m_lPlayerInputs = makePlayerInputs(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, leftPlayerSwBnd, kTPlayerComponents);
  
  m_rPlayerInputs = makePlayerInputs(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, rightPlayerSwBnd, kTPlayerComponents);
  m_lPadInputs = makeMuxInputs(MUXPIN_BUNDLE, LEFT_SWMUX_SIG, leftPadSwBnd, kTPadComponents);
  m_rPadInputs = makeMuxInputs(MUXPIN_BUNDLE, RIGHT_SWMUX_SIG, rightPadSwBnd, kTPadComponents);
}

Input** InputFactory::getLeftPlayerInputs() { return m_lPlayerInputs; }
Input** InputFactory::getRightPlayerInputs() { return m_rPlayerInputs; }
Input** InputFactory::getLeftPadInputs() { return m_lPadInputs; }
Input** InputFactory::getRightPadInputs() { return m_rPadInputs; }

Input** InputFactory::makeMuxInputs(const uint8_t* muxPins, const uint8_t sigPin, const uint8_t* positions, const uint8_t tPositions)
{
  auto result = new Input*[tPositions];
  for (uint8_t i = 0; i < tPositions; i++)
  {
    result[i] = new InputMux(positions[i], muxPins, sigPin);
  }
  
  return result;
}

Input** InputFactory::makePlayerInputs(const uint8_t* muxPins, const uint8_t sigPin, const uint8_t* positions, const uint8_t tPositions)
{
  auto result = new Input*[tPositions];
  for (uint8_t i = 0; i < tPositions-1; i++)
  {
    result[i] = new InputMux(positions[i], muxPins, sigPin);
  }
  result[tPositions-1] = new InputAnalogMux(positions[tPositions-1], muxPins, sigPin);
  
  return result;
}
} // namespace MD



  
