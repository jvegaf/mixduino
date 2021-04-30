#include "NPKit.h"

// const int PADL_SIGPIN = 48;
// const int PADR_SIGPIN = 46;
const byte SIGPIN = 8; 
const int NUMPIXELS = 12;

Adafruit_NeoPixel adaPx(NUMPIXELS, SIGPIN, NEO_GRB + NEO_KHZ800);

uint32_t BLUE = adaPx.Color(0, 0, 255);
uint32_t GREEN = adaPx.Color(0, 255, 0);
uint32_t YELLOW = adaPx.Color(255, 230, 0);
uint32_t ORANGE = adaPx.Color(255, 153, 51);
uint32_t RED = adaPx.Color(255, 0, 0);
uint32_t CLEAR = adaPx.Color(0, 0, 0);


uint32_t colors[] = {
    YELLOW, // CUE
    GREEN   // PLAY
};

// Range: -1 to 5 MAPED TO 0-6 (-1 = no hotcue, 0 = Cue, 1 = FadeIn, 2 = FadeOut, 3 = Load, 4 = Grid, 5 = Loop)
uint32_t HCCols[] = {
    CLEAR,
    YELLOW, 
    ORANGE,
    ORANGE,
    RED,
    BLUE,
    GREEN
};



NPKit::NPKit(byte firstNum)
{
    this->firstNumber = firstNum;
}

void NPKit::begin() 
{
    adaPx.begin();
    adaPx.show();
    adaPx.setBrightness(4); // 0 - 255
}

void NPKit::handleON(byte number) 
{
    adaPx.setPixelColor(number, colors[number]);
    adaPx.show();
}

void NPKit::handleON(byte number, byte value) 
{
    byte reqNum = number - firstNumber;
    if (reqNum < 2) { handleON(reqNum); return; }

    handleHotCUE(reqNum, value);
}

void NPKit::handleOFF(byte number) 
{
    byte reqNum = number - firstNumber;

    adaPx.setPixelColor(reqNum, CLEAR);
    adaPx.show();
}

void NPKit::handleHotCUE(byte number, byte value) 
{
    adaPx.setPixelColor(number, HCCols[value]); 
    adaPx.show();
}


void NPKit::clearAll() 
{
    for (int i = 0; i < NUMPIXELS; i++)
    {
        adaPx.setPixelColor(i, CLEAR);
    }
    
    adaPx.show();
}



////////////
// play 

