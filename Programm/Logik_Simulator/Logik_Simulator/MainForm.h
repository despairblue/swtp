#pragma once

#include "LogicWidgets.h"

#include "Gatter.h"
#include "Signal.h"
#include "Input.h"
#include "Output.h"
#include "And.h"
#include "Or.h"
#include "Not.h"
#include "Nand.h"
#include "Nor.h"
#include "Exor.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace LogicWidgets;


namespace Logik_Simulator
{

/// <summary>
/// Summary for MainForm
///
/// WARNING: If you change the name of this class, you will need to change the
///          'Resource File Name' property for the managed resource compiler tool
///          associated with all .resx files this class depends on.  Otherwise,
///          the designers will not be able to interact properly with localized
///          resources associated with this form.
/// </summary>
public ref class MainForm : public System::Windows::Forms::Form
{
public:
    MainForm(void)
    {
        InitializeComponent();

        this->toolStripButtons = gcnew ArrayList();
        this->logic_widgets = gcnew ArrayList();
        this->signal_widgets = gcnew ArrayList();
        this->toDelete = gcnew ArrayList();

        for each (Object ^ obj in this->toolStrip1->Items)
        {
            if (obj->GetType() == ToolStripButton::typeid)
            {
                this->toolStripButtons->Add( safe_cast < ToolStripButton ^ > ( obj ) );
            }
        }
    }

protected:
    /// <summary>
    /// Clean up any resources being used.
    /// </summary>
    ~MainForm()
    {
        if (components)
        {
            delete components;
        }
    }

protected:
    LogicWidget ^ grabbed_widget;
    LogicWidget ^ selected_widget;
    Point ^ mouse_down_location;
    Point ^ grabbed_widget_location;
    ArrayList ^ toolStripButtons;
    ArrayList ^ logic_widgets;
    ArrayList ^ signal_widgets;
    ArrayList ^ toDelete;


private: System::Windows::Forms::ToolStrip ^  toolStrip1;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton1;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton2;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton3;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton4;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton5;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton6;
private: System::Windows::Forms::StatusStrip ^  statusStrip1;
private: System::Windows::Forms::ToolStripStatusLabel ^  toolStripStatusLabel1;
private: System::Windows::Forms::ToolStripSeparator ^  toolStripSeparator1;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton7;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton8;
private: System::Windows::Forms::ToolStripSeparator ^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton9;
private: System::Windows::Forms::SplitContainer ^  splitContainer1;
private: System::Windows::Forms::DataGridView ^  dataGridView1;
private: System::Windows::Forms::PictureBox ^  pictureBox1;
private: System::Windows::Forms::BindingSource^  mainFormBindingSource;

private: System::Windows::Forms::BindingSource^  logicWidgetBindingSource;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^  Header;




private: System::ComponentModel::IContainer^  components;
protected:

protected:


private:
    /// <summary>
    /// Erforderliche Designervariable.
    /// </summary>


    #pragma region Windows Form Designer generated code
    /// <summary>
    /// Erforderliche Methode für die Designerunterstützung.
    /// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
    /// </summary>
    void InitializeComponent(void)
    {
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
		this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
		this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
		this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
		this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->Header = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->logicWidgetBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
		this->mainFormBindingSource = (gcnew System::Windows::Forms::BindingSource(this->components));
		this->toolStrip1->SuspendLayout();
		this->statusStrip1->SuspendLayout();
		this->splitContainer1->Panel1->SuspendLayout();
		this->splitContainer1->Panel2->SuspendLayout();
		this->splitContainer1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logicWidgetBindingSource))->BeginInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainFormBindingSource))->BeginInit();
		this->SuspendLayout();
		// 
		// toolStrip1
		// 
		this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(11) {this->toolStripButton1, 
			this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6, this->toolStripSeparator1, 
			this->toolStripButton7, this->toolStripButton8, this->toolStripSeparator2, this->toolStripButton9});
		this->toolStrip1->Location = System::Drawing::Point(0, 0);
		this->toolStrip1->Name = L"toolStrip1";
		this->toolStrip1->Size = System::Drawing::Size(457, 25);
		this->toolStrip1->TabIndex = 2;
		this->toolStrip1->Text = L"toolStrip1";
		// 
		// toolStripButton1
		// 
		this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton1->Name = L"toolStripButton1";
		this->toolStripButton1->Size = System::Drawing::Size(36, 22);
		this->toolStripButton1->Tag = L"1";
		this->toolStripButton1->Text = L"AND";
		this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton2
		// 
		this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton2->Name = L"toolStripButton2";
		this->toolStripButton2->Size = System::Drawing::Size(27, 22);
		this->toolStripButton2->Tag = L"2";
		this->toolStripButton2->Text = L"OR";
		this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton3
		// 
		this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton3->Name = L"toolStripButton3";
		this->toolStripButton3->Size = System::Drawing::Size(36, 22);
		this->toolStripButton3->Tag = L"3";
		this->toolStripButton3->Text = L"NOT";
		this->toolStripButton3->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton4
		// 
		this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton4.Image")));
		this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton4->Name = L"toolStripButton4";
		this->toolStripButton4->Size = System::Drawing::Size(34, 22);
		this->toolStripButton4->Tag = L"4";
		this->toolStripButton4->Text = L"XOR";
		this->toolStripButton4->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton5
		// 
		this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton5->Name = L"toolStripButton5";
		this->toolStripButton5->Size = System::Drawing::Size(36, 22);
		this->toolStripButton5->Tag = L"5";
		this->toolStripButton5->Text = L"NOR";
		this->toolStripButton5->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton6
		// 
		this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton6->Name = L"toolStripButton6";
		this->toolStripButton6->Size = System::Drawing::Size(45, 22);
		this->toolStripButton6->Tag = L"6";
		this->toolStripButton6->Text = L"NAND";
		this->toolStripButton6->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripSeparator1
		// 
		this->toolStripSeparator1->Name = L"toolStripSeparator1";
		this->toolStripSeparator1->Size = System::Drawing::Size(6, 25);
		// 
		// toolStripButton7
		// 
		this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton7->Name = L"toolStripButton7";
		this->toolStripButton7->Size = System::Drawing::Size(39, 22);
		this->toolStripButton7->Tag = L"7";
		this->toolStripButton7->Text = L"Input";
		this->toolStripButton7->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton8
		// 
		this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton8->Name = L"toolStripButton8";
		this->toolStripButton8->Size = System::Drawing::Size(49, 22);
		this->toolStripButton8->Tag = L"8";
		this->toolStripButton8->Text = L"Output";
		this->toolStripButton8->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripSeparator2
		// 
		this->toolStripSeparator2->Name = L"toolStripSeparator2";
		this->toolStripSeparator2->Size = System::Drawing::Size(6, 25);
		// 
		// toolStripButton9
		// 
		this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton9.Image")));
		this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton9->Name = L"toolStripButton9";
		this->toolStripButton9->Size = System::Drawing::Size(23, 22);
		this->toolStripButton9->Tag = L"9";
		this->toolStripButton9->Text = L"toolStripButton9";
		this->toolStripButton9->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton9_Click);
		// 
		// statusStrip1
		// 
		this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
		this->statusStrip1->Location = System::Drawing::Point(0, 249);
		this->statusStrip1->Name = L"statusStrip1";
		this->statusStrip1->Size = System::Drawing::Size(457, 22);
		this->statusStrip1->TabIndex = 3;
		this->statusStrip1->Text = L"statusStrip1";
		// 
		// toolStripStatusLabel1
		// 
		this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
		this->toolStripStatusLabel1->Size = System::Drawing::Size(170, 17);
		this->toolStripStatusLabel1->Text = L"Select a Gate from the tool bar.";
		// 
		// splitContainer1
		// 
		this->splitContainer1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->splitContainer1->Location = System::Drawing::Point(0, 25);
		this->splitContainer1->Name = L"splitContainer1";
		// 
		// splitContainer1.Panel1
		// 
		this->splitContainer1->Panel1->Controls->Add(this->pictureBox1);
		// 
		// splitContainer1.Panel2
		// 
		this->splitContainer1->Panel2->Controls->Add(this->dataGridView1);
		this->splitContainer1->Size = System::Drawing::Size(457, 224);
		this->splitContainer1->SplitterDistance = 319;
		this->splitContainer1->TabIndex = 4;
		this->splitContainer1->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
		this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pictureBox1->Location = System::Drawing::Point(0, 0);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(315, 220);
		this->pictureBox1->TabIndex = 0;
		this->pictureBox1->TabStop = false;
		this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
		this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
		this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
		this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
		// 
		// dataGridView1
		// 
		this->dataGridView1->AllowUserToOrderColumns = true;
		this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
		//this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) {this->Header});
		this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->dataGridView1->Location = System::Drawing::Point(0, 0);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->RightToLeft = System::Windows::Forms::RightToLeft::Yes;
		this->dataGridView1->Size = System::Drawing::Size(130, 220);
		this->dataGridView1->TabIndex = 0;
		// 
		// logicWidgetBindingSource
		// 
		this->logicWidgetBindingSource->DataSource = LogicWidgets::LogicWidget::typeid;
		// 
		// mainFormBindingSource
		// 
		this->mainFormBindingSource->DataSource = Logik_Simulator::MainForm::typeid;
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(457, 271);
		this->Controls->Add(this->splitContainer1);
		this->Controls->Add(this->statusStrip1);
		this->Controls->Add(this->toolStrip1);
		this->DoubleBuffered = true;
		this->Name = L"MainForm";
		this->Text = L"MainForm";
		this->toolStrip1->ResumeLayout(false);
		this->toolStrip1->PerformLayout();
		this->statusStrip1->ResumeLayout(false);
		this->statusStrip1->PerformLayout();
		this->splitContainer1->Panel1->ResumeLayout(false);
		this->splitContainer1->Panel2->ResumeLayout(false);
		this->splitContainer1->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->logicWidgetBindingSource))->EndInit();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->mainFormBindingSource))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();
        
    }
    #pragma endregion

