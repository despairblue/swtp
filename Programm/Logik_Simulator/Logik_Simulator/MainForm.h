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
#include "Fork.h"
#include "TableMap.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Text;
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

        this->Focus();

        this->toolStripButtons = gcnew ArrayList();
        this->logic_widgets = gcnew ArrayList();
        this->signal_widgets = gcnew ArrayList();
        this->toDelete = gcnew ArrayList();
        this->inputMap = gcnew ArrayList();
        this->outputMap = gcnew ArrayList();

        this->mouse_down_location.X = 0;
        this->mouse_down_location.Y = 0;

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
    Point mouse_down_location;
    Point grabbed_widget_location;
    ArrayList ^ toolStripButtons;
    ArrayList ^ logic_widgets;
    ArrayList ^ signal_widgets;
    ArrayList ^ toDelete;
    ArrayList ^ inputMap;
    ArrayList ^ outputMap;

public:

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



private: System::Windows::Forms::PictureBox ^  pictureBox1;



private: System::Windows::Forms::DataGridViewCheckBoxColumn ^  Header;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton10;

private: System::Windows::Forms::ToolStripButton ^  toolStripButton11;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton12;
private: System::Windows::Forms::OpenFileDialog ^  openFileDialog1;
private: System::Windows::Forms::SaveFileDialog ^  saveFileDialog1;


private: System::Windows::Forms::ToolStripButton ^  toolStripButton13;
private: System::Windows::Forms::ToolStripSeparator ^  toolStripSeparator4;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton14;
private: System::Windows::Forms::ToolStripButton ^  toolStripButton15;
private: System::Windows::Forms::SaveFileDialog ^  saveFileDialog2;
private: System::Windows::Forms::OpenFileDialog ^  openFileDialog2;
private: System::Windows::Forms::SaveFileDialog ^  saveFileDialog3;





private: System::ComponentModel::IContainer ^  components;
protected:

protected:


