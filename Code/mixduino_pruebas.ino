#define SHIFTPWM_USE_TIMER2
/////////////////////////////////////////////
// PWM bit shifter
// You can choose the latch pin yourself.
const int ShiftPWM_latchPin = 8;




// ** uncomment this part to NOT use the SPI port and change the pin numbers. This is 2.5x slower **
// #define SHIFTPWM_NOSPI
// const int ShiftPWM_dataPin = 11;
// const int ShiftPWM_clockPin = 12; 

// If your LED's turn on if the pin is low, set this to true, otherwise set it to false.
const bool ShiftPWM_invertOutputs = false;

// You can enable the option below to shift the PWM phase of each shift register by 8 compared to the previous.
// This will slightly increase the interrupt load, but will prevent all PWM signals from becoming high at the same time.
// This will be a bit easier on your power supply, because the current peaks are distributed.
const bool ShiftPWM_balanceLoad = false;

/////////////////////////////////////////////
// LIBRARIES
#include <ShiftPWM.h>  // Bit shifter library >> https://github.com/elcojacobs/ShiftPWM - include ShiftPWM.h after setting the pins!x
// If using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // MIDI library (by Forty Seven Effects) >> https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/4.3.1

MIDI_CREATE_DEFAULT_INSTANCE();

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

int ccLastValue = 0;

/////////////////////////////////////////////
// Leds
const byte ledNum = 8; // total number of leds used
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
unsigned int numRegisters = 1;

unsigned int VuL[] = {0, 1, 2, 3, 4, 5, 6, 7}; // VU Master
unsigned int VuR[] = {8, 9, 10, 11, 12, 13, 14, 15}; 

unsigned int red = 180;
unsigned int green = 255;
unsigned int blue = 10;
unsigned int yellow = 100;

// functions declaration
void handleControlChange(byte channel, byte number, byte value);

/////////////////////////////////////////////
void setup() {

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  MIDI.turnThruOff();
  
  /////////////////////////////////////////////
  // Midi in
  MIDI.setHandleControlChange(handleControlChange);
  
  // Sets the number of 8-bit registers that are used.
  ShiftPWM.SetAmountOfRegisters(numRegisters);

  ShiftPWM.Start(pwmFrequency, maxBrightness);

}

void loop() {
  MIDI.read();
}


////////////////////////////////////////////
// led feedback
void handleControlChange(byte channel, byte number, byte value) {


  int value_ = value;
  if (value_ != ccLastValue) { 
    if (number == 12) {
      setVURegister(value_, VuL);
    }
    ccLastValue = value_;
  }

}

void setVURegister (int val, unsigned int pinSet[]) {
  switch (val) {
        case 0:
          for (int i = 0; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          break;
        case 1:
          for (int i = 1; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          ShiftPWM.SetOne(pinSet[0], green);
          break;
        case 2:
          for (int i = 2; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 2; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 3:
          for (int i = 3; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 3; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 4:
          for (int i = 4; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 4; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 5:
          for (int i = 5; i < 7; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 5; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          break;
        case 6:
          for (int i = 6; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 5; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[5], yellow);
          break;
        case 7:
          for (int i = 7; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 6; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[6], yellow);
          break;
        case 8:
          for (int i = 7; i < 8; i++) {
            ShiftPWM.SetOne(pinSet[i], LOW);
          }
          for (int i = 0; i < 6; i++) {
            ShiftPWM.SetOne(pinSet[i], green);
          }
          ShiftPWM.SetOne(pinSet[6], yellow);
          ShiftPWM.SetOne(pinSet[7], red);
          break;
      }
}

/*
  buttons midi order
  40 44 - sync
  39 45 - cue
  38 46 - play
  37 47 - phones
  36 48 - filter
     VU order
  7 9
  6 10
  5 11
  4 12
  3 13
  2 14
  1 15
*/