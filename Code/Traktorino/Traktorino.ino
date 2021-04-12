#define SHIFTPWM_USE_TIMER2
#define PADL_SIGPIN  48
#define PADR_SIGPIN  46
#define NUMPIXELS 8

const int ShiftPWM_latchPin = 8;
const bool ShiftPWM_invertOutputs = false;
const bool ShiftPWM_balanceLoad = false;


/////////////////////////////////////////////
// LIBRARIES
#include <ShiftPWM.h>  // Bit shifter library >> https://github.com/elcojacobs/ShiftPWM - include ShiftPWM.h after setting the pins!
// If using with ATmega328 - Uno, Mega, Nano...
#include <MIDI.h> // MIDI library (by Forty Seven Effects) >> https://github.com/FortySevenEffects/arduino_midi_library/releases/tag/4.3.1
MIDI_CREATE_DEFAULT_INSTANCE();
#include <Multiplexer4067.h> // Multiplexer CD4067 library >> https://github.com/sumotoy/Multiplexer4067
#include <Thread.h> // Threads library (by Ivan seidel) >> https://github.com/ivanseidel/ArduinoThread
#include <ThreadController.h> 
#include <Encoder.h> // Encoder library >> https://github.com/PaulStoffregen/Encoder
#include <Adafruit_NeoPixel.h>  // https://github.com/adafruit/Adafruit_NeoPixel

Adafruit_NeoPixel npadL(NUMPIXELS, PADL_SIGPIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel npadR(NUMPIXELS, PADR_SIGPIN, NEO_GRB + NEO_KHZ800);

uint32_t blueCol = npadL.Color(102, 204, 255);
uint32_t greenCol = npadL.Color(0, 255, 0);
uint32_t yellowCol = npadL.Color(255, 255, 0);
uint32_t orangeCol = npadL.Color(255, 153, 51);

/////////////////////////////////////////////
// buttons
const byte NButtons = 43; // *coloque aqui o numero de entradas digitais utilizadas
const byte buttonPin[NButtons] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41,42, 43, 44, 45}; // *neste array coloque na ordem desejada os pinos das portas digitais utilizadas
int buttonCState[NButtons] = {0}; // estado atual da porta digital
int buttonPState[NButtons] = {0}; // estado previo da porta digital

/////////////////////////////////////////////
// debounce
unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
unsigned long debounceDelay = 5;    // the debounce time; increase if the output flickers

/////////////////////////////////////////////
// potentiometers
const byte NPots = 12; // *coloque aqui o numero de entradas analogicas utilizadas
const byte muxPots = 18;
const byte totalPots = NPots + muxPots;
const byte NPotPin[NPots] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // 
const byte muxPotPin[muxPots] = {0, 1, 2, 3, 4, 5, 6, 15, 14, 13, 12, 11, 10, 8}; // *neste array coloque na ordem desejada os pinos das portas analogicas, ou mux channel, utilizadas
int potCState[totalPots] = {0}; // estado atual da porta analogica
int potPState[totalPots] = {0}; // estado previo da porta analogica
int potVar = 0; // variacao entre o valor do estado previo e o atual da porta analogica
int lastCcValue[totalPots] = {0};

/////////////////////////////////////////////
// pot reading
int TIMEOUT = 50; //quantidade de tempo em que o potenciometro sera lido apos ultrapassar o varThreshold
byte varThreshold = 8; //threshold para a variacao no sinal do potenciometro
boolean potMoving = true; // se o potenciometro esta se movendo
unsigned long pTime[NPots] = {0}; // tempo armazenado anteriormente
unsigned long timer[NPots] = {0}; // armazena o tempo que passou desde que o timer foi zerado

/////////////////////////////////////////////
// encoder
Encoder myEnc(3, 2);
long oldPosition  = -10;

/////////////////////////////////////////////
// midi
byte midiCh = 1; // *Canal midi a ser utilizado
byte note = 36; // *Nota mais grave que sera utilizada
byte cc = 1; // *CC mais baixo que sera utilizado

int ccVuMRLastValue = 0;
int ccVuMLLastValue = 0;
int ccVuL3LastValue = 0;
int ccVuL2LastValue = 0;
int ccVuL1LastValue = 0;

