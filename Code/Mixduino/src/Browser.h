#pragma once
#ifndef MD_BROWSER_H
#define MD_BROWSER_H
#include "BREncoder.h"
#include "ButtonMidi.h"

class Browser  
{

	public:

		Browser(BREncoder *encoders, ButtonMidi *btns)
		: m_encoders{encoders}, m_btns{btns}
		{
		}
	
	private:
		BREncoder* m_encoders;
		ButtonMidi* m_btns;

};
#endif
