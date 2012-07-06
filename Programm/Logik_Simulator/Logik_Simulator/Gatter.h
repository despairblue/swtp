#pragma once
//#include "Signal.h"

ref class Gatter
{
public:
	Gatter(void);
	Gatter(int inputNumber, int time);

	void calculate(int time);
	
	void setInputValue(int number, bool value);
	
	int getLength();
	int getTime();
	bool getResult(int number);
	bool getResult();
	array<bool>^ output;

	void setResult(bool result);
	void setResult(int number, bool result);
	void addInput(int number);
	void finishCalculate();

protected:

	int time;
	array<bool>^ input;

	
	void calculateFlipFlop(bool result, int time);

private:
	bool result, last_result;
	int length;
	int number;
	System::String^ name;
	void setTime(int time);
	
};
