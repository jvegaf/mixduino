#include "PadFactory.hpp"
#include "constans.h"
#include "ButtonCBack.hpp"

namespace MD
{
  PadFactory::PadFactory(InputFactory* inFact, OutputFactory* outFact)
  {
    m_leftPad = makePad(inFact->getLeftPadInputs(), outFact->getlPadOuts(), kPadModeLeftBtnType);
    m_rightPad = makePad(inFact->getRightPadInputs(), outFact->getrPadOuts(), kPadModeRightBtnType);
  }

  Pad* PadFactory::getLeftPad()
  {
    return m_leftPad;
  }

  Pad* PadFactory::getRightPad()
  {
    return m_rightPad;
  }

  Pad* PadFactory::makePad(Input** ins, Output** outs, uint8_t cType)
  {
    auto group = new Button[kTPadButtons];
    for (uint8_t i = 0; i < kTPadButtons; i++)
    {
      group[i] = Button(ins[i], outs[i]);
    }

    ButtonCBack* modebtn = new ButtonCBack(ins[kTPadButtons], outs[kTPadButtons], cType);
    return new Pad(group, modebtn);
  }


  
} // namespace MD


