
#ifndef MDMODEFUNC_H
#define MDMODEFUNC_H
#include <Arduino.h>
#include <md_defs.h>
#include <md_func.h>

class MDModeFunc : public MDFunc
{
	public:
		MDModeFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos )
		:MDFunc(in, in_pos, out, out_pos)
		{
			
		}
		State read() {
			return this->input->read(this->inputPos);
		} 
};
#endif
