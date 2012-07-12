#include "StdAfx.h"
#include "Not.h"

Not::Not(void):Gatter(1)
{
}

Not::Not(int number):Gatter(1){
}

void Not::calculate(){
  bool result = true;

 	  if(Gatter::input[0] == true)
		{
			result = false;
		}else
			{
				result = true;
			}
  Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
