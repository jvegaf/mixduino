
#ifndef ARDUINO_HWBTN_H
#define ARDUINO_HWBTN_H
#include <Arduino.h>
#include "ButtonBase.h"
#include "BtnState.h"
#include "pin_map.h"

class HWBtn : public ButtonBase
{
private:
	uint8_t _arduinoPin;
public:
	HWBtn(uint8_t ardPin); 
	void begin();
	BtnState read();
};
#endif
