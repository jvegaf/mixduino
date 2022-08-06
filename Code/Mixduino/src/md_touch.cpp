#include "md_touch.hpp"

#include <Trill.h>

/**
 * Left Bar is commented because the hardware is broken
 */

namespace MDTouch
{
Trill rightBar;

void initialize()
{
  rightBar.setup(Trill::TRILL_BAR, 33);
  rightBar.setScanSettings(0, 9);
}

void read(void (*scc_func)(uint8_t, uint8_t, uint8_t))
{
    rightBar.read();
    
    if (rightBar.getNumTouches() > 0)
    {
        uint8_t rightLoc = rightBar.touchLocation(0) / 25;

        scc_func(15, rightLoc, 7);
    }
}
} // namespace MDTouch