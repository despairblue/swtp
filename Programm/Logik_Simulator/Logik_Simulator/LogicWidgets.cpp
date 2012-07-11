#pragma once

#include "stdafx.h"

#include "LogicWidgets.h"

using namespace System::Windows::Forms;
using namespace LogicWidgets;

// NOTE: LogicWidget

LogicWidget::LogicWidget( String ^ type, Point ^ location, Gatter ^ gate, Int32 id )
{
    this->size = gcnew Size(40, 40);
    this->selected = false;
    this->destructed = false;

    this->type = type;
    this->setLocation(location);
    this->gate = gate;
    this->id = id;
}

void LogicWidget::setID(Int32 id)
{
    this->id = id;
}

Int32 LogicWidget::getID()
{
    return id;
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
    // TODO: override paint for nor, nand and fork gates
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

    this->inputSignalOneLocation.X = (float) this->location->X ;
    this->inputSignalOneLocation.Y = (float) (this->location->Y + (this->size->Height / 3));

    this->inputSignalTwoLocation.X = (float) this->location->X ;
    this->inputSignalTwoLocation.Y = (float) (this->location->Y + (this->size->Height / 3) * 2);

    this->outputSignalLocation.X = (float) (this->location->X + this->size->Width);
    this->outputSignalLocation.Y = (float) (this->location->Y + (this->size->Height / 2));
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

Boolean LogicWidget::widgetHit(Point ^ clickLocation)
{
    if ( ( clickLocation->X >= this->location->X ) && ( clickLocation->X  <= this->location->X + this->size->Width ) )
    {
        if ( ( clickLocation->Y >= this->location->Y ) && ( clickLocation->Y <= this->location->Y  + this->size->Height ) )
        {
            return true;
        }
    }

    return false;
}

// NOTE: SignalWidget

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

        PointF stop;
        if (this->connectedToInput == 1)
        {
            stop = outputGate->inputSignalOneLocation;
        }
        else
        {
            stop = outputGate->inputSignalTwoLocation;
        }

        canvas->DrawLine(pen, inputGate->outputSignalLocation, stop);
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

LogicWidget ^ SignalWidget::getInputGate()
{
    return inputGate;
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

LogicWidget ^ SignalWidget::getOutputGate()
{
    return outputGate;
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
    LogicWidget(type, location, gate, id)
{
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
        canvas->DrawString("In:\n" + id.ToString(), font, sb,
                           (float)(location->X + 3), (float)(location->Y) + 3);
    }
}

Boolean InputWidget::keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar)
{
    Boolean handled = LogicWidget::keyUp(e, statusBar);

    if ( !handled )
    {
        if ( (e->KeyCode == Keys::NumPad0) || (e->KeyCode == Keys::D0) )
        {
            gate->setInputValue(false);
            statusBar->Text = "Input set to false";

            return true;
        }
        else if ( (e->KeyCode == Keys::NumPad1) || (e->KeyCode == Keys::D1) )
        {
            gate->setInputValue(true);
            statusBar->Text = "Input set to true";

            return true;
        }
    }

    return false;
}

void InputWidget::click(ToolStripStatusLabel ^ statusBar)
{
    LogicWidget::click(statusBar);

    statusBar->Text = "Press 1 or 0 to toggle state. Press Delete to remove. Drag to another Widget to connect.";
}

// NOTE: OutputWidget

OutputWidget::OutputWidget(String ^ type, Point ^ location, Output ^ gate, Int32 id):
    LogicWidget(type, location, gate, id)
{
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
        }
        else
        {
            color = Color::Black;
        }

        Pen ^ pen = gcnew Pen(color, 2.0);
        Font ^ font = gcnew Font(FontFamily::GenericMonospace, 10);
        SolidBrush ^ sb = gcnew SolidBrush(color);

        canvas->DrawRectangle(pen, location->X, location->Y,
                              this->size->Width, this->size->Height);

        canvas->DrawString("Out\n:" + id.ToString(), font, sb,
                           (float)(location->X + 3),
                           (float)(location->Y) + 3);

    }
}

// NOTE: NotWidget

NotWidget::NotWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id):
    LogicWidget(type, location, gate, id)
{
}

Boolean NotWidget::connectInputSignalTwo(SignalWidget ^ sw)
{
    return false;
}

void NotWidget::paint(Graphics ^ canvas)
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

        canvas->DrawRectangle(pen,
                              location->X, location->Y,
                              this->size->Width, this->size->Height);

        canvas->DrawEllipse(pen, this->outputSignalLocation.X, this->outputSignalLocation.Y - 3, 6.0, 6.0);

        canvas->DrawString("1" , font, sb,
                           (float)(location->X + 3),
                           (float)(location->Y + 3));

    }
}

// NOTE: NandWidget

NandWidget::NandWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id):
    LogicWidget(type, location, gate, id)
{
}

void NandWidget::paint(Graphics ^ canvas)
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

        canvas->DrawEllipse(pen, this->outputSignalLocation.X, this->outputSignalLocation.Y - 3, 6.0, 6.0);

        canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
    }
}

// NOTE: NorWidget

NorWidget::NorWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id):
    LogicWidget(type, location, gate, id)
{
}

void NorWidget::paint(Graphics ^ canvas)
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

        canvas->DrawEllipse(pen, this->outputSignalLocation.X, this->outputSignalLocation.Y - 3, 6.0, 6.0);

        canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
    }
}

ForkWidget::ForkWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id):
    LogicWidget(type, location, gate, id)
{
    this->outputSignals = gcnew array < SignalWidget ^ > (2);
}

Boolean ForkWidget::connectInputSignalTwo(SignalWidget ^ sw)
{
    return false;
}

Boolean ForkWidget::connectOutputSignal(SignalWidget ^ sw)
{
    if ( !(outputSignals[0]) || outputSignals[0]->isDestructed() )
    {
        outputSignals[0] = sw;
        return true;
    }
    if ( !(outputSignals[1]) || outputSignals[0]->isDestructed() )
    {
        outputSignals[1] = sw;
        return true;
    }

    return false;
}

void ForkWidget::disconnectOutputSignal(SignalWidget ^ sw)
{
    if (outputSignals[0] == sw)
    {
        outputSignals[0] = nullptr;
    }
    else if (outputSignals[1] == sw)
    {
        outputSignals[1] = nullptr;
    }
}

// void ForkWidget::paint(Graphics ^ canvas)
// {
//     if ( !destructed )
//     {
//         Color color;

//         if (selected)
//         {
//             color = Color::Blue;
//         }
//         else if (gate->getResult())
//         {
//             color = Color::Red;
//         }
//         else
//         {
//             color = Color::Black;
//         }

//         Pen ^ pen = gcnew Pen(color, 2.0);
//         Font ^ font = gcnew Font(FontFamily::GenericMonospace, 10);
//         SolidBrush ^ sb = gcnew SolidBrush(color);

//         canvas->DrawRectangle(pen, location->X, location->Y, this->size->Width, this->size->Height);
//         canvas->DrawString(type, font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
//     }
// }
