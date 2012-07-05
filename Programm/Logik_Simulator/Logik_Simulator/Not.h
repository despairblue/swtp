#pragma once
#include "Gatter.h"

ref class Not :
public Gatter
{
public:
	Not(void);
	Not(int number, int time);

	void calculate(int time);
};
