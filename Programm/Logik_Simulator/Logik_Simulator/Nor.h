#pragma once
#include "gatter.h"

ref class Nor :
public Gatter
{
public:
	Nor(void);
	Nor(int number, int time);

	void calculate(int time);
};
