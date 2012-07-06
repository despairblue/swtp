#include "StdAfx.h"
#include "Gatter.h"
#include "Signal.h"

Gatter::Gatter(){}

Gatter::Gatter(int inputNumber, int time)
{
	Gatter::number = inputNumber;
	Gatter::time = time;

	Gatter::input = gcnew array<bool>(inputNumber);
	Gatter::output = gcnew array<bool>(2);
}

void Gatter::setInputValue(int number, bool value)
{
	this->input[number] = value;
	System::Console::WriteLine("Gatter: {0}", value);
}

void Gatter::addInput(int number)
{
	this->input[number] = true;
}

void Gatter::finishCalculate(){}

//void Gatter::setInput(int number, Signal^ signal)
//{
//	Gatter::input[number] = signal;
//	
//}
//
//void Gatter::setOutput(int number, Signal^ signal){
//
//}

void Gatter::setResult(bool result){ 
	this->output[0] = result;
}

void Gatter::setResult(int number, bool result){ 
	this->output[number] = result;
}

void Gatter::calculate(int time){
	if((Gatter::result != Gatter::output[0]) && (time == -1))
		{
			this->setTime(-1);
			this->setResult(result);
			this->finishCalculate();
			//Gatter::output[0]->setTime(-1);
	//		Gatter::output[0]->setValue(result);
		}
}

void Gatter::calculateFlipFlop(bool result, int time){

}

bool Gatter::getResult(int number)
{
	return this->output[number];
}

bool Gatter::getResult()
{
	return this->output[0];
}

void Gatter::setTime(int time)
{
	this->time = time;
}

int Gatter::getTime()
{
	return this->time;
}

int Gatter::getLength()
{
	return this->length;
}
