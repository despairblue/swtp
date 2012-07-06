// Logik_Simulator.cpp: Hauptprojektdatei.

#include "stdafx.h"
#include "MainForm.h"
#include "Gatter.h"
#include "Signal.h"
#include "Input.h"
#include "Output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Nand.h"
#include "Nor.h"
#include "Exor.h"


using namespace Logik_Simulator;

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{
	
	And^ and = gcnew And(2,1);
	Or^ or = gcnew Or(2,1);
	And^ and1 = gcnew And(2,1);

	Input^ input1 = gcnew Input();
	Input^ input2 = gcnew Input();
	Input^ input3 = gcnew Input();

	Output^ output = gcnew Output();

	Signal^ s1 = gcnew Signal();
	Signal^ s2 = gcnew Signal();
	Signal^ s3 = gcnew Signal();

	Signal^ s4 = gcnew Signal();
	Signal^ s5 = gcnew Signal();

	Signal^ s6 = gcnew Signal();

	input1->setInputValue(0,true);
	input2->setInputValue(0,false);
	input3->setInputValue(0,false);
	
	s1->setInputGate(input1, 0);
	s1->addOutputGate(and,0);
	
	s2->setInputGate(input2, 0);
	s2->addOutputGate(and, 1);
	s2->addOutputGate(or, 0);

	s3->setInputGate(input3,0);
	s3->addOutputGate(or,1);

	s4->setInputGate(and,0);
	s4->addOutputGate(and1,0);

	s5->setInputGate(or, 0);
	s5->addOutputGate(and1,0);

	s6->setInputGate(and1,0);
	s6->addOutputGate(output, 0);


	s1->transmit();
	s2->transmit();
	s3->transmit();

	
	s4->transmit();
	s5->transmit();
	s6->transmit();

	

	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false); 

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew MainForm());

	//TODO remove line below in Final Application
	System::Console::ReadLine();
	//TODO remove line above in Final Application

	return 0;
}
