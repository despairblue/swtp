#pragma once
#include "gatter.h"

public ref class Input :
public Gatter
{
public:
	Input(void);
public:
	bool getInput();
	virtual void setInputValue(bool value) override;
	virtual void calculate() override;
};
