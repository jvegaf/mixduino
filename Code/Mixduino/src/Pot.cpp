#include "Pot.hpp"
#include "InputAnalogMux.hpp"

namespace MD
{
  Pot::Pot(Input* input)
    : m_input{input}
  {
    
  }

  void Pot::read(inCommand_t c)
  {
    InputAnalogMux* in = static_cast<InputAnalogMux*>(m_input);
    in->read(c);
  }
  
} // namespace MD


