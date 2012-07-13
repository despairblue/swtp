#include "StdAfx.h"
#include "Gatter.h"
#include "Signal.h"

// NOTE: Gatter
/**
    Constructs a new Gate.
*/
Gatter::Gatter()
{
	this->number = 2;

	this->input = gcnew array<bool>(number);
	this->output = false;
}

// NOTE: Gatter
/**
    Constructs a new Gate.
	@param number Number of Inputs
*/
Gatter::Gatter(int number)
{
	this->number = number;

	this->input = gcnew array<bool>(number);
	this->output = false;
}

/**
    Set the InputValue
    @param number The Position of the Input
	@param value The Value of the Input
*/
void Gatter::setInputValue(int number, bool value)
{
	this->input[number] = value;
	System::Console::WriteLine("{0} {1}: {2}",this->ToString(), number, value);
}

/**
    Set the InputValue
   	@param value The Value of the Input
*/
void Gatter::setInputValue(bool value)
{
	this->input[0] = value;
	System::Console::WriteLine("{0} {1}: {2}",this->ToString(), number, value);
}

/**
    Add a new Input
    @param number The Position of the Input
*/
void Gatter::addInput(int number)
{
	this->input[number] = true;
}

/**
    Set the Output Value
   	@param result The Value of the Output
*/
void Gatter::setResult(bool result){
	this->output = result;
}

/**
    Set the Output Value
    @param number The Position of the Output
	@param value The Value of the Output
*/
void Gatter::setResult(int number, bool result){
	this->output= result;
}

/**
    Calculates the Gate
*/
void Gatter::calculate(){
/*	if(this->result != this->output)
		{
			this->setResult(this->output);
			this->CalculationFinish();

		}*/
}


/**
    Returns the Output Value
    @param number The Position of the Output
*/
bool Gatter::getResult(int number)
{
	return this->output;
}

/**
    Returns the Output Value
*/
bool Gatter::getResult()
{
	return this->output;
}

int Gatter::getLength()
{
	return this->length;
}
