#pragma once
//#include "Signal.h"

public ref class Gatter
{
public:
	delegate void CalculationFinishEventHandler();
	event CalculationFinishEventHandler^ CalculationFinish;

	Gatter(void);
	Gatter(int inputNumber);

	void calculate();
	
	void setInputValue(bool value);
	void setInputValue(int number,bool value);
	
	int getLength();
	bool getResult(int number);
	bool getResult();
	array<bool>^ output;

	void setResult(bool result);
	void setResult(int number, bool result);
	void addInput(int number);

protected:

	array<bool>^ input;
	
private:
	bool result, last_result;
	int length;
	int number;
	System::String^ name;
	
};
