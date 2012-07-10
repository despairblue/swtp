#pragma once
#include "gatter.h"

public ref class Output :
public Gatter
{
public:
	Output(void);
	bool getOutput();
	virtual void setInputValue(bool value) override;
private:
	bool value;
};
