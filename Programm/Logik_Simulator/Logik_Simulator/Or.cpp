#include "StdAfx.h"
#include "Or.h"

Or::Or(void):Gatter()
{
}
Or::Or(int number):Gatter(number){
	System::Console::WriteLine("Or Gatter hinzugefügt");
}

void Or::calculate(){
  bool result = false;
  int i = 0;

  while((result == false) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == true)
		{
			result = true;
		}i++;
  }
  Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
