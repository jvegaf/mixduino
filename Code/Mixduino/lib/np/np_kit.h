
#ifndef NPKIT_H
#define NPKIT_H
#include <Adafruit_NeoPixel.h>
#include <Arduino.h>
#include <output_base.h>


static uint32_t CLEAR_COL= Adafruit_NeoPixel::Color(0, 0, 0);
static uint32_t BLUE_COL = Adafruit_NeoPixel::Color(0, 0, 255);
static uint32_t GREEN_COL = Adafruit_NeoPixel::Color(0, 255, 0);
static uint32_t RED_COL  = Adafruit_NeoPixel::Color(255, 0, 0);
static uint32_t YELLOW_COL = Adafruit_NeoPixel::Color(255, 230, 0);
static uint32_t ORANGE_COL = Adafruit_NeoPixel::Color(255, 143, 0);
static uint32_t PURPLE_COL = Adafruit_NeoPixel::Color(243, 0, 255);
static uint32_t GRAY_COL = Adafruit_NeoPixel::Color(191, 201, 202);
static uint32_t MAGENTA_COL = Adafruit_NeoPixel::Color(255, 0, 255);
static uint32_t MAROON_COL = Adafruit_NeoPixel::Color(128, 0, 0);

// Range: -1 to 5 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
// mapped 0 to 6
static uint32_t HCCols[] = {
    CLEAR_COL,      // no hotcue
    BLUE_COL,       // cue
    ORANGE_COL,     // fade out
    YELLOW_COL,        // load
    GRAY_COL,       // grid
    GREEN_COL,       // loop
    RED_COL,
    PURPLE_COL,
	MAGENTA_COL,
	MAROON_COL
};

class NPKit : public OutputBase 
{
	private:
		Adafruit_NeoPixel* _npx;
		uint8_t _brightness;
	public:

		NPKit(uint8_t totalPix, uint8_t dataPin, uint8_t brightness);

		NPKit() = default;

		void begin();

		void setTo(OutDTO od);
		
		void clearAll();
};

#endif
