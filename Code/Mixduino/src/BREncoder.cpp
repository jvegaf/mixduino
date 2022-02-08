#include "BREncoder.hpp"

namespace MDEncoder
{


Encoder knobLeft(L_BROWSER_A, L_BROWSER_B);
Encoder knobRight(R_BROWSER_A, R_BROWSER_B);

volatile long positionLeft  = -999;
volatile long positionRight = -999; 


void read(void (*scc_func)(uint8_t, uint8_t, uint8_t))
{

  long newLeft, newRight;
  newLeft = knobLeft.read();
  newRight = knobRight.read();

    if (newLeft != positionLeft ) {

      if ((newLeft - positionLeft) > 0)
      {
        scc_func(14, 127, 1);
      }
      else
      {
        scc_func(14, 1, 1);
      }

      positionLeft = newLeft;
    }
    if (newRight != positionRight ) {

      if ((newRight - positionRight) > 0)
      {
        scc_func(14, 127, 1);
      } 
      else
      {
        scc_func(14, 1, 1);
      }

      positionRight = newRight;
    }
}
  
} // namespace MDEncoder
