
#ifndef ARDUINO_SRMANAGER_H
#define ARDUINO_SRMANAGER_H
#include <Arduino.h>

class SRManager  
{
	private:
		int nRegisters;
		byte *ccNums;
		byte *regValues;
		int *cclastValues;
		void clearAll();
		void shiftOut(byte myDataOut);
		void shiftAll();
	public:

		SRManager(byte *cNums); // int[] with cc number assigments
		~SRManager();
		void begin();
		void handleControlChange(byte number, byte value);
};
#endif