private:
    void changeStatusBar(String ^ text)
    {
        this->toolStripStatusLabel1->Text = text;
    }

    LogicWidget ^ checkWidgetHit(Point ^ location)
    {
        for each (LogicWidget ^ lw in this->logic_widgets)
        {
            Point ^ widget_location = lw->getLocation();

            if (lw->widgetHit(location))
            {
                return lw;
            }
        }
        return nullptr;
    }

    void move_widget(Point ^ location)
    {
        int x_diff = location->X - this->mouse_down_location->X;
        int y_diff = location->Y - this->mouse_down_location->Y;

        Point new_loc = Point(grabbed_widget_location->X + x_diff, grabbed_widget_location->Y + y_diff);

        grabbed_widget->setLocation(new_loc);

        repaint();
    }

    void repaint()
    {
        pictureBox1->Invalidate();
        pictureBox1->Update();
    }

    Int32 createID(Type ^ type)
    {
        Int32 result = 0;

        for each (LogicWidget ^ lw in logic_widgets)
        {
            if (type == InputWidget::typeid)
            {
                if (lw->GetType() == InputWidget::typeid)
                {
                    InputWidget ^ iw = safe_cast < InputWidget ^ > (lw);

                    if (iw->getID() > result)
                    {
                        result = iw->getID();
                    }
                }
            }else if (type == OutputWidget::typeid)
            {
            	if (lw->GetType() == OutputWidget::typeid)
            	{
            		OutputWidget ^ ow = safe_cast <OutputWidget ^> (lw);

            		if (ow->getID() > result)
            		{
            			result = ow->getID();
            		}
            	}
            }
        }

        result++;

        return result;
    }

	void refreshTable() {
		for each (LogicWidget ^ lw in logic_widgets)
    	{
			if(lw->GetType() == InputWidget::typeid)
			{
				this->dataGridView1->Columns->Add("Input"+ safe_cast<InputWidget^>(lw)->getID(), "Input"+ safe_cast<InputWidget^>(lw)->getID());
			}
			
			/*if(lw->GetType() == OutputWidget::typeid)
			{
				this->dataGridView1->Columns->Add("Input"+ safe_cast<OutputWidget^>(lw)->getID(), "Input"+ safe_cast<OutputWidget^>(lw)->getID());
			}*/
		}
	}

    void toolStripButtons_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        ToolStripButton ^ sen = safe_cast < ToolStripButton ^ > (sender);
        Boolean new_state = !(sen->Checked);

        for each (ToolStripButton ^ btn in this->toolStripButtons)
        {
            btn->Checked = false;
        }

        sen->Checked = new_state;

        if (sen->Checked)
        {
            changeStatusBar("Click anywhere on the canvas to place the Gate.");
        }
        else
        {
            changeStatusBar("Select a Gate from the tool bar.");
        }
    }

    void MainForm_MouseUp(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {

        if (grabbed_widget)
        {
            // MouseDown inside of a Widget, might be drag 'n drop or click

            if ( (mouse_down_location->X == e->X) && (mouse_down_location->Y == e->Y) )
            {
                // MouseDown location equals MouseUp location -> click
                // change selection and repaint form

                grabbed_widget->click(this->toolStripStatusLabel1);

                if ( grabbed_widget == selected_widget )
                {
                    // grabbed widget is previous selected widget
                    if ( !(selected_widget->selected) )
                    {
                        // selected widget is not selected anymore
                        selected_widget = nullptr;
                    }
                }
                else
                {
                    // grabbed widget differs from previous selected widget
                    if ( grabbed_widget->selected )
                    {
                        // grabbed widget is selected
                        if (selected_widget)
                        {
                            // deselect previous selected widget
                            selected_widget->selected = false;
                        }

                        // grabbed widget is new selected widget
                        selected_widget = grabbed_widget;
                    }
                }
            }
            else
            {
                // MouseDown location different from MouseUp location -> drag 'n drop or connect

                if (grabbed_widget->selected)
                {
                    // grabbed_widget was selected -> connect to other widget

                    LogicWidget ^ other_widget = checkWidgetHit(e->Location);

                    // only connect if the mouse if over another widget
                    if ( other_widget && (other_widget != grabbed_widget) )
                    {

                        Signal ^ signal = gcnew Signal();

                        SignalWidget ^ sw = gcnew SignalWidget(signal);
                        sw->setInputGate(this->grabbed_widget);
                        sw->setOutputGate(other_widget);

                        if (sw->isDestructed())
                        {
                            changeStatusBar("Couldn't connect. Gate might not have any free input slots left.");
                        }
                        this->signal_widgets->Add(sw);
                    }
                    else
                    {
                        changeStatusBar("No connection made. There was no Gate beneath your cursor.");
                    }


                }
                else
                {
                    // grabbed widget was not selected -> move widget

                    move_widget(gcnew Point(e->X, e->Y));
                }
            }

            // ungrab widget
            this->grabbed_widget = nullptr;

        }
        else
        {
            // MouseDown outside of a Widget -> create a widget here

            ToolStripButton ^ btn;

            for each (ToolStripButton ^ ts_btn in this->toolStripButtons)
            {
                if ( ts_btn->Checked )
                {
                    btn = ts_btn;
                }
            }

            if ( btn )
            {
                Gatter ^ gate;
                LogicWidget ^ lw;

                switch (Int32::Parse(btn->Tag->ToString()))
                {
                case 1:
                    gate = gcnew And();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
					break;
                case 2:
                    gate = gcnew Or();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
                    break;
                case 3:
                    gate = gcnew Not();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
                    break;
                case 4:
                    gate = gcnew Exor();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
                    break;
                case 5:
                    gate = gcnew Nor();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
                    break;
                case 6:
                    gate = gcnew Nand();
                    lw = gcnew LogicWidget(btn->Text, gcnew Point(e->X, e->Y), gate);
                    break;
                case 7:
                    gate = gcnew Input();
                    lw = gcnew InputWidget(btn->Text, gcnew Point(e->X, e->Y), safe_cast < Input ^ > ( gate), createID(InputWidget::typeid));
					break;
                case 8:
                    gate = gcnew Output();
                    lw = gcnew OutputWidget(btn->Text, gcnew Point(e->X, e->Y), safe_cast <Output ^> (gate), createID(OutputWidget::typeid));
                    break;
                }
                this->logic_widgets->Add(lw);
            }
        }

        repaint();
		refreshTable();
    }

    void MainForm_Paint(System::Object ^  sender, System::Windows::Forms::PaintEventArgs ^  e)
    {
        e->Graphics->Clear(Color::LightGray);

        for each (LogicWidget ^ lw in this->logic_widgets)
        {
			if (lw->isDestructed())
            {
                this->toDelete->Add(lw);
            }
            else
            {
                (lw)->paint(e->Graphics);
            }
        }

        for each (SignalWidget ^ sw in this->signal_widgets)
        {
            if (sw->isDestructed())
            {
                this->toDelete->Add(sw);
            }
            else
            {
                (sw)->paint(e->Graphics);
            }
        }

        for each (Object ^ obj in this->toDelete)
        {
            this->logic_widgets->Remove(obj);
            this->signal_widgets->Remove(obj);
        }

        toDelete->Clear();

    }

    void MainForm_MouseDown(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {
        this->grabbed_widget = checkWidgetHit(e->Location);

        // if the mouse was over a widget, save it's old location
        if (grabbed_widget)
        {
            this->grabbed_widget_location = this->grabbed_widget->getLocation();
        }

        this->mouse_down_location = e->Location;
    }

    void MainForm_MouseMove(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {
        if (grabbed_widget && !(grabbed_widget->selected) )
        {

            move_widget( gcnew Point( e->X, e->Y ) );

        }
    }

private: System::Void MainForm_KeyUp(System::Object ^  sender, System::Windows::Forms::KeyEventArgs ^  e)
    {
        if (selected_widget)
        {
            selected_widget->keyUp(e, toolStripStatusLabel1);

            if (selected_widget->isDestructed())
            {
                logic_widgets->Remove(selected_widget);
                selected_widget = nullptr;
            }
        }

        repaint();
    }
private: System::Void toolStripButton9_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        for each (SignalWidget ^ sw in signal_widgets)
        {
            sw->transmit();
        }

        repaint();
    }
};
}
