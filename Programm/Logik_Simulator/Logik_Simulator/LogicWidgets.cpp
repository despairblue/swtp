#pragma once

#include "stdafx.h"

#include "Gatter.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets {

	ref class SignalWidget;
	ref class LogicWidget;

	public ref class LogicWidget
	{
		public:
			LogicWidget( String^ type, Point^ location, Gatter^ gate ) {
				this->type = type;
				this->location = location;
				this->gate = gate;

				this->size = gcnew Size(40, 40);
				this->selected = false;
			}

			LogicWidget( ) {
			}

			Point^ location;
			Boolean selected;

		protected:
			Size^ size;
			String^ type;
			Graphics^ graphic_context;
			Gatter^ gate;
			SignalWidget^ input;
			SignalWidget^ output;


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

			Gatter^ getGate() {
				return this->gate;
			}

			Boolean connect_input_signal(SignalWidget^ sw) {
				this->input = sw;

				return true;
			}

			Boolean connect_output_signal(SignalWidget^ sw) {
				this->output = sw;

				return true;
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

public ref class SignalWidget {
	protected:
		LogicWidget^ input;
		LogicWidget^ output;

	public:
		SignalWidget(void) {

		}

		void SignalWidget_Paint( Graphics^ canvas ) {
			Pen^ pen = gcnew Pen(Color::Black);

			canvas->DrawLine(pen, input->location->X + input->getSize()->Width, input->location->Y + (input->getSize()->Height / 2),
				output->location->X, output->location->Y + ( input->getSize()->Height / 2 ) );
		}

		void setInput(LogicWidget^ lw) {
			this->input = lw;
			lw->connect_input_signal(this);
		}

		void setOutput(LogicWidget^ lw) {
			this->output = lw;
			lw->connect_output_signal(this);
		}
};
}



