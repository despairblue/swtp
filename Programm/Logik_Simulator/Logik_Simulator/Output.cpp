#include "StdAfx.h"
#include "Output.h"

Output::Output(void)
{
		Gatter::input = gcnew array<bool>(1);
	Gatter::output = gcnew array<bool>(1);

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
