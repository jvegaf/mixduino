#include "PlayerFactory.hpp"
#include "constans.h"
#include "Button.hpp"
#include "Pot.hpp"
#include "midi_map.h"

namespace MD
{

PlayerFactory::PlayerFactory(InputFactory* inputFact, OutputFactory* outFact)
{
  auto lplayerIns = inputFact->getLeftPlayerInputs();
  auto lplayerOuts = outFact->getlPlayerOuts();

  m_playerLeft = makePlayer(lplayerIns, lplayerOuts, kPlayerMidi);

  auto rplayerIns = inputFact->getRightPlayerInputs();
  auto rplayerOuts = outFact->getrPlayerOuts();

  m_playerRight = makePlayer(rplayerIns, rplayerOuts, kPlayerMidi);

}

Player* PlayerFactory::getLeftPlayer() { return m_playerLeft; }

Player* PlayerFactory::getRightPlayer() { return m_playerRight; }


Player* PlayerFactory::makePlayer(Input** ins, Output** outs, const uint8_t* midiNums) {
  Button* btns = new Button[kTDeckButtons];
  for (uint8_t i = 0; i < kTDeckButtons; i++)
  {
    btns[i] = Button(ins[i], outs[i]);
  }
  auto tempoPot = new Pot(ins[kTDeckButtons]);
  return new Player(btns, tempoPot, midiNums);
}
  
} // namespace MD



