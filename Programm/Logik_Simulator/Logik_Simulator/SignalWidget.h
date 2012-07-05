#pragma once

#include "LogicWidget.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
using namespace System::Collections;
using namespace LogicWidgets;

namespace LogicWidgets {
	public ref class SignalWidget
	{
	public:
		SignalWidget( ) {
		}

		LogicWidget^ input;
		ArrayList^ outputs;

		System::Void SignalWidget_Paint( Graphics^ canvas ) {
			Pen^ pen = gcnew Pen(Color::Black);

			for each (Object^ obj in outputs) {
				LogicWidget^ lw = safe_cast<LogicWidget^>(obj);
				canvas->DrawLine(pen, input->location->X + 40, input->location->Y + 20, lw->location->X, lw->location->Y + 20);
			}
		}
	};
}
