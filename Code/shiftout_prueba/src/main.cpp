#include <Arduino.h>
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
//Pin connected to ST_CP of 74HC595
int latchPin = 8;
//Pin connected to SH_CP of 74HC595
int clockPin = 13;
////Pin connected to DS of 74HC595
int dataPin = 11;

const int totalRegisters = 2;
byte dataValues[] = {0x00, 0x01, 0x03, 0x07, 0x0F, 0x1F, 0x3F, 0x7F, 0xFF};
byte registerValues[totalRegisters] = {0};

int ccLastValues[totalRegisters] = {0}; 

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

void shiftOut(byte myDataOut);
void handleControlChange(byte channel, byte number, byte value);
void clearAll();
void shiftAll(byte* regValues);

void setup() {
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(latchPin, OUTPUT);

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  clearAll();
  MIDI.turnThruOff();
  MIDI.setHandleControlChange(handleControlChange);

}

void loop() {
  MIDI.read();
}

void clearAll() {
  digitalWrite(latchPin, 0);
  for(int i=0; i < totalRegisters; i++) {
    shiftOut(0x00);
  }
  digitalWrite(latchPin, 1);
}

void shiftAll(byte* regValues) {
  digitalWrite(latchPin, 0);
  for(int i=0; i < totalRegisters; i++) {
    shiftOut(regValues[i]);
  }
  digitalWrite(latchPin, 1);
}


// the heart of the program
void shiftOut(byte myDataOut) {

  // This shifts 8 bits out MSB first,

  //on the rising edge of the clock,

  //clock idles low

  //internal function setup

  int i=0;

  int pinState;

  //clear everything out just in case to

  //prepare shift register for bit shifting

  digitalWrite(dataPin, 0);

  digitalWrite(clockPin, 0);

  //for each bit in the byte myDataOut&#xFFFD;

  //NOTICE THAT WE ARE COUNTING DOWN in our for loop

  //This means that %00000001 or "1" will go through such

  //that it will be pin Q0 that lights.

  for (i=7; i>=0; i--)  {

    digitalWrite(clockPin, 0);

    //if the value passed to myDataOut and a bitmask result

    // true then... so if we are at i=6 and our value is

    // %11010100 it would the code compares it to %01000000

    // and proceeds to set pinState to 1.

    if ( myDataOut & (1<<i) ) {

      pinState= 1;

    }

    else {

      pinState= 0;

    }

    //Sets the pin to HIGH or LOW depending on pinState

    digitalWrite(dataPin, pinState);

    //register shifts bits on upstroke of clock pin

    digitalWrite(clockPin, 1);

    //zero the data pin after shift to prevent bleed through
    digitalWrite(dataPin, 0);

  }

  //stop shifting

  digitalWrite(clockPin, 0);
}

void handleControlChange(byte channel, byte number, byte value) {

  int value_ = value;
  
  if (number == 12) {
    if (value_ != ccLastValues[0]) {
      registerValues[0] = dataValues[value_];
      ccLastValues[0] = value;
    }
  }

  if (number == 13) {
    if (value_ != ccLastValues[1]) {
      registerValues[1] = dataValues[value_];
      ccLastValues[1] = value;
    }
  }
  shiftAll(registerValues);
}