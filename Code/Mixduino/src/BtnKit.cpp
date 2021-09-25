#include "BtnKit.h"

const byte totalButtons = nASw + nSwMuxLeft + nSwMuxRight;
int buttonCState[totalButtons] = {};
int buttonPState[totalButtons] = {};

Multiplexer4067 mplexSwLeft = Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
Multiplexer4067 mplexSwRight = Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);

/////////////////////////////////////////////
// debounce
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 5;

int BtnKit::parseValue(int value) {
	if (value > 100)
    {
        return HIGH;
    }
    return LOW;
}

void BtnKit::begin()
{
    mplexSwLeft.begin();
    mplexSwRight.begin();
    for (byte i = 0; i < nASw; i++)
    {
        pinMode(aSwSet[i], INPUT_PULLUP);
    }
}


void BtnKit::read(void (*func)(byte, byte, byte))
{

    for (byte i = 0; i < nSwMuxLeft; i++)
    {
        buttonCState[i] = this->parseValue(mplexSwLeft.readChannel(SwMuxLeftSet[i]));
    }

    for (byte i = 0; i < nSwMuxRight; i++)
    {
        buttonCState[i + nSwMuxLeft] = this->parseValue(mplexSwRight.readChannel(SWMuxRightSet[i]));
    }
    

    for (byte i = 0; i < nASw; i++)
    {
        buttonCState[i + nSwMuxLeft + nSwMuxRight] = digitalRead(aSwSet[i]);
    }

    for (byte i = 0; i < totalButtons; i++)
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
