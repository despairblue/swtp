#pragma once
#include "Signal.h"

ref class LogikElement abstract
{
public:
	LogikElement(void);
	virtual void setInput(int number, Signal^ signal) abstract;

};
