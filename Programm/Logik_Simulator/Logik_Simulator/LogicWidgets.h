#pragma once

#include "Gatter.h"
#include "Signal.h"

using namespace System;
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
    void destruct();
    Boolean isDestructed();
    void paint(Graphics ^ );
    Size ^ getSize();
    Point ^ getLocation();
    void setLocation(Point ^ );
    Gatter ^ getGate();
    Boolean connectInputSignalOne(SignalWidget ^ );
    Boolean connectInputSignalTwo(SignalWidget ^ );
    Boolean connectOutputSignal(SignalWidget ^ );
    void disconnectInputSignal(SignalWidget ^ );
    void disconnectOutputSignal(SignalWidget ^ );
    Boolean widgetHit(Point ^ );
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
}
