#ifndef __MD_COLORS_H__
#define __MD_COLORS_H__

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

const uint32_t CLEAR_COL  = Adafruit_NeoPixel::Color(0, 0, 0);
const uint32_t BLUE_COL   = Adafruit_NeoPixel::Color(0, 0, 255);
const uint32_t GREEN_COL  = Adafruit_NeoPixel::Color(0, 255, 0);
const uint32_t RED_COL    = Adafruit_NeoPixel::Color(255, 0, 0);
const uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
const uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 143, 0);
const uint32_t PURPLE_COL = Adafruit_NeoPixel::Color(243, 0, 255);
const uint32_t GRAY_COL   = Adafruit_NeoPixel::Color(191, 201, 202);

const uint8_t t_pixels = 21;

#endif // __MD_COLORS_H__
