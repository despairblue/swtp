#pragma once
#include "gatter.h"

ref class Input :
public Gatter
{
public:
	Input(void);
	bool getInput();
	void setInputValue(int number, bool value);

};
