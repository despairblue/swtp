#include "StdAfx.h"
#include "Nor.h"

Nor::Nor(void):Gatter()
{
}

Nor::Nor(int number):Gatter(number)
{
}

void Nor::calculate(){
  bool result = true;
  int i = 0;

  while((result == true) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == true)
		{
			result = false;
		}
	  i++;
  }
  Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
