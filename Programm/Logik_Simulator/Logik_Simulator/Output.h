#pragma once
#include "gatter.h"

ref class Output :
public Gatter
{
public:
	Output(void);
	bool getOutput();
	void setInputValue(int number, bool value);
private:
	bool value;
};
