// #include "BREncoder.h"
#include "pin_map.h"
#include "Core.hpp"
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

// BREncoder encL(L_BROWSER_A, L_BROWSER_B);
// BREncoder encR(R_BROWSER_A, R_BROWSER_B);


MD::Core* core = nullptr;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadLeft;    // thread para controlar os pots
Thread threadReadRight; // thread para controlar os botoes

void initializePins();
void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void readLeftDeck();
void readRightDeck();
// void readEncoder();
// void readTouchBars();
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  initializePins();
  // Serial.begin(31250);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  core = new MD::Core(sendMidiNoteOn, sendMidiNoteOff, sendMidiCC);
  
  // touchBars.begin();
  // Set Deck B Focus
  // MIDI.sendNoteOn(1, 127, 9);

  /////////////////////////////////////////////
  // threads
  // pots
  threadReadLeft.setInterval(10);
  threadReadLeft.onRun(readLeftDeck);
  cpu.add(&threadReadLeft);

  // buttons
  threadReadRight.setInterval(20);
  threadReadRight.onRun(readRightDeck);
  cpu.add(&threadReadRight);
}

void loop()
{
  cpu.run();
  MIDI.read();
  // readEncoder();
  // readTouchBars();
}

inline void initializePins() {
  for (auto i = 0; i < MD::T_MUXPIN_BUNDLE; i++)
  {
    pinMode(MD::MUXPIN_BUNDLE[i], OUTPUT);
  }
  for (auto i = 0; i < MD::T_ARD_SW_BUNDLE; i++)
  {
    pinMode(MD::ARD_SW_BUNDLE[i], INPUT_PULLUP);
  }
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  core->onCChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  core->onNoteOn(channel, number, value);
}


void readLeftDeck()
{
  core->readDeckLeft();
}

void readRightDeck()
{
  core->readDeckRight();
}

// void readEncoder()
// {
//   encL.readEnc(sendMidiCC);
//   encR.readEnc(sendMidiCC);
// }

// void readTouchBars()
// {
//   touchBars.touchRead(sendMidiCC);
// }

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOn(number, value, channel);
}

void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOff(number, value, channel);
}

void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendControlChange(number, value, channel);
}
