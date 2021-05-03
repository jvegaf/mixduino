#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "MDCore.h"
#include "BREncoder.h"
#include "BtnKit.h"
#include "PotKit.h"

MIDI_CREATE_DEFAULT_INSTANCE();

BREncoder brEnc;
BtnKit buttons;
PotKit pots;
MDCore mdCore;


ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes



void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
void readPots();
void readEncoder();
void sendMidiNote(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);



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


void readButtons()
{
  buttons.read(sendMidiNote);
}

void readPots()
{
  pots.read(sendMidiCC);
}

void readEncoder()
{

  int position = brEnc.readEnc();

  MIDI.sendControlChange(14, position, 1);
}

void sendMidiNote(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOn(number, value, channel);
}

void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendControlChange(number, value, channel);
}

