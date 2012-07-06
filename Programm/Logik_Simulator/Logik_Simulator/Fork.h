#pragma once
#include "gatter.h"

ref class Fork :
public Gatter
{
public:
	Fork(void);

	Fork(int number);
	
	void calculate();
};
