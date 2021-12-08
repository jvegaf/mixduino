#include "Pot.hpp"

namespace MD
{
  Pot::Pot(InputPot* input)
    : m_input{input}
  {
    
  }

  void Pot::read(inPotMidip_t p)
  {
    m_input->read(p);
  }
  
} // namespace MD


