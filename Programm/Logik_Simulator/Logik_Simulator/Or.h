#pragma once
#include "Gatter.h"

public ref class Or :
public Gatter
{
public:
	Or(void);
	Or(int number, int time);

	void calculate(int time);
};
