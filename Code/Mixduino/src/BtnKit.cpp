#include "BtnKit.h"

const byte buttonPin[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 41, 42, 43, 44, 45, 46, 68};
const byte nButtons = 41;
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
        pinMode(buttonPin[i], INPUT_PULLUP);
    }
}


void BtnKit::read(void (*func)(byte, byte, byte))
{
    for (byte i = 0; i < nButtons; i++)
    {
        buttonCState[i] = digitalRead(buttonPin[i]);
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