private:
    /// <summary>
    /// Erforderliche Designervariable.
    /// </summary>


    #pragma region Windows Form Designer generated code
    /// <summary>
    /// </summary>
    void InitializeComponent(void)
    {
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
		this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
		this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton10 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripButton7 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton8 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripButton9 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton11 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton12 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripSeparator4 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripButton13 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton14 = (gcnew System::Windows::Forms::ToolStripButton());
		this->toolStripButton15 = (gcnew System::Windows::Forms::ToolStripButton());
		this->statusStrip1 = (gcnew System::Windows::Forms::StatusStrip());
		this->toolStripStatusLabel1 = (gcnew System::Windows::Forms::ToolStripStatusLabel());
		this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
		this->Header = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
		this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
		this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
		this->saveFileDialog2 = (gcnew System::Windows::Forms::SaveFileDialog());
		this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
		this->saveFileDialog3 = (gcnew System::Windows::Forms::SaveFileDialog());
		this->toolStrip1->SuspendLayout();
		this->statusStrip1->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
		this->SuspendLayout();
		// 
		// toolStrip1
		// 
		this->toolStrip1->ImageScalingSize = System::Drawing::Size(24, 24);
		this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(18) {this->toolStripButton1, 
			this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton5, this->toolStripButton6, this->toolStripButton10, 
			this->toolStripSeparator1, this->toolStripButton7, this->toolStripButton8, this->toolStripSeparator2, this->toolStripButton9, 
			this->toolStripButton11, this->toolStripButton12, this->toolStripSeparator4, this->toolStripButton13, this->toolStripButton14, 
			this->toolStripButton15});
		this->toolStrip1->Location = System::Drawing::Point(0, 0);
		this->toolStrip1->Name = L"toolStrip1";
		this->toolStrip1->Size = System::Drawing::Size(681, 31);
		this->toolStrip1->TabIndex = 2;
		this->toolStrip1->Text = L"toolStrip1";
		// 
		// toolStripButton1
		// 
		this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton1->Name = L"toolStripButton1";
		this->toolStripButton1->Size = System::Drawing::Size(36, 28);
		this->toolStripButton1->Tag = L"1";
		this->toolStripButton1->Text = L"AND";
		this->toolStripButton1->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton2
		// 
		this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton2->Name = L"toolStripButton2";
		this->toolStripButton2->Size = System::Drawing::Size(27, 28);
		this->toolStripButton2->Tag = L"2";
		this->toolStripButton2->Text = L"OR";
		this->toolStripButton2->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton3
		// 
		this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton3->Name = L"toolStripButton3";
		this->toolStripButton3->Size = System::Drawing::Size(36, 28);
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
		this->toolStripButton4->Size = System::Drawing::Size(34, 28);
		this->toolStripButton4->Tag = L"4";
		this->toolStripButton4->Text = L"XOR";
		this->toolStripButton4->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton5
		// 
		this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton5->Name = L"toolStripButton5";
		this->toolStripButton5->Size = System::Drawing::Size(36, 28);
		this->toolStripButton5->Tag = L"5";
		this->toolStripButton5->Text = L"NOR";
		this->toolStripButton5->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton6
		// 
		this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton6->Name = L"toolStripButton6";
		this->toolStripButton6->Size = System::Drawing::Size(45, 28);
		this->toolStripButton6->Tag = L"6";
		this->toolStripButton6->Text = L"NAND";
		this->toolStripButton6->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton10
		// 
		this->toolStripButton10->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton10->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton10->Name = L"toolStripButton10";
		this->toolStripButton10->Size = System::Drawing::Size(34, 28);
		this->toolStripButton10->Tag = L"9";
		this->toolStripButton10->Text = L"Fork";
		this->toolStripButton10->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripSeparator1
		// 
		this->toolStripSeparator1->Name = L"toolStripSeparator1";
		this->toolStripSeparator1->Size = System::Drawing::Size(6, 31);
		// 
		// toolStripButton7
		// 
		this->toolStripButton7->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton7->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton7->Name = L"toolStripButton7";
		this->toolStripButton7->Size = System::Drawing::Size(39, 28);
		this->toolStripButton7->Tag = L"7";
		this->toolStripButton7->Text = L"Input";
		this->toolStripButton7->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripButton8
		// 
		this->toolStripButton8->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripButton8->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton8->Name = L"toolStripButton8";
		this->toolStripButton8->Size = System::Drawing::Size(49, 28);
		this->toolStripButton8->Tag = L"8";
		this->toolStripButton8->Text = L"Output";
		this->toolStripButton8->Click += gcnew System::EventHandler(this, &MainForm::toolStripButtons_Click);
		// 
		// toolStripSeparator2
		// 
		this->toolStripSeparator2->Name = L"toolStripSeparator2";
		this->toolStripSeparator2->Size = System::Drawing::Size(6, 31);
		// 
		// toolStripButton9
		// 
		this->toolStripButton9->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton9->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton9.Image")));
		this->toolStripButton9->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton9->Name = L"toolStripButton9";
		this->toolStripButton9->Size = System::Drawing::Size(28, 28);
		this->toolStripButton9->Tag = L"9";
		this->toolStripButton9->Text = L"Start Simulation";
		this->toolStripButton9->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton9_Click);
		// 
		// toolStripButton11
		// 
		this->toolStripButton11->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton11->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton11.Image")));
		this->toolStripButton11->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton11->Name = L"toolStripButton11";
		this->toolStripButton11->Size = System::Drawing::Size(28, 28);
		this->toolStripButton11->Text = L"Open";
		this->toolStripButton11->ToolTipText = L"Open Circiut";
		this->toolStripButton11->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton11_Click);
		// 
		// toolStripButton12
		// 
		this->toolStripButton12->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton12->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton12.Image")));
		this->toolStripButton12->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton12->Name = L"toolStripButton12";
		this->toolStripButton12->Size = System::Drawing::Size(28, 28);
		this->toolStripButton12->Text = L"Save";
		this->toolStripButton12->ToolTipText = L"Save Circiut";
		this->toolStripButton12->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton12_Click);
		// 
		// toolStripSeparator4
		// 
		this->toolStripSeparator4->Name = L"toolStripSeparator4";
		this->toolStripSeparator4->Size = System::Drawing::Size(6, 31);
		// 
		// toolStripButton13
		// 
		this->toolStripButton13->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton13->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton13.Image")));
		this->toolStripButton13->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton13->Name = L"toolStripButton13";
		this->toolStripButton13->Size = System::Drawing::Size(28, 28);
		this->toolStripButton13->Text = L"toolStripButton13";
		this->toolStripButton13->ToolTipText = L"Input Table Simulation";
		this->toolStripButton13->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton13_Click);
		// 
		// toolStripButton14
		// 
		this->toolStripButton14->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton14->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton14.Image")));
		this->toolStripButton14->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton14->Name = L"toolStripButton14";
		this->toolStripButton14->Size = System::Drawing::Size(28, 28);
		this->toolStripButton14->Text = L"toolStripButton14";
		this->toolStripButton14->ToolTipText = L"Load Input Table";
		this->toolStripButton14->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton14_Click);
		// 
		// toolStripButton15
		// 
		this->toolStripButton15->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
		this->toolStripButton15->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"toolStripButton15.Image")));
		this->toolStripButton15->ImageTransparentColor = System::Drawing::Color::Magenta;
		this->toolStripButton15->Name = L"toolStripButton15";
		this->toolStripButton15->Size = System::Drawing::Size(28, 28);
		this->toolStripButton15->Text = L"toolStripButton15";
		this->toolStripButton15->ToolTipText = L"Save Input Table";
		this->toolStripButton15->Click += gcnew System::EventHandler(this, &MainForm::toolStripButton15_Click);
		// 
		// statusStrip1
		// 
		this->statusStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->toolStripStatusLabel1});
		this->statusStrip1->Location = System::Drawing::Point(0, 350);
		this->statusStrip1->Name = L"statusStrip1";
		this->statusStrip1->Size = System::Drawing::Size(681, 22);
		this->statusStrip1->TabIndex = 3;
		this->statusStrip1->Text = L"statusStrip1";
		// 
		// toolStripStatusLabel1
		// 
		this->toolStripStatusLabel1->AutoToolTip = true;
		this->toolStripStatusLabel1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Text;
		this->toolStripStatusLabel1->Name = L"toolStripStatusLabel1";
		this->toolStripStatusLabel1->Size = System::Drawing::Size(666, 17);
		this->toolStripStatusLabel1->Spring = true;
		this->toolStripStatusLabel1->Text = L"Select a Gate from the tool bar.";
		this->toolStripStatusLabel1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
		// 
		// pictureBox1
		// 
		this->pictureBox1->BackColor = System::Drawing::SystemColors::Window;
		this->pictureBox1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pictureBox1->Location = System::Drawing::Point(0, 31);
		this->pictureBox1->Name = L"pictureBox1";
		this->pictureBox1->Size = System::Drawing::Size(681, 319);
		this->pictureBox1->TabIndex = 0;
		this->pictureBox1->TabStop = false;
		this->pictureBox1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseMove);
		this->pictureBox1->Click += gcnew System::EventHandler(this, &MainForm::pictureBox1_Click);
		this->pictureBox1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseDown);
		this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MainForm::MainForm_Paint);
		this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);
		// 
		// Header
		// 
		this->Header->Name = L"Header";
		// 
		// openFileDialog1
		// 
		this->openFileDialog1->DefaultExt = L"knorkator";
		this->openFileDialog1->FileName = L"openFileDialog1";
		this->openFileDialog1->Filter = L"Logik Simulator files|*.knorkator";
		this->openFileDialog1->Title = L"What u want open\?";
		// 
		// saveFileDialog1
		// 
		this->saveFileDialog1->DefaultExt = L"knorkator";
		this->saveFileDialog1->Filter = L"\"Logik Simulator files|*.knorkator";
		this->saveFileDialog1->Title = L"Where u want save\?";
		// 
		// saveFileDialog2
		// 
		this->saveFileDialog2->DefaultExt = L"otto";
		this->saveFileDialog2->Filter = L"Input Table files|*.otto";
		this->saveFileDialog2->Title = L"Where u want save\?";
		// 
		// openFileDialog2
		// 
		this->openFileDialog2->DefaultExt = L"otto";
		this->openFileDialog2->FileName = L"openFileDialog2";
		this->openFileDialog2->Filter = L"Input Table files|*.otto";
		this->openFileDialog2->Title = L"What u want open\?";
		// 
		// saveFileDialog3
		// 
		this->saveFileDialog3->DefaultExt = L"ottoput";
		this->saveFileDialog3->Filter = L"Output Table files|*.ottoput";
		this->saveFileDialog3->Title = L"Where u want save\?";
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(681, 372);
		this->Controls->Add(this->pictureBox1);
		this->Controls->Add(this->statusStrip1);
		this->Controls->Add(this->toolStrip1);
		this->DoubleBuffered = true;
		this->Name = L"MainForm";
		this->Text = L"MainForm";
		this->KeyUp += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::MainForm_KeyUp);
		this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::splitContainer1_KeyDown);
		this->toolStrip1->ResumeLayout(false);
		this->toolStrip1->PerformLayout();
		this->statusStrip1->ResumeLayout(false);
		this->statusStrip1->PerformLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
		this->ResumeLayout(false);
		this->PerformLayout();

	}
    #pragma endregion

