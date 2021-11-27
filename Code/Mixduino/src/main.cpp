#include "MDCore.h"
#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

MDCore* mdCore { nullptr };

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void onChangeSelectDeck();
void onChangePadMode(uint8_t align);
void readButtons();
void readPots();
void readEncoder();
void readTouchBars();
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);

  mdCore = new MDCore(
    sendMidiNoteOn,
    sendMidiNoteOff,
    sendMidiCC,
    onChangePadMode,
    onChangeSelectDeck
  );


  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  mdCore->begin();

  /////////////////////////////////////////////
  // threads
  // pots
  threadReadPots.setInterval(10);
  threadReadPots.onRun(readPots);
  cpu.add(&threadReadPots);

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
  readTouchBars();
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore->onCChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore->onNoteOn(channel, number, value);
}

void readButtons()
{
  mdCore->readButtons();
}

void readPots()
{
  mdCore->readPots();
}

void readEncoder()
{
  
}

void readTouchBars()
{
  
}

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

void onChangeSelectDeck()
{
  
}
