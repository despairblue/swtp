#include "StdAfx.h"
#include "Nand.h"


Nand::Nand(void):Gatter(){}

Nand::Nand(int number):Gatter(number){
}

void Nand::calculate(){
  bool result =false;
  int i = 0;

  while((result == false) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == false)
		{
			result = true;
		}
	  i++;
  }
  Gatter::setResult(result);
  Gatter::calculate();
  this->CalculationFinish();
}
