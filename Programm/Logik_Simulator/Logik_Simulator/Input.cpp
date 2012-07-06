#include "StdAfx.h"
#include "Input.h"

Input::Input(void)
{
	Gatter::input = gcnew array<bool>(1);
	Gatter::output = gcnew array<bool>(1);
	this->setInputValue(true);
}

void Input::setInputValue(bool value)
{
	this->output[0] = value;
}

bool Input::getInput(){
	return this->output[0];
}

void Input::calculate(){
	Gatter::setResult(this->output[0]);
	Gatter::calculate();
}