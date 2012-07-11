#pragma once

#include "Gatter.h"
#include "Signal.h"
#include "Input.h"
#include "Output.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets
{
ref class SignalWidget;

public ref class LogicWidget
{
public:
    LogicWidget( String ^ type, Point ^ location, Gatter ^ gate, Int32 id );
    Boolean selected;
    PointF inputSignalOneLocation;
    PointF inputSignalTwoLocation;
    PointF outputSignalLocation;

protected:
    Boolean destructed;
    Size ^ size;
    Point ^ location;
    String ^ type;
    Gatter ^ gate;
    SignalWidget ^ inputSignalOne;
    SignalWidget ^ inputSignalTwo;
    SignalWidget ^ outputSignal;
    Int32 id;
public:
    virtual Int32 getID();
    virtual void setID(Int32 id);
    virtual void destruct();
    virtual Boolean isDestructed();
    virtual void paint(Graphics ^ canvas);
    virtual Size ^ getSize();
    virtual Point ^ getLocation();
    virtual void setLocation(Point ^ location);
    virtual Gatter ^ getGate();
    virtual Boolean connectInputSignalOne(SignalWidget ^ sw);
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw);
    virtual Boolean connectOutputSignal(SignalWidget ^ sw);
    virtual void disconnectInputSignal(SignalWidget ^ sw);
    virtual void disconnectOutputSignal(SignalWidget ^ sw);
    virtual void click(ToolStripStatusLabel ^ statusBar);
    virtual Boolean keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar);
    virtual Boolean widgetHit(Point ^ clickLocation);
};

public ref class SignalWidget
{
public:
    SignalWidget(Signal ^ signal);

protected:
    Boolean destructed;
    LogicWidget ^ inputGate;
    LogicWidget ^ outputGate;
    int connectedToInput;
    Signal ^ signal;

public:
    void destruct();
    Boolean isDestructed();
    void paint(Graphics ^ canvas);
    Signal ^ getSignal();
    void setInputGate(LogicWidget ^ lw);
    LogicWidget ^ getInputGate();
    void setOutputGate(LogicWidget ^ lw);
    LogicWidget ^ getOutputGate();
    void disconnectAll();
    Boolean transmit();
};

ref class InputWidget :
    public LogicWidget
{
public:
    InputWidget(String ^ type, Point ^ location, Input ^ gate, Int32 id);
public:
    virtual Boolean connectInputSignalOne(SignalWidget ^ sw) override;
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
    virtual Boolean keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar) override;
    virtual void click(ToolStripStatusLabel ^ statusBar) override;
};

ref class OutputWidget :
    public LogicWidget
{
public:
    OutputWidget( String ^ type, Point ^ location, Output ^ gate, Int32 id) ;
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual Boolean connectOutputSignal(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
};

ref class NotWidget:
    public LogicWidget
{
public:
    NotWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
};

ref class NandWidget:
    public LogicWidget
{
public:
    NandWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
public:
    virtual void paint(Graphics ^ canvas) override;
};

ref class NorWidget: public LogicWidget
{
public:
    NorWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
public:
    virtual void paint(Graphics ^ canvas) override;
};

ref class ForkWidget:
    public LogicWidget
{
public:
    ForkWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
protected:
    array < SignalWidget ^ > ^ outputSignals;
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual Boolean connectOutputSignal(SignalWidget ^ sw) override;
    virtual void disconnectOutputSignal(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
};

ref class AndWidget:
    public LogicWidget
{
public:
    AndWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
};

ref class OrWidget:
    public LogicWidget
{
public:
    OrWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
};

ref class ExorWidget:
    public LogicWidget
{
public:
    ExorWidget(String ^ type, Point ^ location, Gatter ^ gate, Int32 id);
};
}
