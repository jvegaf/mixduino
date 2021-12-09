#include "MainFactory.hpp"
#include "MuxerInputFactory.hpp"
#include "MuxerPotsFactory.hpp"
#include "FBLedFactory.hpp"
#include "FBPixel.h"
#include "ButtonFactory.hpp"
#include "PotsFactory.hpp"
#include "PadFactory.hpp"
#include "midi_map.h"

namespace MD
{

  MainFactory::MainFactory()
  {
  
    auto muxerInFact = new MuxerInputFactory();
    auto muxerPotFact = new MuxerPotsFactory();
    auto ledFact = new FBLedFactory();
    auto fbPixel = new FBPixel();

    auto btnFact = new ButtonFactory(muxerInFact, ledFact, fbPixel);
    auto potsFact = new PotsFactory(muxerPotFact);
    auto padFact = new PadFactory(btnFact);

    auto leftPlayer = new Player(btnFact->getLeftPlayerBtns(), potsFact->getLeftTempoPot(), kPlayerMidi);
    auto rightPlayer = new Player(btnFact->getRightPlayerBtns(), potsFact->getRightTempoPot(), kPlayerMidi);
    auto leftPad = padFact->getLeftPad();
    auto rightPad = padFact->getRightPad();

    m_leftDeck = new Deck(leftPlayer, leftPad);
    m_rightDeck = new Deck(rightPlayer, rightPad);
    m_deckSwBtn = btnFact->getDeckSwitcherBtn();
  }

  Deck* MainFactory::getLeftDeck() { return m_leftDeck; }

  Deck* MainFactory::getRightDeck() { return m_rightDeck; }

  ButtonMode* MainFactory::getDeckSwitcherBtn() { return m_deckSwBtn; }

} // namespace MD
