#pragma once
#include "Input.h"

namespace MD
{
  class InputFactory
  {
  public:
    InputFactory();
    Input** getLeftPlayerInputs();
    Input** getRightPlayerInputs();
    Input** getLeftPadInputs();
    Input** getRightPadInputs();
    Input* getDeckSwitchInput();
  private:
    Input** m_lPlayerInputs{nullptr};
    Input** m_rPlayerInputs{nullptr};
    Input** m_lPadInputs{nullptr};
    Input** m_rPadInputs{nullptr};

    Input** makeMuxInputs(const uint8_t* muxPins, const uint8_t sigPin, const uint8_t* positions, const uint8_t tPositions);

    Input** makePlayerInputs(const uint8_t* muxPins, const uint8_t sigPin, const uint8_t* positions, const uint8_t tPositions);
  };
  
} // namespace MD
