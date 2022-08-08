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
const uint32_t HCCols[] = {
    CLEAR_COL,      // no hotcue
    BLUE_COL,       // cue
    ORANGE_COL,     // fade in out
    YELLOW_COL,        // load
    GRAY_COL,       // grid
    GREEN_COL,
};

const uint32_t cue_color = BLUE_COL;
const uint32_t fadein_color = ORANGE_COL;
const uint32_t fadeout_color = ORANGE_COL;
const uint32_t load_color = YELLOW_COL;
const uint32_t grid_color = GRAY_COL;
const uint32_t loop_color = GREEN_COL;
  
} // namespace MDColor




