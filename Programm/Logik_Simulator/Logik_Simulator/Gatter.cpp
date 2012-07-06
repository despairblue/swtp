#include "StdAfx.h"
#include "Gatter.h"
#include "Signal.h"

Gatter::Gatter()
{
	Gatter::number = 2;

	Gatter::input = gcnew array<bool>(number);
	Gatter::output = gcnew array<bool>(2);
}

Gatter::Gatter(int number)
{
	Gatter::number = number;

	Gatter::input = gcnew array<bool>(number);
	Gatter::output = gcnew array<bool>(2);
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
	this->output[0] = result;
}

void Gatter::setResult(int number, bool result){ 
	this->output[number] = result;
}

void Gatter::calculate(){
	if(Gatter::result != Gatter::output[0])
		{
			this->setResult(result);
			this->CalculationFinish();
	
		}
}

bool Gatter::getResult(int number)
{
	return this->output[number];
}

bool Gatter::getResult()
{
	return this->output[0];
}

int Gatter::getLength()
{
	return this->length;
}
