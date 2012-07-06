#pragma once
#include "Gatter.h"

public ref class And :
public Gatter
{
public:
    And(int number, int time);
	And(void);

	void calculate(int time);
};
