#pragma once
#include <Arduino.h>
namespace mixduino
{
    static const uint32_t kDEBOUNCEDELAY = 20;
    static const uint8_t kTIMEOUT        = 50;
    static const uint8_t kTHRESHOLD      = 8;

    // Touchbars
    static const uint8_t kScanSpeed   = 0;
    static const uint8_t kScanNumBits = 9;

    static const uint16_t kTouchLeftAddr  = 32;
    static const uint16_t kTouchRightAddr = 33;
} // namespace mixduino
