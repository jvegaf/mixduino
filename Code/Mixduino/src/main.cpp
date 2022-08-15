#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include "md_init.h"
#include "md_enums.hpp"
#include "PotKit.h"
#include "md_pad.hpp"
#include "BREncoder.hpp"
#include "md_touch.hpp"
#include "md_input.hpp"
#include "components_def.h"








// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

PotKit pots;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

ActiveDeck rightDeck = ActiveDeck::Deck_B;

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);

Pad padA(pad_A_notes, sendMidiNoteOn);
Pad padB(pad_C_notes, sendMidiNoteOn);
Pad padC(pad_C_notes, sendMidiNoteOn);

void changeDeck();

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleEvent(uint8_t component_id, State state);
void readButtons();
void readPots();
void readTouchBars();
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  // Serial.begin(31250);
  MD::initPins();
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
  pots.begin();
  // Set Deck B Focus
  // MIDI.onNoteOn(1, 127, 9);

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
  // MDFeedback::onCChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  // MDFeedback::onNoteOn(channel, number, value);
}


void changeDeck() {
  if (rightDeck == ActiveDeck::Deck_B)
  {
    rightDeck = ActiveDeck::Deck_C;
    return;
  }

  rightDeck = ActiveDeck::Deck_B;
}

void readButtons()
{
  MDInput::read(handleEvent);
}

void readPots()
{
  pots.read(sendMidiCC);
}

void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendNoteOn(number, value, channel);
}


void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel)
{
  MIDI.sendControlChange(number, value, channel);
}

inline void handleEvent(uint8_t component_id, State state) {
  switch (component_id)
  {
  case 11 ... 15 :
    // mixer
    break;
  
  case 16 ... 20:
    // browser
    break;
  
  case 21 ... 23:
    //fx 1
    break;

  case 24 ... 26:
    // fx 2
    break;
  
  case 27 ... 31:
    //deck L
    break;
  
  case 32 ... 40:
    // deck r
    break;

  case 41 ... 48:
    padA.sendNote(component_id, state);
    break;
  
  case 49 ... 64:
    {
      if (rightDeck == ActiveDeck::Deck_B) {
        padB.sendNote(component_id, state);
        return;
      }
      padC.sendNote(component_id, state);
    }
    break;

  

    
  default:
    break;
  }
}