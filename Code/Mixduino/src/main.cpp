#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "MDCore.h"
#include "BREncoder.h"
#include "BtnKit.h"
#include "PotKit.h"
#include "TouchKit.h"
// Rev2 Version

MIDI_CREATE_DEFAULT_INSTANCE();

BREncoder enc;
TouchKit touchBar;
BtnKit buttons;
PotKit pots;
MDCore mdCore;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(byte channel, byte number, byte value);
void handleNoteOn(byte channel, byte number, byte value);
void handleNoteOff(byte channel, byte number, byte value);
void readButtons();
void readPots();
void readEncoder();
void readTouchBar();
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
  touchBar.begin();
  buttons.begin();
  pots.begin();
  mdCore.begin();

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
  readTouchBar();
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
  enc.readEnc(sendMidiCC);
}

void readTouchBar()
{
  touchBar.touchRead(sendMidiCC);
}

void sendMidiNote(byte number, byte value, byte channel)
{
  MIDI.sendNoteOn(number, value, channel);
}

void sendMidiCC(byte number, byte value, byte channel)
{
  MIDI.sendControlChange(number, value, channel);
}
