#include "StdAfx.h"
#include "And.h"

And::And(void){}

And::And(int number, int time):Gatter(number, time){

		System::Console::WriteLine("And Gatter hinzugefügt");
}

void And::calculate(int time){
  bool result = true;
  int i = 0;

  while((result == true) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == false)
		{
			result = false;
		}i++;
  }
  Gatter::setResult(result);
  Gatter::calculate(time);
  this->CalculationFinish();
}