private:
    /**
        Change status bar text.
        @param text new status bar text
    */
    void changeStatusBar(String ^ text)
    {
        this->toolStripStatusLabel1->Text = text;
    }

    /**
        Iterate over logic_widgets and calls LogicWidget::widgetHit()
        for every LogicWidget.
        @return the first LogicWidget that was hit by the mouse click.
    */
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

    /**
        Moves the selected_widget to the specified location.
        @param location Location to move to
    */
    void move_widget(Point ^ location)
    {
        if (grabbed_widget)
        {
            int x_diff = location->X - this->mouse_down_location.X;
            int y_diff = location->Y - this->mouse_down_location.Y;

            Point new_loc = Point(grabbed_widget_location.X + x_diff, grabbed_widget_location.Y + y_diff);

            grabbed_widget->setLocation(new_loc);

            repaint();
        }
    }

    /// Invalidates and Updates the form.
    void repaint()
    {
        pictureBox1->Invalidate();
        pictureBox1->Update();
    }

    /**
        Returns an ID that is unique for the current circuit.
        @return ID as Int32
    */
    Int32 createID()
    {
        Int32 result = 0;

        for each (LogicWidget ^ lw in logic_widgets)
        {
            if (lw->getID() > result)
            {
                result = lw->getID();
            }
        }

        result++;

        return result;
    }

    /**
        Returns the LogicWidget with the given ID or nullptr.
        @param id ID as Int32
        @return LogicWidget with the corresponding ID.
    */
    LogicWidget ^ getWidgetByID(Int32 id)
    {
        for each (LogicWidget ^ lw in logic_widgets)
        {
            if (lw->getID() == id)
            {
                return lw;
            }
        }

        return nullptr;
    }

    /**
        Checks the given ToolStripButton and unchecks all others.
        @param checkBtn ToolStripButton to check or nullptr to uncheck all
        @return True if succeeded, otherwise false.
    */
    Boolean checkButton(ToolStripButton ^ checkBtn)
    {

        for each (ToolStripButton ^ btn in toolStripButtons)
        {
            btn->Checked = false;
        }

        if (checkBtn == nullptr)
        {
            return true;
        }
        else
        {
            for each (ToolStripButton ^ btn in toolStripButtons)
            {
                if (btn == checkBtn)
                {
                    btn->Checked = true;
                    return true;
                }
            }
            return false;
        }
    }

    /**
        Starts the simulation.
        @param deselectWidgets If true all widgets and buttons will be deselected
    */
    void startSimulation(Boolean deselectWidgets)
    {
        Boolean simulated = false;

        if (deselectWidgets)
        {
            checkButton(nullptr);

            if (selected_widget)
            {
                selected_widget->selected = false;
                selected_widget = nullptr;
            }
        }

        for each (SignalWidget ^ sw in signal_widgets)
        {
            if (sw->transmit())
            {
                simulated = true;
            }
        }

        if (simulated)
        {
            changeStatusBar("Simulation started.");
        }
        else
        {
            changeStatusBar("No simulation started. Add some Inputs and connect them to Gates.");
        }

        repaint();
    }

    /**
        Destructs all LogicWidget instances in logic_widgets and
        all SignalWidget instances in signal_widgets and calls
        repaint();
    */
    void cleanCanvas()
    {
        for each (LogicWidget ^ lw in logic_widgets)
        {
            lw->destruct();
        }

        for each (SignalWidget ^ sw in signal_widgets)
        {
            sw->destruct();
        }

        logic_widgets->Clear();
        signal_widgets->Clear();
        selected_widget = nullptr;

        repaint();
    }

    /**
        EventHandler for the Buttons in the Toolbar.
        set which Type of Gate is selected
    */
    void toolStripButtons_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        ToolStripButton ^ sen = safe_cast < ToolStripButton ^ > (sender);
        Boolean new_state = !(sen->Checked);

        if (sen->Checked)
        {
            checkButton(nullptr);
            changeStatusBar("Select a Gate from the tool bar.");
        }
        else
        {
            checkButton(sen);
            changeStatusBar("Click anywhere on the canvas to place the Gate.");
        }
    }

    /**
        EventHandler for MouseUp Event
        creates (depending on MouseDown) a new Widget,
        or moves a Widget,
        or cutes a Signal
    */
    void MainForm_MouseUp(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {
        Control ^ control = dynamic_cast < Control ^ > (sender);

        Boolean sameLocation = ( (mouse_down_location.X == e->X) && (mouse_down_location.Y == e->Y) );
        Boolean controlKeyDown = Control::ModifierKeys == Keys::Control;

        if (grabbed_widget)
        {
            // MouseDown inside of a Widget, might be drag 'n drop or click

            if (sameLocation)
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

                        SignalWidget ^ sw = gcnew SignalWidget();
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
            if ( sameLocation )
            {
                //MouseDown outside of a Widget and in the same location as mouseup -> create a widget here

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
                        lw = gcnew AndWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 2:
                        gate = gcnew Or();
                        lw = gcnew OrWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 3:
                        gate = gcnew Not();
                        lw = gcnew NotWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 4:
                        gate = gcnew Exor();
                        lw = gcnew ExorWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 5:
                        gate = gcnew Nor();
                        lw = gcnew NorWidget( gcnew Point(e->X, e->Y), createID());
                        break;
                    case 6:
                        gate = gcnew Nand();
                        lw = gcnew NandWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 7:
                        gate = gcnew Input();
                        lw = gcnew InputWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 8:
                        gate = gcnew Output();
                        lw = gcnew OutputWidget(gcnew Point(e->X, e->Y), createID());
                        break;
                    case 9:
                        gate = gcnew Fork();
                        lw = gcnew ForkWidget(gcnew Point(e->X, e->Y), createID());
                    }
                    this->logic_widgets->Insert(0, lw);

                }
            }
            else if ( controlKeyDown )
            {
                // MouseUp in different location than mouse down and control key pressed -> cut tool

                for each (SignalWidget ^ sw in signal_widgets)
                {
                    if (sw->signalCut(mouse_down_location, control->PointToClient(control->MousePosition)))
                    {
                        sw->destruct();
                    }
                    else
                    {
                        changeStatusBar("No Signal cut.");
                    }
                }

            }
        }

        repaint();
    }



    /// Draws the Line for the Cut-Tool and Refreshes the Canvas
    void MainForm_Paint(System::Object ^  sender, System::Windows::Forms::PaintEventArgs ^  e)
    {
        Control ^ control = dynamic_cast < Control ^ > (sender);
        Pen ^ pen = gcnew Pen(Color::Orange);
        Boolean controlKeyDown = Control::ModifierKeys == Keys::Control;
        Boolean leftMouseButtonDown = Control::MouseButtons == ::MouseButtons::Left;

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

        if ( controlKeyDown && leftMouseButtonDown )
        {
            Point endPoint = control->PointToClient(control->MousePosition);

            e->Graphics->DrawLine(pen, mouse_down_location.X, mouse_down_location.Y, endPoint.X, endPoint.Y);
        }
    }

    ///safes the current Position if the mouse was over a widget
    void MainForm_MouseDown(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {
        this->mouse_down_location = e->Location;
        this->grabbed_widget = checkWidgetHit(e->Location);

        // if the mouse was over a widget, save it's old location
        if (grabbed_widget)
        {
            this->grabbed_widget_location.X = this->grabbed_widget->getLocation()->X;
            this->grabbed_widget_location.Y = this->grabbed_widget->getLocation()->Y;
        }
    }

    ///moves a Widget, if its not selected, or draw a SignalWidget
    void MainForm_MouseMove(System::Object ^  sender, System::Windows::Forms::MouseEventArgs ^  e)
    {
        Boolean controlKeyDown = Control::ModifierKeys == Keys::Control;
        Boolean leftMouseButtonDown = Control::MouseButtons == ::MouseButtons::Left;

        if (grabbed_widget && !(grabbed_widget->selected) )
        {
            // only if an unselected widget is grabbed
            if (controlKeyDown)
            {
                // undo move and grabbing if control is pressed
                move_widget(grabbed_widget_location);
                grabbed_widget = nullptr;
            }
            else
            {
                // else move it
                move_widget( gcnew Point( e->X, e->Y ) );
            }
        }
        if ( controlKeyDown && leftMouseButtonDown )
        {
            repaint();
        }
    }

    /**
        deletes a Widget on Delete Key Press
        if Widget is selected
    */
private: System::Void MainForm_KeyUp(System::Object ^  sender, System::Windows::Forms::KeyEventArgs ^  e)
    {
        Boolean handled = false;

        if (Control::ModifierKeys != Keys::Control)
        {
            pictureBox1->Cursor = Cursors::Default;
        }

        if (selected_widget)
        {
            handled = selected_widget->keyUp(e, toolStripStatusLabel1);

            if (selected_widget->isDestructed())
            {

                logic_widgets->Remove(selected_widget);

                selected_widget = nullptr;

            }
        }

        if ( !handled )
        {
            if (e->KeyCode == Keys::Enter)
            {
                startSimulation(true);
            }
        }
        else if (e->KeyCode == Keys::Delete)
        {
            changeStatusBar("No Gate selected. Select the Gate you want to remove.");
        }

        repaint();
    }

    ///starts the Single-Row Simulation
private: System::Void toolStripButton9_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        // TODO: multi output implemt
        startSimulation(true);
    }
    ///opens a SafeFileDialog and Write the Circuit to the Harddisc
