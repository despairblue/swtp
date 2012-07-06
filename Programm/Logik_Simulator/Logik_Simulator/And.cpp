#include "StdAfx.h"
#include "And.h"

And::And(void):Gatter(){}

And::And(int number):Gatter(number){

		System::Console::WriteLine("And Gatter hinzugefügt");
}

void And::calculate(){
  bool result = true;
  int i = 0;

  while((result == true) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == false)
		{
			result = false;
		}i++;
  }
  Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
