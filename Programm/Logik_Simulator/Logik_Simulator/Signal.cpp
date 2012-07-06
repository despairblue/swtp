#include "StdAfx.h"
#include "Signal.h"
#include "Output.h"

Signal::Signal()
{
	Signal::outputGates = gcnew ArrayList();
	Signal::outputPosition = gcnew ArrayList();
}

bool Signal::getValue(){
	return Signal::value;
}

void Signal::setValue(bool value){
	if(Signal::time == -1)
		{
			Signal::value = value;
		}

	if(Signal::value != value)
		{
			Signal::value = value;		 
		}
	Signal::value = value;

	System::Console::WriteLine("{0}", value);
}


void Signal::setInputGate(Gatter^ gate, int position)
{
	this->inputGate = gate;
	this->inputPosition = position;
}

void Signal::addOutputGate(Gatter^ gate, int position)
{
	this->outputGates->Add(gate);
	this->outputPosition->Add(position);
}


void Signal::setTime(int time)
{
	Signal::time = time;
}

void Signal::transmit()
{
	bool input = this->inputGate->getResult(this->inputPosition);
	int index = this->outputGates->Count;
	System::Console::WriteLine("Index: {0}", index);

	for(int i = 0;i< index; i++)
	{	
		int position = safe_cast<int>(this->outputPosition[i]);
		if(outputGates[i]->GetType() == Output::typeid)
		{
		safe_cast<Output^>(outputGates[i])->setInputValue(position, input);
		}else
		{
			safe_cast<Gatter^>(outputGates[i])->setInputValue(position, input);
		}
	}	


}