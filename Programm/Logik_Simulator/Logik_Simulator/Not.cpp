#include "StdAfx.h"
#include "Not.h"

Not::Not(void)
{
}

Not::Not(int number, int time):Gatter(1, time){
	System::Console::WriteLine("Not Gatter hinzugefügt");
}

void Not::calculate(int time){
  bool result = true;

 	  if(Gatter::input[0] == true)
		{
			result = false;
		}else
			{
				result = true;
			}
  Gatter::setResult(result);
  Gatter::calculate(time);
}
