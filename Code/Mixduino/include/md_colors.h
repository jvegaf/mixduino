#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

namespace MDColor
{
const uint32_t CLEAR_COL  = Adafruit_NeoPixel::Color(0, 0, 0);
const uint32_t BLUE_COL   = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t GREEN_COL  = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t RED_COL    = Adafruit_NeoPixel::Color(255, 0, 0);
const uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
const uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 143, 0);
const uint32_t PURPLE_COL = Adafruit_NeoPixel::Color(243, 0, 255);
const uint32_t GRAY_COL   = Adafruit_NeoPixel::Color(191, 201, 202);

const uint8_t t_pixels = 21;

const uint8_t BRIGHTNESS = 32;

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6

const uint32_t hotcues_t[] {
    BLUE_COL,
    ORANGE_COL,
    ORANGE_COL,
    YELLOW_COL,
    GRAY_COL,
    GREEN_COL
};

const uint32_t HotCueColorMode = CLEAR_COL;
const uint32_t LoopColorMode = GREEN_COL; 
const uint32_t BeJumpColorMode = ORANGE_COL; 
const uint32_t TRangeColorMode = PURPLE_COL; 
  
} // namespace MDColor




