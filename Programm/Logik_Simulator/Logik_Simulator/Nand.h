#pragma once
#include "gatter.h"

ref class Nand :
public Gatter
{
public:
	Nand(int number, int time);
	Nand(void);

	void calculate(int time);
};