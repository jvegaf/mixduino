#include "MainFactory.hpp"
#include "InputFactory.hpp"
#include "OutputFactory.hpp"
#include "FBPixel.h"
#include "PlayerFactory.hpp"
#include "PadFactory.hpp"
#include "midi_map.h"
#include "constans.h"

namespace MD
{

  MainFactory::MainFactory(Adafruit_NeoPixel* np)
  {
  
    auto inFact = new InputFactory();
    auto outFact = new OutputFactory(np);

    auto playerFact = new PlayerFactory(inFact, outFact);
    auto padFact = new PadFactory(inFact, outFact);

    auto leftPlayer = playerFact->getLeftPlayer();
    auto rightPlayer = playerFact->getRightPlayer();
    auto leftPad = padFact->getLeftPad();
    auto rightPad = padFact->getRightPad();

    m_leftDeck = new Deck(leftPlayer, leftPad);
    m_rightDeck = new Deck(rightPlayer, rightPad);
    m_deckSwBtn = new ButtonCBack(inFact->getDeckSwitchInput(), outFact->getDeckSwitchOutput(), kDeckSwitcherBtnType );
  }

  Deck* MainFactory::getLeftDeck() { return m_leftDeck; }

  Deck* MainFactory::getRightDeck() { return m_rightDeck; }

  ButtonCBack* MainFactory::getDeckSwitcherBtn() { return m_deckSwBtn; }

} // namespace MD
