#include "StdAfx.h"
#include "Output.h"

Output::Output(void)
{
}

bool Output::getOutput()
{
	System::Console::WriteLine("Output: {0}", this->output[0]);
	return this->output[0];
}

void Output::setInputValue(int number, bool value)
{
	this->output[0] = value;
	System::Console::WriteLine("Output: {0} gesetzt", this->output[0]);
}
