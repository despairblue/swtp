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
	private: System::Windows::Forms::SplitContainer^  splitContainer1;
	protected: System::Random^ rnd;
			   Boolean mouse_down;
			   Point loc_mouse_down;
	private: System::Windows::Forms::Button^  btn_add_AND;
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
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->btn_add_AND = (gcnew System::Windows::Forms::Button());
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			this->SuspendLayout();
			// 
			// splitContainer1
			// 
			this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer1->Location = System::Drawing::Point(0, 0);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->btn_add_AND);
			this->splitContainer1->Size = System::Drawing::Size(266, 232);
			this->splitContainer1->SplitterDistance = 92;
			this->splitContainer1->TabIndex = 0;
			// 
			// btn_add_AND
			// 
			this->btn_add_AND->Location = System::Drawing::Point(10, 12);
			this->btn_add_AND->Name = L"btn_add_AND";
			this->btn_add_AND->Size = System::Drawing::Size(75, 23);
			this->btn_add_AND->TabIndex = 0;
			this->btn_add_AND->Text = L"AND";
			this->btn_add_AND->UseVisualStyleBackColor = true;
			this->btn_add_AND->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(266, 232);
			this->Controls->Add(this->splitContainer1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				System::Windows::Forms::Button^  btn;
				btn = (gcnew System::Windows::Forms::Button());
				btn->Name = L"AND";
				btn->Text = L"AND";
				btn->Click += gcnew EventHandler(this, &Form1::AND_Click);
				btn->MouseDown += gcnew MouseEventHandler(this, &Form1::AND_MouseDown);
				btn->MouseUp   += gcnew MouseEventHandler(this, &Form1::AND_MouseUp);
				btn->Location = System::Drawing::Point(this->rnd->Next(0, this->splitContainer1->Panel2->Size.Width), this->rnd->Next(0, this->splitContainer1->Panel2->Size.Height));
				this->splitContainer1->Panel2->Controls->Add(btn);
			 }

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
};
}

