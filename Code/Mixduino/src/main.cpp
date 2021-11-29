#include <Arduino.h>
#include <MIDI.h>
#include <Thread.h>
#include <ThreadController.h>
#include <EventManager.h>
#include "midi_map.h"
#include "MDCore.hpp"
#include "BREncoder.hpp"
#include "Muxer.h"
#include "BtnKit.hpp"
#include "PotKit.hpp"
#include "TouchKit.hpp"
// Rev5 version
MIDI_CREATE_DEFAULT_INSTANCE();

EventManager gEM;

browser::BREncoder encL(L_BROWSER_A, L_BROWSER_B);
browser::BREncoder encR(R_BROWSER_A, R_BROWSER_B);
input::PotKit pots;
Muxer leftBtns(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A3);
Muxer rightBtns(MPLEX_S0, MPLEX_S1, MPLEX_S2, MPLEX_S3, MPLEX_A2);
input::BtnKit btns(aSwSet, nASw);

mdcore::Core mdCore;
input::TouchKit touchBars;

ThreadController cpu;     //thread master, onde as outras vao ser adicionadas
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
void sendMidiNoteOn(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiNoteOff(uint8_t number, uint8_t value, uint8_t channel);
void sendMidiCC(uint8_t number, uint8_t value, uint8_t channel);

void setup()
{
  // Serial.begin(31250);
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(MIDI_CHANNEL_OMNI);
  MIDI.turnThruOff();

  gEM.addListener(EventManager::kEventKeyPress, btnPressedListener);
  gEM.addListener(EventManager::kEventKeyRelease, btnReleasedListener);
  gEM.addListener(EventManager::kEventAnalog0, potMovedListener);

  pots.begin();
  leftBtns.begin(SwMuxLeftSet, nSwMuxLeft, LEFT_BTNS_CH);
  rightBtns.begin(SWMuxRightSet, nSwMuxRight, RIGHT_BTNS_CH);
  btns.begin();
  mdCore.begin();
  touchBars.begin();
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
  leftBtns.read(sendMidiNoteOn, sendMidiNoteOff);
  rightBtns.read(sendMidiNoteOn, sendMidiNoteOff);
  btns.read(gEM);
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
  //
}

void btnReleasedListener(int event, int param)
{
  //
}
void potMovedListener(int event, int param)
{
  //
}