private: System::Void toolStripButton12_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        Stream ^ myStream;

        if ( saveFileDialog1->ShowDialog() == ::DialogResult::OK )
        {
            if ( (myStream = saveFileDialog1->OpenFile()) != nullptr )
            {
                StringBuilder ^ file = gcnew StringBuilder();

                for each (LogicWidget ^ lw in logic_widgets)
                {
                    StringBuilder ^ line = gcnew StringBuilder();

                    line->Append("Gate");
                    line->Append(",");
                    line->Append(lw->GetType()->ToString());
                    line->Append(",");
                    line->Append(lw->getID());
                    line->Append(",");
                    line->Append(lw->getLocation()->X);
                    line->Append(",");
                    line->Append(lw->getLocation()->Y);

                    file->Append(line->ToString());
                    file->Append("\n");
                }

                for each (SignalWidget ^ sw in signal_widgets)
                {
                    StringBuilder ^ line = gcnew StringBuilder();

                    line->Append("Signal");
                    line->Append(",");
                    line->Append(sw->getInputGate()->getID());
                    line->Append(",");
                    line->Append(sw->getOutputGate()->getID());

                    file->Append(line->ToString());
                    file->Append("\n");
                }

                StreamWriter ^ fileWriter = gcnew StreamWriter(myStream);

                fileWriter->Write(file->ToString());

                fileWriter->Close();
                myStream->Close();
            }
        }

    }

    ///opens a OpenFileDialog and  the Circuit from the Harddisc
