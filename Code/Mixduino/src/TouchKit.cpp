#include "TouchKit.hpp"

namespace input
{

    Trill leftBar;
    Trill rightBar;

    TouchKit::TouchKit()
    {
    }

    void TouchKit::begin()
    {
        leftBar.setup(Trill::TRILL_BAR, 32);
        leftBar.setScanSettings(0, 9);
        rightBar.setup(Trill::TRILL_BAR, 33);
        rightBar.setScanSettings(0, 9);
    }

    void TouchKit::touchRead(void (*scc_func)(uint8_t, uint8_t, uint8_t))
    {
        leftBar.read();

        if (leftBar.getNumTouches() > 0)
        {
            uint8_t leftLoc = leftBar.touchLocation(0) / 25;

            scc_func(14, leftLoc, 7);
        }

        rightBar.read();

        if (rightBar.getNumTouches() > 0)
        {
            uint8_t rightLoc = rightBar.touchLocation(0) / 25;

            scc_func(15, rightLoc, 7);
        }
    }
} // namespace input
