#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets {

	public ref class LogicWidget
	{
		public:
			LogicWidget(String^ type, Point^ location)
			{
				this->type = type;
				this->location = location;
			}

			LogicWidget(){
			}

			Point^ location;

		protected:

			String^ type;
			Graphics^ graphic_context;

		public:
			System::Void LogicWidget_Paint(Graphics^ canvas) {
				Pen^ pen = gcnew Pen(Color::Black);
				Font^ font = gcnew Font(FontFamily::GenericMonospace, 10);
				SolidBrush^ sb = gcnew SolidBrush(Color::Black);

				canvas->DrawRectangle(pen, location->X -3, location->Y - 3, 40, 20);
				canvas->DrawString(type, font, sb , safe_cast<float>(location->X), safe_cast<float>(location->Y));
			}
	};
}
