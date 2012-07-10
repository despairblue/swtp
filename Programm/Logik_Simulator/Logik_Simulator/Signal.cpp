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
	return this->inputGate->getResult(0);
}

void Signal::destruct()
{
	this->inputGate = nullptr;
	//this->outputGates = 
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


void Signal::transmit()
{
	bool input = this->inputGate->getResult(this->inputPosition);
	int index = this->outputGates->Count;
	
	//System::Console::WriteLine("Index: {0}", index);

	for(int i = 0;i< index; i++)
	{	
		int position = safe_cast<int>(this->outputPosition[i]);
		
		if(outputGates[i]->GetType() == Output::typeid)
		{
		safe_cast<Output^>(outputGates[i])->setInputValue(input);
		}
		
		if(outputGates[i]->GetType() == And::typeid)
		{
			safe_cast<And^>(outputGates[i])->setInputValue(position, input);
			safe_cast<And^>(outputGates[i])->calculate();
		}

		if(outputGates[i]->GetType() == Or::typeid)
		{
			safe_cast<Or^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Or^>(outputGates[i])->calculate();
		}

		if(outputGates[i]->GetType() == Not::typeid)
		{
			safe_cast<Not^>(outputGates[i])->setInputValue(input);
			safe_cast<Not^>(outputGates[i])->calculate();
		}

		if(outputGates[i]->GetType() == Nand::typeid)
		{
			safe_cast<Nand^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Nand^>(outputGates[i])->calculate();
		}

		if(outputGates[i]->GetType() == Nor::typeid)
		{
			safe_cast<Nor^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Nor^>(outputGates[i])->calculate();
		}

		if(outputGates[i]->GetType() == Exor::typeid)
		{
			safe_cast<Exor^>(outputGates[i])->setInputValue(position, input);
			safe_cast<Exor^>(outputGates[i])->calculate();
		}
		System::Console::WriteLine("{0} {1}",this->ToString(), this->getValue());
	}	


}