private: System::Void toolStripButton11_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        Stream ^ myStream;

        // workaround for the weird doubleclick behaviour of the OpenFileDialog
        this->pictureBox1->MouseUp -= gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);

        if ( openFileDialog1->ShowDialog() == ::DialogResult::OK )
        {
            if ( (myStream = openFileDialog1->OpenFile()) != nullptr )
            {
                cleanCanvas();

                StreamReader ^ fileReader = gcnew StreamReader(myStream);
                String ^ fileContent = fileReader->ReadToEnd();
                LogicWidget ^ lw;
                SignalWidget ^ sw;


                for each (String ^ line in fileContent->Split('\n'))
                {
                    array < String ^ > ^ seperatedLine = line->Split(',');

                    if (seperatedLine->GetLength(0) > 0)
                    {
                        if (seperatedLine[0] == "Gate")
                        {
                            if (seperatedLine[1] == "LogicWidgets.AndWidget")
                            {
                                lw = gcnew AndWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                 Convert::ToInt32(seperatedLine[4])),
                                                     Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.OrWidget")
                            {
                                lw = gcnew OrWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                Convert::ToInt32(seperatedLine[4])),
                                                    Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.NandWidget")
                            {
                                lw = gcnew NandWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                  Convert::ToInt32(seperatedLine[4])),
                                                      Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.NorWidget")
                            {
                                lw = gcnew NorWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                 Convert::ToInt32(seperatedLine[4])),
                                                     Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.NotWidget")
                            {
                                lw = gcnew NotWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                 Convert::ToInt32(seperatedLine[4])),
                                                     Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.ExorWidget")
                            {
                                lw = gcnew ExorWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                  Convert::ToInt32(seperatedLine[4])),
                                                      Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.InputWidget")
                            {
                                lw = gcnew InputWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                   Convert::ToInt32(seperatedLine[4])),
                                                       Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.OutputWidget")
                            {
                                lw = gcnew OutputWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                    Convert::ToInt32(seperatedLine[4])),
                                                        Convert::ToInt32(seperatedLine[2]));
                            }
                            else if (seperatedLine[1] == "LogicWidgets.ForkWidget")
                            {
                                lw = gcnew ForkWidget(gcnew Point(Convert::ToInt32(seperatedLine[3]),
                                                                  Convert::ToInt32(seperatedLine[4])),
                                                      Convert::ToInt32(seperatedLine[2]));
                            }

                        }
                        else if (seperatedLine[0] == "Signal")
                        {
                            sw = gcnew SignalWidget();

                            sw->setInputGate( getWidgetByID( Convert::ToInt32( seperatedLine[1] ) ) );
                            sw->setOutputGate( getWidgetByID( Convert::ToInt32( seperatedLine[2] ) ) );
                        }
                    }

                    if (lw)
                    {
                        logic_widgets->Add(lw);
                        lw = nullptr;
                    }

                    if (sw)
                    {
                        signal_widgets->Add(sw);
                        sw = nullptr;
                    }
                }

                fileReader->Close();
                myStream->Close();
            }
        }
        // finish workaround
        Application::DoEvents();
        this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);

        repaint();
    }


    ///Change Cursor if Control-Key is Pressed
