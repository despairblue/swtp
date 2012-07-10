#include "StdAfx.h"
#include "Output.h"

Output::Output(void)
{
	this->input = gcnew array<bool>(1);
	this->output = true;

}

bool Output::getOutput()
{
	System::Console::WriteLine("Output: {0}", this->output);
	return this->output;
}

void Output::setInputValue(bool value)
{
	this->output = value;
	System::Console::WriteLine("Output: {0} gesetzt", this->output);
}
