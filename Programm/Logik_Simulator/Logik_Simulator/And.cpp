#include "StdAfx.h"
#include "And.h"

And::And(void):Gatter(){}

And::And(int number):Gatter(number){

		System::Console::WriteLine("And Gatter hinzugef�gt");
}

void And::calculate(){
  bool result = true;
  int i = 0;

  while((result == true) && (i < this->input->GetLength(0))){
	  if(this->input[i] == false)
		{
			result = false;
		}i++;
  }
  this->setResult(result);
  __super::calculate();
  this->CalculationFinish();
}