private: System::Void splitContainer1_KeyDown(System::Object ^  sender, System::Windows::Forms::KeyEventArgs ^  e)
    {
        if (Control::ModifierKeys == Keys::Control)
        {
            pictureBox1->Cursor = Cursors::Cross;
            changeStatusBar("While pressing Control you can cut Signals to remove them.");
        }
    }

private: System::Void pictureBox1_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
    }
private: System::Void toolStripButton15_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        Stream ^ myStream;

        if ( saveFileDialog2->ShowDialog() == ::DialogResult::OK )
        {
            if ( (myStream = saveFileDialog2->OpenFile()) != nullptr )
            {
                StringBuilder ^ file = gcnew StringBuilder();

                for each (LogicWidget ^ lw in logic_widgets)
                {
                    if (lw->GetType() == InputWidget::typeid)
                    {
                        file->Append(lw->getGate()->getResult());
                        file->Append(",");
                    }
                }

                // Remove last comma
                if (file->Length > 0)
                {
                    file->Remove(file->Length - 1, 1);
                }

                file->Append("\n");

                StreamWriter ^ fileWriter = gcnew StreamWriter(myStream);

                fileWriter->Write(file->ToString());

                fileWriter->Close();
                myStream->Close();
            }
        }
    }
private: System::Void toolStripButton14_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        inputMap->Clear();

        Stream ^ myStream;

        // workaround for the weird doubleclick behaviour of the OpenFileDialog
        this->pictureBox1->MouseUp -= gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);

        if ( openFileDialog2->ShowDialog() == ::DialogResult::OK )
        {
            if ( (myStream = openFileDialog2->OpenFile()) != nullptr )
            {
                StreamReader ^ fileReader = gcnew StreamReader(myStream);
                //String ^ fileContent = fileReader->ReadToEnd();
                String ^ line;

                inputMap = gcnew ArrayList();

                while (line = fileReader->ReadLine())
                {
                    array < String ^ > ^ seperatedLine = line->Split(',');

                    if (seperatedLine->GetLength(0) > 0)
                    {
                        ArrayList ^ temp = gcnew ArrayList();

                        for each (String ^ part in seperatedLine)
                        {
                            temp->Add(Convert::ToBoolean( part));
                        }

                        inputMap->Add(temp);
                    }
                }

                fileReader->Close();
                myStream->Close();

            }
        }
        // finish workaround
        Application::DoEvents();
        this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::MainForm_MouseUp);

        repaint();
    }

