
#ifndef ARDUINO_SRMANAGER_H
#define ARDUINO_SRMANAGER_H
#include <Arduino.h>

class SRManager  
{
	private:
		int nRegisters;
		uint8_t *ccNums;
		uint8_t *regValues;
		int *cclastValues;
		void clearAll();
		void shiftOut(uint8_t myDataOut);
		void shiftAll();
	public:

		SRManager(uint8_t *cNums); // int[] with cc number assigments
		~SRManager();
		void begin();
		void handleChange(uint8_t number, uint8_t value);
};
#endif
