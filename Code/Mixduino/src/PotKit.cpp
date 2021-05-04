#include "PotKit.h"

const byte muxPotPin[] = {0, 1, 2, 3, 4, 5, 6, 15, 14, 13, 12, 11, 10, 8};
const byte NPotPin[] = {
    GAIN_L3,
    GAIN_L2,
    GAIN_L1,
    PFXL_3,
    PFXL_2,
    PFXL_1,
    PFXR_3,
    PFXR_2,
    PFXR_1,
    TRE_L3,
    TRE_L2,
    TRE_L1,
    PMASTER
};
const byte totalPots = sizeof(NPotPin) + sizeof(muxPotPin);

int potCState[totalPots] = {}; // current state
int potPState[totalPots] = {}; // previous state
int potVar = 0;                // prev/current variation
int lastCcValue[totalPots] = {};

Multiplexer4067 mplexPots = Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A0);

byte TIMEOUT = 50;
byte varThreshold = 8;
boolean potMoving = true;
unsigned long pTime[totalPots] = { };
unsigned long timer[totalPots] = { };

void PotKit::begin()
{
    pinMode(MPLEX_A0, INPUT_PULLUP);
    mplexPots.begin();
}

void PotKit::read(void (*scc_func)(byte, byte, byte))
{
    for (byte i = 0; i < sizeof(muxPotPin); i++)
    {
        potCState[i] = mplexPots.readChannel(muxPotPin[i]);
    }

    for (byte i = 0; i < sizeof(NPotPin); i++)
    {
        potCState[i + sizeof(muxPotPin)] = analogRead(NPotPin[i]);
    }

    for (byte i = 0; i < totalPots; i++)
    {

        potVar = abs(potCState[i] - potPState[i]); // calcula a variacao da porta analogica

        if (potVar >= varThreshold)
        {
            pTime[i] = millis(); // armazena o tempo previo
        }
        timer[i] = millis() - pTime[i]; // reseta o timer
        if (timer[i] < TIMEOUT)
        { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
            potMoving = true;
        }
        else
        {
            potMoving = false;
        }

        if (potMoving == true)
        { // se o potenciometro ainda esta se movendo, mande o control change
            int ccValue = map(potCState[i], 0, 1023, 0, 127);
            if (lastCcValue[i] != ccValue)
            {
                scc_func(i, map(potCState[i], 0, 1023, 0, 127), 11); // envia Control Change (numero do CC, valor do CC, canal midi)
                potPState[i] = potCState[i];                         // armazena a leitura atual do potenciometro para comparar com a proxima
                lastCcValue[i] = ccValue;
            }
        }
    }
}
