#include "StdAfx.h"
#include "Signal.h"
#include "Output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Nand.h"
#include "Nor.h"
#include "Exor.h"

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
	this->inputGate->CalculationFinish +=gcnew Gatter::CalculationFinishEventHandler(this, &Signal::transmit);
	
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
	
	//System::Console::WriteLine("Index: {0}", index);

	for(int i = 0;i< index; i++)
	{	
		int position = safe_cast<int>(this->outputPosition[i]);
		
		//System::Console::WriteLine("gate: {0} {1}",outputGates[i]->GetType(), this->outputPosition[i]); 
	
		if(outputGates[i]->GetType() == Output::typeid)
		{
		safe_cast<Output^>(outputGates[i])->setInputValue(position, input);
		}
		
		if(outputGates[i]->GetType() == And::typeid)
		{
			safe_cast<And^>(outputGates[i])->setInputValue(position, input);
			safe_cast<And^>(outputGates[i])->calculate(0);
		}

		if(outputGates[i]->GetType() == Or::typeid)
		{
			safe_cast<Or^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Or^>(outputGates[i])->calculate(0);
		}

		if(outputGates[i]->GetType() == Not::typeid)
		{
			safe_cast<Not^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Not^>(outputGates[i])->calculate(0);
		}

		if(outputGates[i]->GetType() == Nand::typeid)
		{
			safe_cast<Nand^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Nand^>(outputGates[i])->calculate(0);
		}

		if(outputGates[i]->GetType() == Nor::typeid)
		{
			safe_cast<Nor^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Nor^>(outputGates[i])->calculate(0);
		}

		if(outputGates[i]->GetType() == Exor::typeid)
		{
			safe_cast<Exor^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Exor^>(outputGates[i])->calculate(0);
		}
	}	


}