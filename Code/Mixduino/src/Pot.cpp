#include "Pot.hpp"

namespace MD
{
  Pot::Pot(Input* input)
    : m_input{input}
  {
    
  }

  void Pot::read(inCommand_t c)
  {
    m_input->read(c);
  }
  
} // namespace MD


