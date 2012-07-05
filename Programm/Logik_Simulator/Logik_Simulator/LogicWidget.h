#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets {

	ref class LogicWidget
	{
		public:
			LogicWidget(String^ type, Form^ form)
			{
				this->type = type;
				this->form = form;
			}

			Point^ coords;

		protected:
			~LogicWidget()
			{

			}

			String^ type;
			Form^ form;

		public:
			System::Void LogicWidget_Paint() {
				Graphics^ canvas = form->CreateGraphics();
					 Pen^ pen = gcnew Pen(Color::Black);
					 Font^ font = gcnew Font(FontFamily::GenericMonospace, 10);
					 SolidBrush^ sb = gcnew SolidBrush(Color::Black);

					 canvas->DrawRectangle(pen, coords->X -3, coords->Y - 3, 40, 20);
					 canvas->DrawString(type, font, sb , safe_cast<float>(coords->X), safe_cast<float>(coords->Y));
			}
	};
}
