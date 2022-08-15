#ifndef __COMPONENTS_DEF_H__
#define __COMPONENTS_DEF_H__

#pragma once

#include <Arduino.h>


enum class Mixer : uint8_t {
  DeckSelector = 11,
  Shift,
  CueA,
  CueB,
  CueC
};

enum class Browser : uint8_t {
  PreviewBtn = 16,
  BackBtn,
  LeftBtn,
  RightBtn
};

enum class FxUnit1 : uint8_t {
  Button1 = 21,
  Button2,
  Button3,
};

enum class FxUnit2 : uint8_t {
  Button1 = 24,
  Button2,
  Button3,
};

enum class DeckLeft : uint8_t {
  ModeSelector = 27,
  Play,
  Cue,
  Loop,
  Sync
 };

 enum class DeckRight : uint8_t {
  ModeSelector = 32,
  Play,
  Cue,
  Loop,
  Sync
 };


enum class PadLeft : uint8_t {
  P_1 = 41,
  P_2,
  P_3,
  P_4,
  P_5,
  P_6,
  P_7,
  P_8
 };

enum class PadRight : uint8_t {
  P_1 = 49,
  P_2,
  P_3,
  P_4,
  P_5,
  P_6,
  P_7,
  P_8
 };

 

 

#endif // __COMPONENTS_DEF_H__
