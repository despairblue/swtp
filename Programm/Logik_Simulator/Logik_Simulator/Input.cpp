#include "StdAfx.h"
#include "Input.h"

Input::Input(void)
{
	Gatter::input = gcnew array<bool>(1);
	Gatter::output = gcnew array<bool>(1);
	this->setInputValue(0,true);
}

void Input::setInputValue(int number, bool value)
{
	this->output[0] = value;
	System::Console::WriteLine("Input: {0}", this->output[0]);
}

bool Input::getInput(){
	return this->output[0];
}