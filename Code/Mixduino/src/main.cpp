#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include <EventManager.h>
#include "constants.h"
#include "board.h"
#include "board_map.h"
#include "str_reqs.h"
#include "midi_map.h"
#include "mdcore.hpp"
#include "encoder.hpp"
#include "button_mux.hpp"
#include "button.hpp"
#include "pot.hpp"
#include "pot_mux.hpp"
#include "touchbar.hpp"
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

EventManager gEM;

mixduino::MDEncoder encL(L_BROWSER_A, L_BROWSER_B);
mixduino::MDEncoder encR(R_BROWSER_A, R_BROWSER_B);
mixduino::Pot pots(kPotsBundle, kTPotsBndl);
mixduino::MuxPot topMuxPots(mixduino::topMPotsReqs);
mixduino::MuxPot btmMuxPots(mixduino::btMPotsReqs);
mixduino::MuxButton leftBtns(mixduino::lMBtnsReqs);
mixduino::MuxButton rightBtns(mixduino::rMBtnsReqs);
mixduino::Button btns(aSwSet, nASw);

mdcore::Core mdCore;
mixduino::TouchBar leftTBar(mixduino::kTouchLeftAddr);
mixduino::TouchBar rightTBar(mixduino::kTouchRightAddr);

ThreadController cpu;     // thread master, onde as outras vao ser adicionadas
Thread threadReadPots;    // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value);
void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value);
void readButtons();
void readPots();
void readEncoder();
void readTouchBars();
void btnPressedListener(int event, int param);
void btnReleasedListener(int event, int param);
void potMovedListener(int event, int param);
void touchEventListener(int event, int param);
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);
void initializePins();

void setup()
{
  // Serial.begin(31250);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();

  initializePins();

  gEM.addListener(EventManager::kEventKeyPress, btnPressedListener);
  gEM.addListener(EventManager::kEventKeyRelease, btnReleasedListener);
  gEM.addListener(EventManager::kEventAnalog0, potMovedListener);
  gEM.addListener(EventManager::kEventUser0, touchEventListener);

  topMuxPots.begin();
  btmMuxPots.begin();

  mdCore.begin();
  leftTBar.begin();
  rightTBar.begin();
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
  readEncoder();
  readTouchBars();
}

void handleControlChange(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.cChange(channel, number, value);
}

void handleNoteOn(uint8_t channel, uint8_t number, uint8_t value)
{
  if (value < 1U)
  {
    mdCore.noteOff(channel, number, value);
    return;
  }
  mdCore.noteOn(channel, number, value);
}

void handleNoteOff(uint8_t channel, uint8_t number, uint8_t value)
{
  mdCore.noteOff(channel, number, value);
}

void readButtons()
{
  leftBtns.read(gEM, mixduino::leftMuxBtnEvents);
  rightBtns.read(gEM, mixduino::rightMuxBtnEvents);
  btns.read(gEM, mixduino::buttonsEvents);
}

void readPots()
{
  topMuxPots.read(gEM, mixduino::topMuxPotsEvents);
  btmMuxPots.read(gEM, mixduino::bottomMuxPotsEvents);
  pots.read(gEM, mixduino::potsEvents);
}

void readEncoder()
{
  encL.read(gEM);
  encR.read(gEM);
}

void readTouchBars()
{
  leftTBar.read(gEM, mixduino::Board::Event::TouchBarLeft);
  rightTBar.read(gEM, mixduino::Board::Event::TouchBarRight);
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

void btnPressedListener(int event, int param)
{
  //test
  sendMidiNoteOn(param<<8, param, 8);
}

void btnReleasedListener(int event, int param)
{
  //test
  sendMidiNoteOff(param<<8, param, 8);
}
void potMovedListener(int event, int param)
{
  // test
  sendMidiCC(param<<8, param, 9);
}

void touchEventListener(int event, int param)
{
  //
}

void initializePins ()
{
  for (uint8_t i = 0; i < ktOutputPins; i++)
  {
    pinMode(kOutputPins[i], OUTPUT);
  }

for (uint8_t i = 0; i < ktBtnInputPinsBndl; i++)
  {
    pinMode(kBtnInputPinsBndl[i], INPUT_PULLUP);
  }
}
