// Logik_Simulator.cpp: Hauptprojektdatei.
#pragma once

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

void startSimulation(ArrayList^ inputList)
{
	int index = inputList->Count;

	for(int i = 0;i< index; i++)
	{
		safe_cast<Signal^>(inputList[i])->transmit();
	}
}

[STAThreadAttribute]
int main(array<System::String ^> ^args)
{

	And^ and = gcnew And();
	//Or^ or = gcnew Or();
	//And^ and1 = gcnew And();

	ArrayList^ inputList = gcnew ArrayList();

	Input^ input1 = gcnew Input();
	Input^ input2 = gcnew Input();
	//Input^ input3 = gcnew Input();

	Output^ output = gcnew Output();

	Signal^ s1 = gcnew Signal();
	Signal^ s2 = gcnew Signal();
	Signal^ s3 = gcnew Signal();

	inputList->Add(s1);
	inputList->Add(s2);
	//inputList->Add(s3);

	//Signal^ s4 = gcnew Signal();
	//Signal^ s5 = gcnew Signal();

	//Signal^ s6 = gcnew Signal();

	s1->setInputGate(input1, 0);
	s1->addOutputGate(and,0);

	s2->setInputGate(input2, 0);
	s2->addOutputGate(and, 1);
//	s2->addOutputGate(or, 0);

	s3->setInputGate(and,0);
	s3->addOutputGate(output,0);

/*	s4->setInputGate(and,0);
	s4->addOutputGate(and1,0);

	s5->setInputGate(or, 0);
	s5->addOutputGate(and1,1);

	s6->setInputGate(and1,0);
	s6->addOutputGate(output, 0);`*/
	input1->setInputValue(true);
	input2->setInputValue(true);
	//input3->setInputValue(false);

	startSimulation(inputList);

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

