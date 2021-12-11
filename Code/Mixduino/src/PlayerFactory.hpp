#pragma once

#include "Player.hpp"
#include "InputFactory.hpp"
#include "OutputFactory.hpp"

namespace MD
{
  class PlayerFactory
  {
  public:
    PlayerFactory(InputFactory* inputFact, OutputFactory* outFact);
    Player* getLeftPlayer();
    Player* getRightPlayer();
    
  private:
    Player* m_playerLeft{nullptr};
    Player* m_playerRight{nullptr};
    

    Player* makePlayer(Input** ins, Output** outs, const uint8_t* midiNums);

  };

} // namespace MD
