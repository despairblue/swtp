#include "StdAfx.h"
#include "Input.h"

Input::Input(void)
{
	this->input = gcnew array<bool>(1);
	this->output = false;
}

void Input::setInputValue(bool value)
{
	this->output = value;
}

bool Input::getInput(){
	return this->output;
}

void Input::calculate(){
	__super::setResult(this->output);
	__super::calculate();
}
