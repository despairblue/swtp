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

	// Aktivieren visueller Effekte von Windows XP, bevor Steuerelemente erstellt werden
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	// Hauptfenster erstellen und ausführen
	Application::Run(gcnew MainForm());
	
	System::Console::ReadLine();
	return 0;
}

