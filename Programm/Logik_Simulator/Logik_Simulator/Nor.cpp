#include "StdAfx.h"
#include "Nor.h"

Nor::Nor(void)
{
}

Nor::Nor(int number, int time):Gatter(number, time){
	System::Console::WriteLine("Nor Gatter hinzugefügt");
}

void Nor::calculate(int time){
  bool result = true;
  int i = 0;

  while((result == true) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == true)
		{
			result = false;
		}
  }
  Gatter::setResult(result);
  Gatter::calculate(time);
  this->CalculationFinish();
}
