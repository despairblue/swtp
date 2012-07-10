#pragma once

#include "stdafx.h"

#include "LogicWidgets.h"

using namespace System::Windows::Forms;
using namespace LogicWidgets;

// NOTE: LogicWidget

LogicWidget::LogicWidget( String ^ type, Point ^ location, Gatter ^ _gate )
{
    this->size = gcnew Size(40, 40);
    this->selected = false;
    this->destructed = false;

    this->type = type;
    this->setLocation(location);
    this->gate = _gate;
}

LogicWidget::LogicWidget( )
{
}

void LogicWidget::destruct()
{
    this->destructed = true;
    if (this->inputSignalOne)
    {
        this->inputSignalOne->destruct();
    }
    if (this->inputSignalTwo)
    {
        this->inputSignalTwo->destruct();

    }
    if (this->outputSignal)
    {
        this->outputSignal->destruct();
    }
}

Boolean LogicWidget::isDestructed()
{
    return this->destructed;
}

void LogicWidget::paint(Graphics ^ canvas)
{
    // TODO: override paint for all particular gates
    if ( !destructed )
    {
        Color color;

        if (selected)
        {
            color = Color::Blue;
        }
        else
        {
            color = Color::Black;
        }

        Pen ^ pen = gcnew Pen(color, 2.0);
        Font ^ font = gcnew Font(FontFamily::GenericMonospace, 10);
        SolidBrush ^ sb = gcnew SolidBrush(color);

        canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
        canvas->DrawEllipse(pen, this->inputSignalOneLocation);
        canvas->DrawEllipse(pen, this->inputSignalTwoLocation);
        canvas->DrawEllipse(pen, this->outputSignalLocation);
        canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);

    }
}

Size ^ LogicWidget::getSize()
{
    return this->size;
}

Point ^ LogicWidget::getLocation()
{
    return this->location;
}

void LogicWidget::setLocation(Point ^ location)
{
    this->location = location;

    this->inputSignalOneLocation.X = this->location->X - 5;
    this->inputSignalOneLocation.Y = this->location->Y + (this->size->Height / 3) - 2;
    this->inputSignalOneLocation.Width = 5;
    this->inputSignalOneLocation.Height = 5;

    this->inputSignalTwoLocation.X = this->location->X - 5;
    this->inputSignalTwoLocation.Y = this->location->Y + (this->size->Height / 3) * 2 - 2;
    this->inputSignalTwoLocation.Width = 5;
    this->inputSignalTwoLocation.Height = 5;

    this->outputSignalLocation.X = this->location->X + this->size->Width;
    this->outputSignalLocation.Y = this->location->Y + (this->size->Height / 2) - 2;
    this->outputSignalLocation.Width = 5;
    this->outputSignalLocation.Height = 5;
}

Gatter ^ LogicWidget::getGate()
{
    return this->gate;
}

Boolean LogicWidget::connectInputSignalOne(SignalWidget ^ sw)
{

    if ( this->inputSignalOne && !( this->inputSignalOne->isDestructed() ) )
    {
        return false;
    }
    else
    {
        this->inputSignalOne = sw;
        return true;
    }

}

Boolean LogicWidget::connectInputSignalTwo(SignalWidget ^ sw)
{

    if ( this->inputSignalTwo && !( this->inputSignalTwo->isDestructed() ) )
    {
        return false;
    }
    else
    {
        this->inputSignalTwo = sw;
        return true;
    }

}

void LogicWidget::disconnectInputSignal(SignalWidget ^ sw)
{
    if (this->inputSignalOne == sw)
    {
        this->inputSignalOne = nullptr;
    }
    if (this->inputSignalTwo == sw)
    {
        this->inputSignalTwo = nullptr;
    }
}

Boolean LogicWidget::connectOutputSignal(SignalWidget ^ sw)
{

    if (this->outputSignal && !( this->outputSignal->isDestructed() ))
    {
        return false;
    }
    else
    {
        this->outputSignal = sw;
        return true;
    }

}

void LogicWidget::disconnectOutputSignal(SignalWidget ^ sw)
{
    if (this->outputSignal == sw)
    {
        this->outputSignal = nullptr;
    }
}

void LogicWidget::click(ToolStripStatusLabel ^ statusBar)
{
    if (this->selected)
    {
        this->selected = false;
        statusBar->Text = "Gate deselected. Click another Gate to select it or drag 'n drop to move Gates.";
    }
    else
    {
        this->selected = true;
        statusBar->Text = "Gate selected. Drag to another Gate to connect them. Press Delete to remove.";
    }
}

Boolean LogicWidget::keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar)
{
    if (e->KeyCode == Keys::Delete && selected)
    {
        destruct();
        statusBar->Text = "Gate removed.";

        return true;
    }
    else if (e->KeyCode == Keys::Delete)
    {
        statusBar->Text = "No Gate selected. Select the Gate you want to remove.";
        return false;
    }

    return false;
}

Boolean LogicWidget::widgetHit(Point ^ click_location)
{
    if ( ( click_location->X >= this->location->X ) && ( click_location->X  <= this->location->X + this->size->Width ) )
    {
        if ( ( click_location->Y >= this->location->Y ) && ( click_location->Y <= this->location->Y  + this->size->Height ) )
        {
            return true;
        }
    }

    return false;
}

// NOTE: SignalWidget

SignalWidget::SignalWidget(void)
{
    this->destructed = false;
}

SignalWidget::SignalWidget(Signal ^ signal)
{
    this->destructed = false;
    this->connectedToInput = 0;
    this->signal = signal;
}

void SignalWidget::destruct()
{
    this->destructed = true;
    this->disconnectAll();

    // FIX: Won't work, need a method to destruct the signal @roesti77
    // this->signal->setInputGate(nullptr, 0);
    // this->signal->addOutputGate(nullptr, 0);
}

