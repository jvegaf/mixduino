#include "PotKit.h"


const uint8_t totalPots = nAPots + nTopMuxpots + nBottomMuxPots;

int potCState[totalPots] = {}; // current state
int potPState[totalPots] = {}; // previous state
int potVar = 0;                // prev/current variation
int lastCcValue[totalPots] = {};

Multiplexer4067 mplexTopPots = Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, TOP_POTMUX_SIG);
Multiplexer4067 mplexBottomPots = Multiplexer4067(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, BOTTOM_POTMUX_SIG);

uint8_t TIMEOUT = 50;
uint8_t varThreshold = 8;
boolean potMoving = true;
unsigned long pTime[totalPots] = {};
unsigned long timer[totalPots] = {};

void PotKit::begin()
{
    mplexTopPots.begin();
    mplexBottomPots.begin();
}

void PotKit::read(void (*scc_func)(uint8_t, uint8_t, uint8_t))
{
    for (uint8_t i = 0; i < nTopMuxpots; i++)
    {
        potCState[i] = mplexTopPots.readChannel(topMuxpotsSet[i]);
    }

    for (uint8_t i = 0; i < nBottomMuxPots; i++)
    {
        potCState[i + nTopMuxpots] = mplexBottomPots.readChannel(bottomMuxpotsSet[i]);
    }

    for (uint8_t i = 0; i < nAPots; i++)
    {
        potCState[i + nTopMuxpots + nBottomMuxPots] = analogRead(aPotsSet[i]);
    }

    for (uint8_t i = 0; i < totalPots; i++)
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
            uint8_t ccValue = map(potCState[i], 0, 1023, 0, 127);
            if (lastCcValue[i] != ccValue)
            {
                scc_func(i, ccValue, 11); // envia Control Change (numero do CC, valor do CC, canal midi)
                potPState[i] = potCState[i];                         // armazena a leitura atual do potenciometro para comparar com a proxima
                lastCcValue[i] = ccValue;
            }
        }
    }
}
