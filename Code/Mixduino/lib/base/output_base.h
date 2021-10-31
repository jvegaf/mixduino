
#pragma once
#ifndef OUTPUT_BASE_H
#define OUTPUT_BASE_H

#include <out_dto.h>

class OutputBase  
{
	public:
		virtual void clearAll() = 0;
		virtual void setTo(OutDTO dto) = 0;
};

#endif // OUTPUT_BASE_H
