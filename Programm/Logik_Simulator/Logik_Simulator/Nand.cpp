#include "StdAfx.h"
#include "Nand.h"


Nand::Nand(void){}

Nand::Nand(int number, int time):Gatter(number, time){
	System::Console::WriteLine("Nand Gatter hinzugefügt");
}

void Nand::calculate(int time){
  bool result =false;
  int i = 0;

  while((result == false) && (i < Gatter::input->GetLength(0))){
	  if(Gatter::input[i] == false)
		{
			result = true;
		}
  }
  Gatter::setResult(result);
  Gatter::calculate(time);
  this->CalculationFinish();
}