private: System::Void toolStripButton13_Click(System::Object ^  sender, System::EventArgs ^  e)
    {
        ArrayList ^ inputs = gcnew ArrayList();
        ArrayList ^ outputs = gcnew ArrayList();

        for each (LogicWidget ^ lw in logic_widgets)
        {
            if (lw->GetType() == InputWidget::typeid)
            {
                inputs->Add(lw);
            }
            else if (lw->GetType() == OutputWidget::typeid)
            {
                outputs->Add(lw);
            }
        }

        outputMap->Clear();

        for ( int h = 0; h < inputMap->Count; h++)
        {
            for (int i = 0; i < inputs->Count; i++)
            {
                if ( ((ArrayList ^ ) inputMap[h])->Count > i)
                {
                    ((LogicWidget ^ )inputs[i])->getGate()->setResult( (bool) ((ArrayList ^ )inputMap[h])[i]);
                }
                else
                {
                    ((LogicWidget ^ )inputs[i])->getGate()->setResult(false);
                }
            }

            startSimulation(true);

            ArrayList ^ temp = gcnew ArrayList();

            for each (LogicWidget ^ lw in outputs)
            {
                temp->Add(lw->getGate()->getResult());
            }

            outputMap->Add(temp);
        }
        Stream ^ myStream;

        if ( saveFileDialog3->ShowDialog() == ::DialogResult::OK )
        {
            if ( (myStream = saveFileDialog3->OpenFile()) != nullptr )
            {
                StringBuilder ^ file = gcnew StringBuilder();

                for each (ArrayList ^ al in outputMap)
                {
                    for each (Boolean boo in al)
                    {
                        file->Append(boo);
                        file->Append(",");
                    }

                    // Remove last comma
                    if (file->Length > 0)
                    {
                        file->Remove(file->Length - 1, 1);
                    }

                    file->Append("\n");
                }

                StreamWriter ^ fileWriter = gcnew StreamWriter(myStream);

                fileWriter->Write(file->ToString());

                fileWriter->Close();
                myStream->Close();
            }
        }

    }
};
}
