#pragma once

#include "stdafx.h"

#include "LogicWidgets.h"

using namespace System::Windows::Forms;
using namespace LogicWidgets;

LogicWidget::LogicWidget( String ^ type, Point ^ location, Gatter ^ gate )
{
    this->size = gcnew Size(40, 40);
    this->selected = false;
    this->destructed = false;

    this->type = type;
    this->setLocation(location);
    this->gate = gate;
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

        Pen ^ pen = gcnew Pen(color);
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

    // TODO: Won't work, need a method to destruct the signal @roesti77
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
            pen = gcnew Pen(Color::Red);
        }
        else
        {
            pen = gcnew Pen(Color::Black);
        }

        if (this->connectedToInput == 1)
        {
            canvas->DrawLine(pen, inputGate->outputSignalLocation.X, inputGate->outputSignalLocation.Y, outputGate->inputSignalOneLocation.X, outputGate->inputSignalOneLocation.Y);
        }
        else
        {

            canvas->DrawLine(pen, inputGate->outputSignalLocation.X, inputGate->outputSignalLocation.Y, outputGate->inputSignalTwoLocation.X, outputGate->inputSignalTwoLocation.Y);
        }
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
            this->signal->addOutputGate(lw->getGate(), 0);
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
