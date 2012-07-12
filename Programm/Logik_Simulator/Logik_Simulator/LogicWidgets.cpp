#pragma once

#include "stdafx.h"

#include "LogicWidgets.h"

using namespace System::Windows::Forms;
using namespace LogicWidgets;


// NOTE: LogicWidget
/**
    Constructs a new LogicWidget.
    @param location The location of this widget on the canvas.
    @param id The ID of this widget.
    @param text The Text inside the widget
*/
LogicWidget::LogicWidget(Point ^ location, Int32 id, String ^ text )
{
    this->size = gcnew Size(40, 40);
    this->selected = false;
    this->destructed = false;

    this->setLocation(location);
    this->gate = gcnew Gatter();
    this->id = id;
    this->text = text;
}

/**
    Set the ID
    @param id The new ID
*/
void LogicWidget::setID(Int32 id)
{
    this->id = id;
}

/**
    Get the ID
    @return ID of the widget.
*/
Int32 LogicWidget::getID()
{
    return id;
}

/**
    Destructs the widget
    - sets destructed to true
    - desctructs oll connected SignalWidgets
*/
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

/**
    Returns true if the widget was desctructed
    @see desctructed destruct()
*/
Boolean LogicWidget::isDestructed()
{
    return this->destructed;
}

/**
    Paints the widget on a graphics context.
    @param canvas An instance of System::Drawing::Graphics
*/
void LogicWidget::paint(Graphics ^ canvas)
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

        canvas->DrawString(text, font, sb,
                           (float)(location->X + 3),
                           (float)(location->Y + 3));
    }
}


/// Returns the size of the widget.
Size ^ LogicWidget::getSize()
{
    return this->size;
}

/// Returns the location of the widget.
Point ^ LogicWidget::getLocation()
{
    return this->location;
}

/// Sets the Location of the widget.
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

/// Returns underlying Gatter
Gatter ^ LogicWidget::getGate()
{
    return this->gate;
}

/**
    Tries to connect sw to this widgets first input slot.
    @param sw SignalWidget that's supposed to be connected.
    @return true if connection succeeded, otherwise false.
*/
Boolean LogicWidget::connectInputSignalOne(SignalWidget ^ sw)
{

    if ( this->inputSignalOne )
    {
        return false;
    }
    else
    {
        if ( destructed )
        {
            return false;
        }
        else
        {
            this->inputSignalOne = sw;
            return true;
        }
    }

}

/**
    Tries to connect sw to this widgets second input slot.
    @param sw SignalWidget that's supposed to be connected.
    @return true if connection succeeded, otherwise false.
*/
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

/// Disconnects sw from this widgets input
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


/**
    Tries to connect sw to this widgets output slot.
    @param sw SignalWidget that's supposed to be connected.
    @return true if connection succeeded, otherwise false.
*/
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

/// Disconnects sw from this widgets output
void LogicWidget::disconnectOutputSignal(SignalWidget ^ sw)
{
    if (this->outputSignal == sw)
    {
        this->outputSignal = nullptr;
    }
}

/// Tells the widget that it has been clicked
/// @param statusBar the status bar of the main form
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

/// Tells the widget that a key was pressed
Boolean LogicWidget::keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar)
{
    if (e->KeyCode == Keys::Delete && selected)
    {
        destruct();
        statusBar->Text = "Gate removed.";

        return true;
    }

    return false;
}

/// Returns true if the widget was clicked, otherwise false.
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
/// Constructs new SignalWidget
SignalWidget::SignalWidget()
{
    this->destructed = false;
    this->connectedToInput = 0;
    this->signal = gcnew Signal();
}

/**
    Destructs this widget
    - disconnects all connected LogicWidgets
    - removes reference to underlying signal
*/
void SignalWidget::destruct()
{
    this->destructed = true;
    this->disconnectAll();

    signal = nullptr;
}

/// Returns true if the widget was destructed.
Boolean SignalWidget::isDestructed()
{
    return this->destructed;
}

/// Paints the widget on a graphics context.
/// @param canvas   An instance of System::Drawing::Graphics
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

/// Returns underlying Signal
Signal ^ SignalWidget::getSignal()
{
    return this->signal;
}

/// Sets the widgets input LogicWidget.
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

/// Returns the the widgets input LogicWidget
LogicWidget ^ SignalWidget::getInputGate()
{
    return inputGate;
}

