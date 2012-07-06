// Logik_Simulator.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "MainForm.h"
#include "Gatter.h"
#include "And.h"
#include "Signal.h"
#include "Input.h"
#include "Output.h"


using namespace Logik_Simulator;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	And^ and = gcnew And(2,1);
	Input^ input1 = gcnew Input();
	Input^ input2 = gcnew Input();

	Output^ output = gcnew Output();

	Signal^ s1 = gcnew Signal();
	Signal^ s2 = gcnew Signal();
	Signal^ s3 = gcnew Signal();

	input1->setInputValue(0,true);
	input2->setInputValue(0,false);
	
	s1->setInputGate(input1, 0);
	s1->addOutputGate(and,0);
	
	s2->setInputGate(input2, 0);
	s2->addOutputGate(and, 1);

	s3->setInputGate(and,0);
	s3->addOutputGate(output,0);

	input1->setInputValue(0,true);
	input2->setInputValue(0,false);


	s1->transmit();
	s2->transmit();

	and->calculate(1);

	s3->transmit();

	input1->setInputValue(0,true);
	input2->setInputValue(0,true);


	s1->transmit();
	s2->transmit();

	and->calculate(1);

	s3->transmit();
	//input1->setInputValue(0,false);
	//input2->setInputValue(0,false);

	
	

	//test->setInput(0,s1);
	//test->setInput(1,s2);
	//test->setOutput(0,s3);

//	s1->setValue(0);
//	s2->setValue(1);

	//test->calculate(0);

	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausf�hren
	Application::Run(gcnew MainForm());

	//TODO remove line below in Final Application
	System::Console::ReadLine();
	//TODO remove line above in Final Application

	return 0;
}
