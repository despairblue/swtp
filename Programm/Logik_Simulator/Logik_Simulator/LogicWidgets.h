#pragma once

#include "Gatter.h"
#include "Signal.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets
{
ref class SignalWidget;

public ref class LogicWidget
{
public:
    LogicWidget(String ^ , Point ^ , Gatter ^ );
    LogicWidget(void);
    Boolean selected;
    Rectangle inputSignalOneLocation;
    Rectangle inputSignalTwoLocation;
    Rectangle outputSignalLocation;

protected:
    Boolean destructed;
    Size ^ size;
    Point ^ location;
    String ^ type;
    Gatter ^ gate;
    SignalWidget ^ inputSignalOne;
    SignalWidget ^ inputSignalTwo;
    SignalWidget ^ outputSignal;

public:
    virtual void destruct();
    virtual Boolean isDestructed();
    virtual void paint(Graphics ^ );
    virtual Size ^ getSize();
    virtual Point ^ getLocation();
    virtual void setLocation(Point ^ );
    virtual Gatter ^ getGate();
    virtual Boolean connectInputSignalOne(SignalWidget ^ );
    virtual Boolean connectInputSignalTwo(SignalWidget ^ );
    virtual Boolean connectOutputSignal(SignalWidget ^ );
    virtual void disconnectInputSignal(SignalWidget ^ );
    virtual void disconnectOutputSignal(SignalWidget ^ );
    virtual void click(ToolStripStatusLabel ^ );
    virtual void keyUp(KeyEventArgs ^ , ToolStripStatusLabel ^ );
    virtual Boolean widgetHit(Point ^ );
};

public ref class SignalWidget
{
public:
    SignalWidget(Signal ^ );
    SignalWidget(void);

protected:
    Boolean destructed;
    LogicWidget ^ inputGate;
    LogicWidget ^ outputGate;
    int connectedToInput;
    Signal ^ signal;

public:
    void destruct();
    Boolean isDestructed();
    void paint(Graphics ^ );
    Signal ^ getSignal();
    void setInputGate(LogicWidget ^ );
    void setOutputGate(LogicWidget ^ );
    void disconnectAll();
};

ref class InputWidget :
    public LogicWidget
{
public:
    InputWidget(String ^ , Point ^ , Gatter ^ );
    InputWidget(void);
    virtual Boolean connectInputSignalOne(SignalWidget ^ ) override;
    virtual Boolean connectInputSignalTwo(SignalWidget ^ ) override;
    virtual void paint(Graphics ^ ) override;
};
}
