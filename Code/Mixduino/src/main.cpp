#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "midi_map.h"
#include "md_output.hpp"
#include "md_input.hpp"
#include "BREncoder.hpp"
#include "BtnKit.h"
#include "PotKit.h"
#include "md_touch.hpp"
#include "pad.hpp"


// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

PotKit pots;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

Selected deckSelected = Selected::Deck_B;

Pad::Mode padDeckA = Pad::Mode::HotCues;
Pad::Mode padDeckB = Pad::Mode::HotCues;
Pad::Mode padDeckC = Pad::Mode::HotCues;

uint8_t padLCh = hotcues_ch;
uint8_t padRCh = hotcues_ch;


void changeDeck();
void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
void readPots();
void readTouchBars();
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  // Serial.begin(31250);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  pots.begin();
  MDInput::initialize();
  MDOutput::initialize();
  MDTouch::initialize();
  // Set Deck B Focus
  // MIDI.sendNoteOn(1, 127, 9);

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
  MDEncoder::read(sendMidiCC);
  MDTouch::read(sendMidiCC);
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  MDOutput::cChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  MDOutput::noteOn(channel, number, value);
}

void changeDeck() {
  switch (deckSelected)
  {
  case Selected::Deck_B:
    deckSelected = Selected::Deck_C;
    padRCh = padDeckC;
    break;
  
  case Selected::Deck_C:
    deckSelected = Selected::Deck_B;
    padRCh = padDeckB;
    break;
  }
}


void changePadL() {
    padDeckA = Pad::change(padDeckA);
}

void changePadR(){
  switch (deckSelected)
  {
  case Selected::Deck_B:
    padDeckB = Pad::change(padDeckB);
    break;

  case Selected::Deck_C:
    padDeckC = Pad::change(padDeckC);
    break;
  }
}

void readButtons()
{
  MDInput::readSelector(&changeDeck);
  MDInput::readPadMode(&changePadL, Location::Left);
  MDInput::readPadMode(&changePadR, Location::Right);
  MDInput::read(sendMidiNoteOn, padLCh, padRCh);
}

void readPots()
{
  pots.read(sendMidiCC);
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
