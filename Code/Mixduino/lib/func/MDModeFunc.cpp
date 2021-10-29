#include "MDModeFunc.h"  

MDModeFunc::MDModeFunc(InputBase* in, uint8_t in_pos, OutputBase* out, uint8_t out_pos )
	: MDFunc(in, in_pos, out, out_pos)
{
	
}

MDState MDModeFunc::read() {
	return this->_input->read(this->_inputPos);
}
