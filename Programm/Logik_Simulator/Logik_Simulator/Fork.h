#pragma once
#include "gatter.h"

ref class Fork :
public Gatter
{
public:
	Fork(void);

	Fork(int number, int time);
	
	void calculate(int time);
};