/// Sets the widgets output LogicWidget
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

/// Returns the widgets output LogicWidget.
LogicWidget ^ SignalWidget::getOutputGate()
{
    return outputGate;
}

/// Disconnects this widget from all LogicWidget instances it was connected to.
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

/// Starts simulation if this SignalWidget is connected to an InputWidget.
Boolean SignalWidget::transmit()
{
    if (inputGate->GetType() == InputWidget::typeid)
    {
        signal->transmit();
        return true;
    }
    return false;
}

// NOTE: InputWidget
/**
    @param location The widgets location
    @param id The widgets ID
*/
InputWidget::InputWidget(Point ^ location, Int32 id):
    LogicWidget(location, id, "In:\n")
{
    this->gate = gcnew Input();
}

/// Will always return false, InputWidgets have no input slots.
Boolean InputWidget::connectInputSignalOne(SignalWidget ^ sw)
{
    return false;
}

/// Will always return false, InputWidgets have no input slots.
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

/** Handles key events.
    - Keys::Delete will destruct the widget
    - 0 and 1 change the @link Input Inputs @endlink state
*/
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

    if (selected)
    {
        statusBar->Text = "Press 1 or 0 to toggle state. Press Delete to remove. Drag to another Widget to connect.";
    }
}

// NOTE: OutputWidget
/**
    @param location The widgets location
    @param id The widgets ID
*/
OutputWidget::OutputWidget(Point ^ location, Int32 id):
    LogicWidget(location, id, "Out:\n")
{
    this->setLocation(location);
}

void OutputWidget::setLocation(Point ^ location)
{
    LogicWidget::setLocation(location);
    
    this->inputSignalOneLocation.X = (float) this->location->X ;
    this->inputSignalOneLocation.Y = (float) (this->location->Y + (this->size->Height / 2));
}

/// Will always return false, OutputWidget instances have only one input slot.
Boolean OutputWidget::connectInputSignalTwo(SignalWidget ^ sw)
{
    return false;
}

/// Will always return false, OutputWidget instances have no output slot.
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
/**
    @param location The widgets location
    @param id The widgets ID
*/
NotWidget::NotWidget(Point ^ location, Int32 id):
    LogicWidget(location, id, "1")
{
    this->gate = gcnew Not();

    this->setLocation(location);
}

void NotWidget::setLocation(Point ^ location)
{
    LogicWidget::setLocation(location);

    this->inputSignalOneLocation.X = (float) this->location->X ;
    this->inputSignalOneLocation.Y = (float) (this->location->Y + (this->size->Height / 2));
}

/// Will always return false, NotWidget instances have only one input slot.
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

NandWidget::NandWidget(Point ^ location, Int32 id):
    LogicWidget(location, id, "&")
{
    this->gate = gcnew Nand();
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

        canvas->DrawString("&", font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
    }
}

// NOTE: NorWidget

NorWidget::NorWidget(Point ^ location, Int32 id):
    LogicWidget(location, id, ">=1")
{
    this->gate = gcnew Nor();
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

        canvas->DrawString(">=1" , font, sb , safe_cast<float>(location->X + 3), safe_cast<float>(location->Y) + 3);
    }
}

// NOTE: ForkWidget
ForkWidget::ForkWidget(Point ^ location, Int32 id):
    LogicWidget( location, id, "Fork")
{
    this->gate = gcnew Fork();

    this->outputSignals = gcnew array < SignalWidget ^ > (2);
    this->size = gcnew Size(10, 10);
    this->setLocation(location);
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

void ForkWidget::paint(Graphics ^ canvas)
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

		canvas->FillEllipse(sb, location->X, location->Y, this->size->Width, this->size->Height);
    }
}

// NOTE: AndWidget
AndWidget::AndWidget(Point ^ location, Int32 id):
    LogicWidget( location, id, "&")
{
    this->gate = gcnew And();
}

// NOTE: OrWidget
OrWidget::OrWidget(Point ^ location, Int32 id):
    LogicWidget( location, id, ">=1")
{
    this->gate = gcnew Or();
}

// NOTE: ExorWidget
ExorWidget::ExorWidget(Point ^ location, Int32 id):
    LogicWidget( location, id, "=1")
{
    this->gate = gcnew Exor();
}