/////////////////////////////////////////////
// Leds
const byte ledNum = 47; // total number of leds used
unsigned char maxBrightness = 255;
unsigned char pwmFrequency = 75;
unsigned int numRegisters = 6;

unsigned int VuMR[8] = {0, 1, 2, 3, 4, 5, 6, 7}; // VU master right pins
unsigned int VuML[8] = {8, 9, 10, 11, 12, 13, 14, 15}; // VU master left pins
unsigned int VuL3[8] = {16, 17, 18, 19, 20, 21, 22, 23}; // VU line 1 pins
unsigned int VuL2[8] = {24, 25, 26, 27, 28, 29, 30, 31}; // VU line 2 pins
unsigned int VuL1[8] = {32, 33, 34, 35, 36, 37, 38, 39}; // VU line 3 pins
unsigned int buttonsLed[7] = {41, 42, 43, 44, 45, 46, 47};

unsigned int red = 180;
unsigned int green = 255;
unsigned int blue = 10;
unsigned int yellow = 100;

/////////////////////////////////////////////
// Multiplexer
Multiplexer4067 mplexPots = Multiplexer4067(47, 49, 40, 53, A0);

/////////////////////////////////////////////
// threads - programa cada atividade do Arduino para acontecer em um determinado tempo
ThreadController cpu; //thread master, onde as outras vao ser adicionadas
Thread threadReadPots; // thread para controlar os pots
Thread threadReadButtons; // thread para controlar os botoes

