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
	private: System::Windows::Forms::Button^  btn_add_AND;
	private: System::Windows::Forms::ToolStrip^  toolStrip1;
	private: System::Windows::Forms::ToolStripButton^  toolStripButton1;
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
			this->btn_add_AND = (gcnew System::Windows::Forms::Button());
			this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			this->toolStrip1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btn_add_AND
			// 
			this->btn_add_AND->Location = System::Drawing::Point(96, 105);
			this->btn_add_AND->Name = L"btn_add_AND";
			this->btn_add_AND->Size = System::Drawing::Size(75, 23);
			this->btn_add_AND->TabIndex = 1;
			this->btn_add_AND->Text = L"AND";
			this->btn_add_AND->UseVisualStyleBackColor = true;
			// 
			// toolStrip1
			// 
			this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripButton1});
			this->toolStrip1->Location = System::Drawing::Point(0, 0);
			this->toolStrip1->Name = L"toolStrip1";
			this->toolStrip1->Size = System::Drawing::Size(266, 25);
			this->toolStrip1->TabIndex = 2;
			this->toolStrip1->Text = L"toolStrip1";
			// 
			// toolStripButton1
			// 
			this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton1.Image")));
			this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			this->toolStripButton1->Name = L"toolStripButton1";
			this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			this->toolStripButton1->Text = L"toolStripButton1";
			this->toolStripButton1->Click += gcnew System::EventHandler(this, &Form1::toolStripButton1_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(266, 232);
			this->Controls->Add(this->toolStrip1);
			this->Controls->Add(this->btn_add_AND);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->toolStrip1->ResumeLayout(false);
			this->toolStrip1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

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
				btn->Location = System::Drawing::Point(this->rnd->Next(0, this->Size.Width), this->rnd->Next(0, this->Size.Height));
				this->Controls->Add(btn);
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
private: System::Void toolStripButton1_Click(System::Object^  sender, System::EventArgs^  e) {
			 	System::Windows::Forms::Button^  btn;
				btn = (gcnew System::Windows::Forms::Button());
				btn->Name = L"AND";
				btn->Text = L"AND";
				btn->Click += gcnew EventHandler(this, &Form1::AND_Click);
				btn->MouseDown += gcnew MouseEventHandler(this, &Form1::AND_MouseDown);
				btn->MouseUp   += gcnew MouseEventHandler(this, &Form1::AND_MouseUp);
				btn->Location = System::Drawing::Point(this->rnd->Next(0, this->Size.Width), this->rnd->Next(0, this->Size.Height));
				this->Controls->Add(btn);
		 }
};
}

