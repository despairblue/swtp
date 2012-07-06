#pragma once
#include "gatter.h"

public ref class Input :
public Gatter
{
public:
	Input(void);
	bool getInput();
	void setInputValue(bool value);
	void calculate();
};
