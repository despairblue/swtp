#pragma once

#include "StdAfx.h"
#include "SignalWidget.h"

#include "LogicWidget.cpp"
#include "Gatter.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections;
using namespace LogicWidgets;

namespace LogicWidgets {

public ref class SignalWidget {
	public:
		LogicWidget^ input;
		LogicWidget^ output;

		SignalWidget(void) {

		}

		void SignalWidget_Paint( Graphics^ canvas ) {
			Pen^ pen = gcnew Pen(Color::Black);

			canvas->DrawLine(pen, input->location->X + input->getSize()->Width, input->location->Y + (input->getSize()->Height / 2),
				output->location->X, output->location->Y + ( input->getSize()->Height / 2 ) );

		}
};
}
