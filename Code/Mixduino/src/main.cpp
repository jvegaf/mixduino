#include <MDCore.h>
#include <Arduino.h>
#include <Thread.h>
#include <ThreadController.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();

MDCore mdCore;
Deck* deckLeft;
Deck* deckRight;
Pad* padLeft;
Pad* padRight;
// TouchKit touchBars;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
// Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value);
void readDecks();
// void readPots();
// void readEncoder();
// void readTouchBars();
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
// void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  // MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();
 
  // pots.begin();
  // leftBtns.begin();
  // rightBtns.begin();
  // btns.begin(BTNS_CH);
  mdCore.begin(sendMidiNoteOn, sendMidiNoteOff);
  deckLeft = mdCore.getDeck(MDAlign::AlignType::LEFT_ALIGN);
  deckRight = mdCore.getDeck(MDAlign::AlignType::RIGHT_ALIGN);
  padLeft = mdCore.getPad(MDAlign::AlignType::LEFT_ALIGN);
  padRight = mdCore.getPad(MDAlign::AlignType::RIGHT_ALIGN);
  // touchBars.begin();
  // Send monitor state
  // MIDI.sendNoteOn(SEND_MON_STATE, 127, 1);

  /////////////////////////////////////////////
  // threads
  // pots
  // threadReadPots.setInterval(10);
  // threadReadPots.onRun(readPots);
  // cpu.add(&threadReadPots);

  // // buttons
  threadReadButtons.setInterval(20);
  threadReadButtons.onRun(readDecks);
  cpu.add(&threadReadButtons);
}

void loop()
{
  cpu.run();
  // readDecks();
  MIDI.read();
}


void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  switch (channel)
  {
  case DECK_LEFT_FUNCS_MIDI_CH :
    deckLeft->onNoteOn(number, value);
    break;
  case DECK_LEFT_PAD_FUNCS_MIDI_CH :
    padLeft->onNoteOn(number, value);
    break;
  case DECK_RIGHT_FUNCS_MIDI_CH :
    deckRight->onNoteOn(number, value);
    break;
  case DECK_RIGHT_PAD_FUNCS_MIDI_CH :
    padRight->onNoteOn(number, value);
    break;

  default:
    break;
  }
}

void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
   switch (channel)
  {
  case DECK_LEFT_FUNCS_MIDI_CH :
    deckLeft->onNoteOff(number, value);
    break;
  case DECK_LEFT_PAD_FUNCS_MIDI_CH :
    padLeft->onNoteOff(number, value);
    break;
  case DECK_RIGHT_FUNCS_MIDI_CH :
    deckRight->onNoteOff(number, value);
    break;
  case DECK_RIGHT_PAD_FUNCS_MIDI_CH :
    padRight->onNoteOff(number, value);
    break;

  default:
    break;
  }
}

void readDecks() {
  deckLeft->read();
  deckRight->read();
  padLeft->read();
  padRight->read();
}

// void readPots()
// {
//   pots.read(sendMidiCC);
// }

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
