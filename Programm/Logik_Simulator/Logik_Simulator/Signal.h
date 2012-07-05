#pragma once
#include "Gatter.h"

#using <mscorlib.dll>
using namespace System::Collections;

ref class Signal
{
public:
	Signal();

	bool getValue();
	void setValue(bool value);
	void setTime(int time);
	
	
	void setInputGate(Gatter^ gate, int position);
	void addOutputGate(Gatter^ gate, int position);
void transmit();
	

private: 
	
	int type;
	bool value;
	int time;
	ArrayList^ outputGates;
	ArrayList^ outputPosition;
	Gatter^ inputGate;
	int inputPosition;
	
};
