#include "Deck.h"  

Deck::Deck(MuxBtnSet bset, LedSet lset, NPxSet npSet)
{
	buttons = bset.set;
    modeBtn = bset.modeBtn;
    leds = lset.set;
    npixels = npSet.set;
    totalButtons = bset.totalBtns;
    totalLeds = lset.totalLeds;
    totalNpxls = npSet.totalNpixels;
}

Deck::begin(Adafruit_NeoPixel* aNP) {
	for (int i = 0; i < totalButtons; i++)
    {
        buttons[i].begin();
    }

    for (size_t i = 0; i < totalNpxls; i++)
    {
        npixels[i].setNPObject(aNP);
    }
    
    
}


