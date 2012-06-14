#pragma once


namespace Logik_Simulator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
			this->mouse_down = false;
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
			   Boolean mouse_down;
			   Point loc_mouse_down;

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
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
			System::Void AND_Click(System::Object^ sender, System::EventArgs^ e) {
				 Button^ btn = safe_cast<Button^>(sender);
				 String^ x_coord = L"X: " + btn->Location.X.ToString();
				 String^ y_coord = L"Y: " + btn->Location.Y.ToString();

				 MessageBox::Show(L"You clicked a Button", x_coord + " " + y_coord, MessageBoxButtons::OK,MessageBoxIcon::Information , MessageBoxDefaultButton::Button1, MessageBoxOptions::DefaultDesktopOnly, false);
			 }

			 System::Void AND_MouseDown(System::Object^ sender, MouseEventArgs^ e) {
				 this->mouse_down = true;
				 this->loc_mouse_down = e->Location;
			 }

			 Void AND_MouseUp(Object^ sender, MouseEventArgs^ e) {
				this->mouse_down = false;
				Button^ btn = safe_cast<Button^>(sender);
				int x_diff = e->X - this->loc_mouse_down.X;
				int y_diff = e->Y - this->loc_mouse_down.Y;

				Point new_loc = Point(btn->Location.X + x_diff, btn->Location.Y + y_diff);
				btn->Location = new_loc;
			 }
private: System::Void toolStripButtons_Click(System::Object^  sender, System::EventArgs^  e) {
				ToolStripButton^ sen = safe_cast<ToolStripButton^>(sender);
				Button^ btn = (gcnew System::Windows::Forms::Button());

				btn->Name     = sen->Name;
				btn->Text     = sen->Text;
				btn->Location = System::Drawing::Point(5, this->toolStrip1->Height + 5);

				btn->Click     += gcnew EventHandler(this, &Form1::AND_Click);
				btn->MouseDown += gcnew MouseEventHandler(this, &Form1::AND_MouseDown);
				btn->MouseUp   += gcnew MouseEventHandler(this, &Form1::AND_MouseUp);
				
				this->Controls->Add(btn);
		 }
};
}

