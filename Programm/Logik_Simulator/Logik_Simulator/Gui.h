#pragma once

#include "LogicWidget.h"


namespace Logik_Simulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace LogicWidgets;

	/// <summary>
	/// Zusammenfassung für Form1
	///
	/// Warnung: Wenn Sie den Namen dieser Klasse ändern, müssen Sie auch
	///          die Ressourcendateiname-Eigenschaft für das Tool zur Kompilierung verwalteter Ressourcen ändern,
	///          das allen RESX-Dateien zugewiesen ist, von denen diese Klasse abhängt.
	///          Anderenfalls können die Designer nicht korrekt mit den lokalisierten Ressourcen
	///          arbeiten, die diesem Formular zugewiesen sind.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();

			this->rnd = (gcnew System::Random());
			this->widget_grabbed = false;
			this->logic_widgets = gcnew ArrayList();
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: System::Random^ rnd;
			   Boolean widget_grabbed;
			   LogicWidget^ grabbed_widget;
			   LogicWidget^ selected_widget;
			   Point^ mouse_down_location;
			   Point^ grabbed_widget_location;

	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton6;
	protected:

	protected:


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container ^components;
		ArrayList^ logic_widgets;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			//
			// toolStrip1
			//
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {this->toolStripButton1,
				this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(457, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			//
			// toolStripButton1
			//
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(36, 22);
			this->toolStripButton1->Text = L"AND";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// toolStripButton2
			//
			this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton2.Image")));
			this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton2->Name = L"toolStripButton2";
			this->toolStripButton2->Size = System::Drawing::Size(27, 22);
			this->toolStripButton2->Text = L"OR";
			this->toolStripButton2->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// toolStripButton3
			//
			this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton3.Image")));
			this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton3->Name = L"toolStripButton3";
			this->toolStripButton3->Size = System::Drawing::Size(36, 22);
			this->toolStripButton3->Text = L"NOT";
			this->toolStripButton3->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// toolStripButton4
			//
			this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
			this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton4->Name = L"toolStripButton4";
			this->toolStripButton4->Size = System::Drawing::Size(34, 22);
			this->toolStripButton4->Text = L"XOR";
			this->toolStripButton4->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// toolStripButton5
			//
			this->toolStripButton5->Checked = true;
			this->toolStripButton5->CheckState = System::Windows::Forms::CheckState::Checked;
			this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton5.Image")));
			this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton5->Name = L"toolStripButton5";
			this->toolStripButton5->Size = System::Drawing::Size(36, 22);
			this->toolStripButton5->Text = L"NOR";
			this->toolStripButton5->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// toolStripButton6
			//
			this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
			this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton6.Image")));
			this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton6->Name = L"toolStripButton6";
			this->toolStripButton6->Size = System::Drawing::Size(45, 22);
			this->toolStripButton6->Text = L"NAND";
			this->toolStripButton6->Click += gcnew System::EventHandler(this, &Form1::toolStripButtons_Click);
			//
			// Form1
			//
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(457, 271);
			this->Controls->Add(this->toolStrip1);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseUp);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::Form1_Paint);
			this->Click += gcnew System::EventHandler(this, &Form1::Form1_Click);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Form1::Form1_MouseMove);
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:

		 Boolean check_widget_hit(Point^ location) {
		 	for each (Object^ obj in this->logic_widgets) {
		 		LogicWidget^ lw =  safe_cast<LogicWidget^>(obj);
		 		Point^ widget_location = lw->location;

		 		if (lw->widget_hit(location))
		 		{
		 				this->widget_grabbed = true;
		 				this->grabbed_widget = lw;
						this->grabbed_widget_location = lw->location;
		 				return true;
		 		}
		 	}

		 	this->widget_grabbed = false;
			this->grabbed_widget = nullptr;
		 	return false;
		 }

		 Void move_widget(Point^ location){
		 			int x_diff = location->X - this->mouse_down_location->X;
					int y_diff = location->Y - this->mouse_down_location->Y;

					Point new_loc = Point(grabbed_widget_location->X + x_diff, grabbed_widget_location->Y + y_diff);

					grabbed_widget->location = new_loc;

					this->Invalidate();
					this->Update();
		 }



private: System::Void toolStripButtons_Click(System::Object^  sender, System::EventArgs^  e) {
				ToolStripButton^ sen = safe_cast<ToolStripButton^>(sender);
				Boolean new_state = !(sen->Checked);

				for each (ToolStripButton^ btn in this->toolStrip1->Items) {
					btn->Checked = false;
				}

				sen->Checked = new_state;
		 }

private: System::Void Form1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void Form1_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {

			if (widget_grabbed) {
				// MouseDown inside of a Widget, might be drag 'n drop or click

				if ( (mouse_down_location->X == e->X) && (mouse_down_location->Y == e->Y) ) {
					// MouseDown location equals MouseUp location -> click
					// change selection and repaint form

					if (grabbed_widget == selected_widget) {
						// grabbed widget equals selected widget -> deselect widget

						grabbed_widget->selected = false;
						selected_widget = nullptr;
					} else {
						// grabbed widget different from selected widget -> select another widget and deselect currently selected

						grabbed_widget->selected = true;

						if (selected_widget) {
							selected_widget->selected = false;
						}

						selected_widget = grabbed_widget;
					}

					// repaint
					this->Invalidate();
					this->Update();

				} else {
					// MouseDown location different from MouseUp location -> drag 'n drop

					move_widget(gcnew Point(e->X, e->Y));
				}

				// ungrab widget
				this->grabbed_widget = nullptr;
				this->widget_grabbed = false;

			} else {
				// MouseDown outside of a Widget -> create a widget here

				ToolStripButton^ btn;

				for each (ToolStripButton^ ts_btn in this->toolStrip1->Items) {
					if ( ts_btn->Checked ) {
						btn = ts_btn;
					}
				}

				if ( btn ) {
					LogicWidget^ lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y));

					this->logic_widgets->Add(lw);

					// repaint
					this->Invalidate();
					this->Update();

				}
			}
		}

private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e) {
		 }

private: System::Void Form1_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			 e->Graphics->Clear(Color::Gray);

			 for each (Object^ obj in this->logic_widgets) {
				 (safe_cast<LogicWidget^>(obj))->LogicWidget_Paint(e->Graphics);
			 }
		 }

private: System::Void Form1_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			check_widget_hit(e->Location);

			this->mouse_down_location = e->Location;
		 }

private: System::Void Form1_MouseMove(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
			if (widget_grabbed)
			{

				move_widget( gcnew Point( e->X, e->Y ) );

			}
		 }
};
}

