#pragma once
#include "Gatter.h"

public ref class Exor :
public Gatter
{
public:
	Exor(void);
	Exor(int number, int time);

	void calculate(int time);
};
