#pragma once

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets {

	public ref class LogicWidget
	{
		public:
			LogicWidget( String^ type, Point^ location ) {
				this->type = type;
				this->location = location;

				this->size = gcnew Size(40, 40);
				this->selected = false;
			}

			LogicWidget( ) {
			}

			Point^ location;
			Boolean selected;

		protected:

			String^ type;
			Graphics^ graphic_context;
			Size^ size;


		public:
			System::Void LogicWidget_Paint(Graphics^ canvas) {
				Color color;

				if (selected)
				{
					color = Color::Blue;
				} else {
					color = Color::Black;
				}

				Pen^ pen = gcnew Pen(color);
				Font^ font = gcnew Font(FontFamily::GenericMonospace, 10);
				SolidBrush^ sb = gcnew SolidBrush(color);

				canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
				canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) +3);
			}

			Size^ getSize() {
				return this->size;
			}

			Boolean widget_hit(Point^ click_location) {
				if ( ( click_location->X >= this->location->X ) && ( click_location->X  <= this->location->X + this->size->Width ) )
		 		{
		 			if ( ( click_location->Y >= this->location->Y ) && ( click_location->Y <= this->location->Y  + this->size->Height ) )
		 			{
		 				return true;
		 			}
		 		}

		 		return false;
			}
	};
}