Boolean SignalWidget::isDestructed()
{
    return this->destructed;
}

void SignalWidget::paint( Graphics ^ canvas )
{
    if ( !destructed )
    {
        Pen ^ pen;
        if (this->signal->getValue())
        {
            pen = gcnew Pen(Color::Red, 2.0);
        }
        else
        {
            pen = gcnew Pen(Color::Black, 2.0);
        }

        Point start = Point(inputGate->outputSignalLocation.X + inputGate->outputSignalLocation.Width / 2,
                            inputGate->outputSignalLocation.Y + inputGate->outputSignalLocation.Height / 2);
        Point stop;
        if (this->connectedToInput == 1)
        {
            stop = Point(outputGate->inputSignalOneLocation.X + outputGate->inputSignalOneLocation.Width / 2,
                         outputGate->inputSignalOneLocation.Y + outputGate->inputSignalOneLocation.Height / 2);
        }
        else
        {
            stop = Point(outputGate->inputSignalTwoLocation.X + outputGate->inputSignalTwoLocation.Width / 2,
                         outputGate->inputSignalTwoLocation.Y + outputGate->inputSignalTwoLocation.Height / 2);
        }

        canvas->DrawLine(pen, start, stop);
    }
}

Signal ^ SignalWidget::getSignal()
{
    return this->signal;
}

void SignalWidget::setInputGate(LogicWidget ^ lw)
{
    this->inputGate = lw;
    Boolean connected = lw->connectOutputSignal(this);

    if ( !connected )
    {
        this->destruct();
    }
    else
    {
        this->signal->setInputGate(lw->getGate(), 0);
    }
}

void SignalWidget::setOutputGate(LogicWidget ^ lw)
{
    this->outputGate = lw;
    Boolean connected = lw->connectInputSignalOne(this);

    if ( connected )
    {
        this->signal->addOutputGate(lw->getGate(), 0);
        this->connectedToInput = 1;
    }
    else
    {
        connected = lw->connectInputSignalTwo(this);

        if ( connected )
        {
            this->signal->addOutputGate(lw->getGate(), 1);
            this->connectedToInput = 2;
        }
        else
        {
            this->destruct();
        }
    }
}

void SignalWidget::disconnectAll()
{
    if (this->inputGate)
    {
        this->inputGate->disconnectOutputSignal(this);
        this->inputGate = nullptr;
    }
    if (this->outputGate)
    {
        this->outputGate->disconnectInputSignal(this);
        this->inputGate = nullptr;
    }
}

void SignalWidget::transmit()
{
    if (inputGate->GetType() == InputWidget::typeid)
    {
        signal->transmit();
    }
}

// NOTE: InputWidget

InputWidget::InputWidget(String ^ type, Point ^ location, Input ^ gate, Int32 id):
    LogicWidget(type, location, gate)
{
    this->id = id;
}

InputWidget::InputWidget(void): LogicWidget()
{
}

void InputWidget::setID(Int32 id)
{
    this->id = id;
}

Int32 InputWidget::getID()
{
    return id;
}

Boolean InputWidget::connectInputSignalOne(SignalWidget ^ sw)
{
    return false;
}

Boolean InputWidget::connectInputSignalTwo(SignalWidget ^ sw)
{
    return false;
}

void InputWidget::paint(Graphics ^ canvas)
{
    if ( !destructed )
    {
        Color color;

        if (selected)
        {
            color = Color::Blue;
        }
        else if (gate->getResult())
        {
            color = Color::Red;
        }
        else
        {
            color = Color::Black;
        }

        Pen ^ pen = gcnew Pen(color, 2.0);
        Font ^ font = gcnew Font(FontFamily::GenericMonospace, 10);
        SolidBrush ^ sb = gcnew SolidBrush(color);


        canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
        canvas->DrawEllipse(pen, this->outputSignalLocation);
        canvas->DrawString(id.ToString(), font, sb,
                           safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
    }
}

Boolean InputWidget::keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar)
{
    Boolean handled = LogicWidget::keyUp(e, statusBar);

    if ( !handled )
    {
        if (e->KeyCode == Keys::NumPad0)
        {
            gate->setInputValue(false);
            statusBar->Text = "Input set to false";

            return true;
        }
        else if (e->KeyCode == Keys::NumPad1)
        {
            gate->setInputValue(true);
            statusBar->Text = "Input set to true";

            return true;
        }
    }

    return false;
}

OutputWidget::OutputWidget(String ^ type, Point ^ location, Output ^ gate, Int32 id):
    LogicWidget(type, location, gate)
{
    this->id = id;
}

OutputWidget::OutputWidget()
{
}

Int32 OutputWidget::getID()
{
    return id;
}

void OutputWidget::setID(Int32 id)
{
    this->id = id;
}

Boolean OutputWidget::connectInputSignalTwo(SignalWidget ^ sw)
{
    return false;
}

Boolean OutputWidget::connectOutputSignal(SignalWidget ^ sw)
{
    return false;
}

void OutputWidget::paint(Graphics ^ canvas)
{
    if ( !destructed )
    {
        Color color;

        if (selected)
        {
            color = Color::Blue;
        }
		else if (gate->getResult())
        {
            color = Color::Red;
		} else {
			color = Color::Black;
		}

        Pen ^ pen = gcnew Pen(color, 2.0);
        Font ^ font = gcnew Font(FontFamily::GenericMonospace, 10);
        SolidBrush ^ sb = gcnew SolidBrush(color);

        canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
        canvas->DrawEllipse(pen, this->inputSignalOneLocation);
        canvas->DrawString(id.ToString(), font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);

    }
}
