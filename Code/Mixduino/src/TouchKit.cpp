#include "TouchKit.h"

Trill trillSensor;

TouchKit::TouchKit()
{
}

void TouchKit::begin()
{
    trillSensor.setup(Trill::TRILL_BAR);
    trillSensor.setScanSettings(0,9);
}

void TouchKit::touchRead(void (*scc_func)(byte, byte, byte))
{
    trillSensor.read();

    if (trillSensor.getNumTouches() < 1)
    {
        return;
    }

    byte location = trillSensor.touchLocation(0)/25;

    scc_func(14, location, 7);
}