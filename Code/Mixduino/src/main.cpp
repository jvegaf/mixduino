#include <Arduino.h>
#include <MIDI.h>
// #include <Multiplexer4067.h>
#include <Thread.h>
#include <ThreadController.h>
#include "MDCore.h"
#include "BREncoder.h"
#include "BtnKit.h"

MIDI_CREATE_DEFAULT_INSTANCE();
/////////////////////////////////////////////
// buttons

/////////////////////////////////////////////
// potentiometers
// const uint8_t NPotPin[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};              //
// const uint8_t muxPotPin[] = {0, 1, 2, 3, 4, 5, 6, 15, 14, 13, 12, 11, 10, 8};
// const uint8_t totalPots = sizeof(NPotPin) + sizeof(muxPotPin);

//  // *neste array coloque na ordem desejada os pinos das portas analogicas, ou mux channel, utilizadas
// int potCState[totalPots] = {0};                                                      // estado atual da porta analogica
// int potPState[totalPots] = {0};                                                      // estado previo da porta analogica
// int potVar = 0;                                                                      // variacao entre o valor do estado previo e o atual da porta analogica
// int lastCcValue[totalPots] = {0};

/////////////////////////////////////////////
// // pot reading
// uint8_t TIMEOUT = 50;                 //quantidade de tempo em que o potenciometro sera lido apos ultrapassar o varThreshold
// uint8_t varThreshold = 8;         //threshold para a variacao no sinal do potenciometro
// boolean potMoving = true;         // se o potenciometro esta se movendo
// unsigned long pTime[sizeof(NPotPin)] = { }; // tempo armazenado anteriormente
// unsigned long timer[sizeof(NPotPin)] = { }; // armazena o tempo que passou desde que o timer foi zerado

/////////////////////////////////////////////
// encoder
BREncoder brEnc;
BtnKit buttons;
MDCore mdCore;


/////////////////////////////////////////////
// Multiplexer
// Multiplexer4067 mplexPots = Multiplexer4067(47, 49, 40, 53, A0);

/////////////////////////////////////////////
// threads - programa cada atividade do Arduino para acontecer em um determinado tempo
ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
// Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
// void readPots();
void readEncoder();
void sendMidiNote(uint8_t number, uint8_t value, uint8_t channel);


/////////////////////////////////////////////
void setup()
{

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa

  MIDI.turnThruOff();
  buttons.begin();
  mdCore.begin();

  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  /////////////////////////////////////////////
  // Multiplexers
  // mplexPots.begin();         // inicializa o multiplexer
  // pinMode(A0, INPUT_PULLUP); // pots need input pull up


  /////////////////////////////////////////////
  // threads
  // pots
  // threadReadPots.setInterval(10);
  // threadReadPots.onRun(readPots);
  // cpu.add(&threadReadPots);

  // buttons
  threadReadButtons.setInterval(20);
  threadReadButtons.onRun(readButtons);
  cpu.add(&threadReadButtons);
}

void loop()
{
  cpu.run();
  MIDI.read();
  readEncoder();
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.cChange(number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.noteOn(channel, number, value);
}
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.noteOff(number, value);
}

/////////////////////////////////////////////
// read buttons

void readButtons()
{
  buttons.read(sendMidiNote);
}

////////////////////////////////////////////
//read potentiometers

// void readPots()
// {

//   for (uint8_t i = 0; i < sizeof(muxPotPin); i++)
//   { // le todas entradas analogicas utilizadas, menos a dedicada a troca do canal midi
//     potCState[i] = mplexPots.readChannel(muxPotPin[i]);
//   }

//   for (uint8_t i = 0; i < sizeof(NPotPin); i++)
//   { // le todas entradas analogicas utilizadas, menos a dedicada a troca do canal midi
//     potCState[i + sizeof(muxPotPin)] = analogRead(NPotPin[i]);
//   }

//   for (uint8_t i = 0; i < totalPots; i++)
//   {

//     potVar = abs(potCState[i] - potPState[i]); // calcula a variacao da porta analogica

//     if (potVar >= varThreshold)
//     {                      //sets a threshold for the variance in the pot state, if it varies more than x it sends the cc message
//       pTime[i] = millis(); // armazena o tempo previo
//     }
//     timer[i] = millis() - pTime[i]; // reseta o timer
//     if (timer[i] < TIMEOUT)
//     { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
//       potMoving = true;
//     }
//     else
//     {
//       potMoving = false;
//     }

//     if (potMoving == true)
//     { // se o potenciometro ainda esta se movendo, mande o control change
//       int ccValue = map(potCState[i], 0, 1023, 0, 127);
//       if (lastCcValue[i] != ccValue)
//       {
//         MIDI.sendControlChange(i, map(potCState[i], 0, 1023, 0, 127), 11); // envia Control Change (numero do CC, valor do CC, canal midi)
//         potPState[i] = potCState[i];                                            // armazena a leitura atual do potenciometro para comparar com a proxima
//         lastCcValue[i] = ccValue;
//       }
//     }
//   }
// }

void readEncoder()
{

  int position = brEnc.readEnc();

  MIDI.sendControlChange(14, position, 1);
}

void sendMidiNote(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOn(number, value, channel);
}