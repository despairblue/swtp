#pragma once
#include "Gatter.h"

#using <mscorlib.dll>
using namespace System::Collections;

public ref class Signal
{
public:
	Signal();

	bool getValue();
	
	void setInputGate(Gatter^ gate, int position);
	void addOutputGate(Gatter^ gate, int position);
	void transmit();
	void destruct();

private: 
	
	int type;
	bool value;
	ArrayList^ outputGates;
	ArrayList^ outputPosition;
	Gatter^ inputGate;
	int inputPosition;
	
};
