#include "StdAfx.h"
#include "Fork.h"

Fork::Fork(void):Gatter()
{
}

Fork::Fork(int number, int time):Gatter(number, time){
	System::Console::WriteLine("Vergabelung hinzugefügt");
}

void Fork::calculate(int time){
	bool result = this->input[0];
	int i = 0;

	while(i < this->getLength()){
		this->output[i] = result;
		Gatter::setResult(i, result);
		Gatter::calculate(1);
		 i++;
		 this->CalculationFinish();
	 }
} 

