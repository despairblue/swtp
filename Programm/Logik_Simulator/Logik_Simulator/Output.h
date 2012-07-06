#pragma once
#include "gatter.h"

public ref class Output :
public Gatter
{
public:
	Output(void);
	bool getOutput();
	void setInputValue(bool value);
private:
	bool value;
};
