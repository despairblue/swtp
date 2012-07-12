#include "StdAfx.h"
#include "Exor.h"

Exor::Exor(void):Gatter()
{
}

Exor::Exor(int number):Gatter(number){
}

void Exor::calculate(){
  bool result = false;
  int i = 0;
  int number = 0;

  while(i < Gatter::input->GetLength(0))
  {
	  if(Gatter::input[i] == true)
		{
			number++;
		}
			i++;
  }
	  if((number%2) == 1){
		  result = true;
	  }

   Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
