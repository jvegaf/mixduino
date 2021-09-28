#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "MDCore.h"
#include "BREncoder.h"
#include "BtnKit.h"
#include "PotKit.h"
#include "TouchKit.h"
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

BREncoder encL(L_BROWSER_A, L_BROWSER_B);
BREncoder encR(R_BROWSER_A, R_BROWSER_B);
BtnKit buttons;
PotKit pots;
MDCore mdCore;
TouchKit touchBars;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(byte channel, byte number, byte value);
void handleNoteOn(byte channel, byte number, byte value);
void handleNoteOff(byte channel, byte number, byte value);
void readButtons();
void readPots();
void readEncoder();
void readTouchBars();
void sendMidiNote(byte number, byte value, byte channel);
void sendMidiCC(byte number, byte value, byte channel);

void setup()
{
  // Serial.begin(31250);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  buttons.begin();
  pots.begin();
  mdCore.begin();
  touchBars.begin();
  // Set Deck B Focus
  MIDI.sendNoteOn(1, 127, 9);

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

void handleControlChange(byte channel, byte number, byte value)
{
  mdCore.cChange(channel, number, value);
}

void handleNoteOn(byte channel, byte number, byte value)
{
  if (value < 1U)
  {
    mdCore.noteOff(channel, number, value);
    return;
  }
  mdCore.noteOn(channel, number, value);
}
void handleNoteOff(byte channel, byte number, byte value)
{
  mdCore.noteOff(channel, number, value);
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
  encL.readEnc(sendMidiCC);
  encR.readEnc(sendMidiCC);
}

void readTouchBars()
{
  touchBars.touchRead(sendMidiCC);
}

void sendMidiNote(byte number, byte value, byte channel)
{
  MIDI.sendNoteOn(number, value, channel);
}

void sendMidiCC(byte number, byte value, byte channel)
{
  MIDI.sendControlChange(number, value, channel);
}
