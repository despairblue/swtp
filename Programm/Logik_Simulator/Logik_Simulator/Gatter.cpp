#include "StdAfx.h"
#include "Gatter.h"
#include "Signal.h"

Gatter::Gatter()
{
	this->number = 2;

	this->input = gcnew array<bool>(number);
	this->output = true;
}

Gatter::Gatter(int number)
{
	this->number = number;

	this->input = gcnew array<bool>(number);
	this->output = true;
}

void Gatter::setInputValue(int number, bool value)
{
	this->input[number] = value;
	System::Console::WriteLine("{0} {1}: {2}",this->ToString(), number, value);
}

void Gatter::setInputValue(bool value)
{
	this->input[0] = value;
	System::Console::WriteLine("{0} {1}: {2}",this->ToString(), number, value);
}
void Gatter::addInput(int number)
{
	this->input[number] = true;
}

void Gatter::setResult(bool result){
	this->output = result;
}

void Gatter::setResult(int number, bool result){
	this->output= result;
}

void Gatter::calculate(){
/*	if(this->result != this->output)
		{
			this->setResult(this->output);
			this->CalculationFinish();

		}*/
}

bool Gatter::getResult(int number)
{
	return this->output;
}

bool Gatter::getResult()
{
	return this->output;
}

int Gatter::getLength()
{
	return this->length;
}
