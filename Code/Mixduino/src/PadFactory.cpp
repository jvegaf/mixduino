#include "PadFactory.hpp"

namespace MD
{
  PadFactory::PadFactory(ButtonFactory* bFactory)
  {
    m_leftPad = new Pad(bFactory->getLeftPadBtns(), bFactory->getLeftPadModeBtn());
    m_rightPad = new Pad(bFactory->getRightPadBtns(), bFactory->getRightPadModeBtn());
  }
  
} // namespace MD


