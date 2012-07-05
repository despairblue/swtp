#include "StdAfx.h"
#include "Or.h"

Or::Or(void)
{
}
Or::Or(int number, int time){
	Gatter(number, time);
	System::Console::WriteLine("Or Gatter hinzugefügt");
}

void Or::calculate(int time){
  bool result = false;
  int i = 0;

  while((result == false) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == true)
		{
			result = true;
		}
  }
  Gatter::setResult(result);
  Gatter::calculate(time);
}
