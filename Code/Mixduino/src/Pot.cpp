#include "Pot.hpp"

namespace MD
{
  Pot::Pot(InputPot* input, const uint8_t inputPos)
    : m_input{input}, m_inputPos{inputPos}
  {
    
  }

  void Pot::read(inCommand_t c)
  {
    c.inputPos = m_inputPos;
    m_input->read(c);
  }
  
} // namespace MD


