#include "BtnKit.h"

const byte buttonPins[] = {
    SWPADL_1,
    SWPADL_2,
    SWPADL_3,
    SWPADL_4,
    SWPADL_5,
    SWPADL_6,
    SWPADL_7,
    SWPADL_8,
    SWPADR_1,
    SWPADR_2,
    SWPADR_3,
    SWPADR_4,
    SWPADR_5,
    SWPADR_6,
    SWPADR_7,
    SWPADR_8,
    SWFXL_1,
    SWRANGE_L,
    SWSYNC_L,
    SWCUE_L,
    SWPLAY_L,
    SWFXR_1,
    SWFXR_2,
    SWFXR_3,
    SWRANGE_R,
    SWSYNC_R,
    SWCUE_R,
    SWPLAY_R,
    SW_PREVIEW,
    SW_BACK,
    SW_BROWSER_L,
    SW_BROWSER_R,
    DECK_SEL,
    SWSHIFT,
    SWPRECUE_L1,
    SWPRECUE_L2,
    SWPRECUE_L3,
};
const byte nButtons = 37;
int buttonCState[nButtons] = {};
int buttonPState[nButtons] = {};
/////////////////////////////////////////////
// debounce
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;

void BtnKit::begin()
{
    for (byte i = 0; i < nButtons; i++)
    {
        pinMode(buttonPins[i], INPUT_PULLUP);
    }
}


void BtnKit::read(void (*func)(byte, byte, byte))
{
    for (byte i = 0; i < nButtons; i++)
    {
        buttonCState[i] = digitalRead(buttonPins[i]);
    }

    for (byte i = 0; i < nButtons; i++)
    {

        if ((millis() - lastDebounceTime) > debounceDelay)
        {

            if (buttonCState[i] != buttonPState[i])
            {
                lastDebounceTime = millis();

                if (buttonCState[i] == LOW)
                {
                    func(i,127,10); // envia NoteOn(nota, velocity, canal midi)
                    buttonPState[i] = buttonCState[i];
                }
                else
                {
                    func(i, 0, 10 );
                    buttonPState[i] = buttonCState[i];
                }
            }
        }
    }
}
