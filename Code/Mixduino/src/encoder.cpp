#include "encoder.hpp"
#include "constants.h"
#include <EventManager.h>

namespace mixduino
{

  MDEncoder::MDEncoder(uint8_t pin_a, uint8_t pin_b)
  : m_encoder { new Encoder(pin_a, pin_b)}
  {

  }

  void MDEncoder::read(EventManager &em)
  {

    int newPosition = m_encoder->read();

    if (newPosition != m_oldPosition)
    {

      if ((newPosition - m_oldPosition) > 0)
      {
        em.queueEvent(EventManager::kEventUser0, 127);
      }
      else
      {
        em.queueEvent(EventManager::kEventUser0, 1);
      }

      m_oldPosition = newPosition;
    }
  }
} // namespace mixduino
