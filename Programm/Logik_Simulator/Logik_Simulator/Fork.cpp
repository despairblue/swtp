#include "StdAfx.h"
#include "Fork.h"

Fork::Fork(void):Gatter()
{
}

Fork::Fork(int number):Gatter(number){
	System::Console::WriteLine("Vergabelung hinzugefügt");
}

void Fork::calculate(){
	bool result = this->input[0];
	int i = 0;

	while(i < this->getLength()){
		this->output[i] = result;
		Gatter::setResult(i, result);
		Gatter::calculate();
		 i++;
		 this->CalculationFinish();
	 }
} 