/////////////////////////////////////////////
void setup() {

  Serial.begin(31250); // 115200 for hairless - 31250 for MOCO lufa
  
  MIDI.turnThruOff();
  
  /////////////////////////////////////////////
  // Midi in
  MIDI.setHandleControlChange(handleControlChange);
  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  /////////////////////////////////////////////
  // Multiplexers
  mplexPots.begin(); // inicializa o multiplexer
  pinMode(A0, INPUT_PULLUP); // pots need input pull up

  /////////////////////////////////////////////
  // buttons on Arduino Digital pins
  for (int i = 0; i < NButtons; i++) { // buttons on Digital pin
    pinMode(buttonPin[i], INPUT_PULLUP);
  }

  // Sets the number of 8-bit registers that are used.
  ShiftPWM.SetAmountOfRegisters(numRegisters);
  ShiftPWM.Start(pwmFrequency, maxBrightness);

  /////////////////////////////////////////////
  // Init neopixels
  npadL.begin();
  npadL.show();
  npadR.begin();
  npadR.show();

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

void loop() {
  cpu.run();
  MIDI.read();
  readEncoder();
}

/////////////////////////////////////////////
// read buttons

void readButtons() {

  for (int i = 0; i < NButtons; i++) { //read buttons on Arduino
    buttonCState[i] = digitalRead(buttonPin[i]); // stores in the rest of buttonCState
  }

  for (int i = 0; i < NButtons; i++) {

    if ((millis() - lastDebounceTime) > debounceDelay) {

      if (buttonCState[i] != buttonPState[i]) {
        lastDebounceTime = millis();

        if (buttonCState[i] == LOW) {
          MIDI.sendNoteOn(note + i, 127, midiCh); // envia NoteOn(nota, velocity, canal midi)
          buttonPState[i] = buttonCState[i];
        }
        else {
          MIDI.sendNoteOn(note + i, 0, midiCh);
          buttonPState[i] = buttonCState[i];
        }
      }
    }

  }

}

////////////////////////////////////////////
//read potentiometers

void readPots() {

  for (int i = 0; i < muxPots; i++) { // le todas entradas analogicas utilizadas, menos a dedicada a troca do canal midi
    potCState[i] = mplexPots.readChannel(muxPotPin[i]);
  }

  for (int i = 0; i < NPots; i++) { // le todas entradas analogicas utilizadas, menos a dedicada a troca do canal midi
    potCState[i + muxPots] = analogRead(NPotPin[i]);
  }

  

  for (int i = 0; i < totalPots; i++) {

    potVar = abs(potCState[i] - potPState[i]); // calcula a variacao da porta analogica

    if (potVar >= varThreshold) {  //sets a threshold for the variance in the pot state, if it varies more than x it sends the cc message
      pTime[i] = millis(); // armazena o tempo previo
    }
    timer[i] = millis() - pTime[i]; // reseta o timer
    if (timer[i] < TIMEOUT) { // se o timer for menor que o tempo maximo permitido significa que o potenciometro ainda esta se movendo
      potMoving = true;
    }
    else {
      potMoving = false;
    }

    if (potMoving == true) { // se o potenciometro ainda esta se movendo, mande o control change
      int ccValue = map(potCState[i], 0, 1023, 0, 127);
      if (lastCcValue[i] != ccValue) {
        MIDI.sendControlChange(cc + i, map(potCState[i], 0, 1023, 0, 127), 11); // envia Control Change (numero do CC, valor do CC, canal midi)
        potPState[i] = potCState[i]; // armazena a leitura atual do potenciometro para comparar com a proxima
        lastCcValue[i] = ccValue;
      }
    }
  }

}

////////////////////////////////////////////
//// read encoder
void readEncoder () {

  int newPosition = myEnc.read();
  int encoderVal = map(newPosition, -1024, 1024, -256, 256);
  int encoderValue;

  if (encoderVal != oldPosition) {

    if ((encoderVal - oldPosition) > 0) {
      encoderValue = 127;
    }
    else {
      encoderValue = 1;
    }

    MIDI.sendControlChange(14, encoderValue, 1);

    oldPosition = encoderVal;
  }

}

////////////////////////////////////////////
// led feedback
void handleControlChange(byte channel, byte number, byte value) {

  int value_ = value;
  if (number == 12) {
    if (value_ != ccVuMRLastValue) {
      setVURegister(value_, VuMR);
      ccVuMRLastValue = value;
    }
  }
  if (number == 13) {
    if (value_ != ccVuMLLastValue) {
      setVURegister(value_, VuML);
      ccVuMLLastValue = value;
    }
  }
  if (number == 14) {
    if (value_ != ccVuL3LastValue) {
      setVURegister(value_, VuL3);
      ccVuL3LastValue = value;
    }
  }
  if (number == 15) {
    if (value_ != ccVuL2LastValue) {
      setVURegister(value_, VuL2);
      ccVuL2LastValue = value;
    }
  }
  if (number == 16) {
    if (value_ != ccVuL1LastValue) {
      setVURegister(value_, VuL1);
      ccVuL1LastValue = value;
    }
  }
}

void handleNoteOn(byte channel, byte number, byte value)
{
  switch (number) {
    case 36: //cue left
      ShiftPWM.SetOne(buttonsLed[0], blue);
      break;
    case 37: //play left
      ShiftPWM.SetOne(buttonsLed[1], blue);
      break;
    case 38: //precue L1
      ShiftPWM.SetOne(buttonsLed[2], blue);
      break;
    case 39: //precue L2
      ShiftPWM.SetOne(buttonsLed[3], blue);
      break;
    case 40: //precue L3
      ShiftPWM.SetOne(buttonsLed[4], blue);
      break;
    case 44: //play right
      ShiftPWM.SetOne(buttonsLed[5], blue);
      break;
    case 45: //cue right
      ShiftPWM.SetOne(buttonsLed[6], blue);
      break;
  }
}

void handleNoteOff(byte channel, byte number, byte value) {
  switch (number) {
      case 36: //cue left
        ShiftPWM.SetOne(buttonsLed[0], LOW);
        break;
      case 37: //play left
        ShiftPWM.SetOne(buttonsLed[1], LOW);
        break;
      case 38: //precue L1
        ShiftPWM.SetOne(buttonsLed[2], LOW);
        break;
      case 39: //precue L2
        ShiftPWM.SetOne(buttonsLed[3], LOW);
        break;
      case 40: //precue L3
        ShiftPWM.SetOne(buttonsLed[4], LOW);
        break;
      case 44: //play right
        ShiftPWM.SetOne(buttonsLed[5], LOW);
        break;
      case 45: //cue right
        ShiftPWM.SetOne(buttonsLed[6], LOW);
        break;
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
