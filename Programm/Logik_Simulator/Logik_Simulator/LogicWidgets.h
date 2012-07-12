#pragma once

#include "Gatter.h"
#include "And.h"
#include "Or.h"
#include "Exor.h"
#include "Not.h"
#include "Nand.h"
#include "Nor.h"
#include "Input.h"
#include "Output.h"
#include "Signal.h"
#include "Input.h"
#include "Output.h"
#include "Fork.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;

namespace LogicWidgets
{
ref class SignalWidget;

/// Base class of all widgets.

/// Contains all shared properties and methods,
/// so other classes can use any widget without
/// knowing what it looks like or what its for.
public ref class LogicWidget
{
public:
    LogicWidget( Point ^ location, Int32 id, String ^ text);
    /// False by default. Changes the appearance of the widget if true.
    /** Depending on state paint will draw the widget in another color.
        @see LogicWidget::paint() */
    Boolean selected;
    PointF inputSignalOneLocation; ///< Docking location of the first ingoing SignalWidget.
    PointF inputSignalTwoLocation; ///< Docking location of the second ingoing SignalWidget.
    PointF outputSignalLocation; ///< Docking location of the outgoing SignalWidget.

protected:
    /// False by default. Set to true after destruct() finishes.
    /** 
        If true prevents widget from painting.
        @see LogicWidget::destruct()
    */
    Boolean destructed;
    Size ^ size; ///< Size of the widget.
    Point ^ location; ///< Location of the widget.
    String ^ text; ///< Text inside the widget.
    Gatter ^ gate; ///< The underlying Gatter.
    SignalWidget ^ inputSignalOne; ///< First ingoing SignalWidget
    SignalWidget ^ inputSignalTwo; ///< Second ingoing SignalWidget
    SignalWidget ^ outputSignal; ///< Outgoing SignalWidget
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

/// Graphical representation of Signal.

/// SignalWidgets are used to connect two LogicWidget instances.
public ref class SignalWidget
{
public:
    SignalWidget();

protected:
    /// False by default. Set to true after destruct() finishes.
    /** @see SignalWidget::destruct()*/
    Boolean destructed;
    LogicWidget ^ inputGate; ///< Ingoing LogicWidget.
    LogicWidget ^ outputGate; ///< Outgoing LogicWidget.
    /// Contains a number specifying to what input slot it connects.
    /** This is used by paint() to decide where to draw the SignalWidget to.
        Either LogicWidget::inputSignalOneLocation or LogicWidget::inputSignalTwoLocation. */
    int connectedToInput;
    Signal ^ signal; ///< Contains underlying Signal.

private:
    array<Int32> ^ cross(array<Int32> ^ v1, array<Int32> ^ v2);

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
    Boolean signalCut(Point start, Point stop);
};

/// Graphical representation of Input.
ref class InputWidget :
    public LogicWidget
{
public:
    InputWidget(Point ^ location, Int32 id);
public:
    virtual Boolean connectInputSignalOne(SignalWidget ^ sw) override;
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
    virtual Boolean keyUp(KeyEventArgs ^ e, ToolStripStatusLabel ^ statusBar) override;
    virtual void click(ToolStripStatusLabel ^ statusBar) override;
};

/// Graphical representation of Output.
ref class OutputWidget :
    public LogicWidget
{
public:
    OutputWidget(Point ^ location, Int32 id) ;
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual Boolean connectOutputSignal(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
    virtual void setLocation(Point ^ location) override;
};

/// Graphical representation of Not.
ref class NotWidget:
    public LogicWidget
{
public:
    NotWidget(Point ^ location, Int32 id);
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
    virtual void setLocation(Point ^ location) override;
};

/// Graphical representation of Nand.
ref class NandWidget:
    public LogicWidget
{
public:
    NandWidget(Point ^ location, Int32 id);
public:
    virtual void paint(Graphics ^ canvas) override;
};

/// Graphical representation of Nor.
ref class NorWidget: public LogicWidget
{
public:
    NorWidget(Point ^ location, Int32 id);
public:
    virtual void paint(Graphics ^ canvas) override;
};

/// Graphical representation of Fork.

/// A Fork is used to split a Signal into two @link Signal Signals @endlink
ref class ForkWidget:
    public LogicWidget
{
public:
    ForkWidget(Point ^ location, Int32 id);
protected:
    array < SignalWidget ^ > ^ outputSignals; ///< Contains the outgoing SignalWidget instances.
public:
    virtual Boolean connectInputSignalTwo(SignalWidget ^ sw) override;
    virtual Boolean connectOutputSignal(SignalWidget ^ sw) override;
    virtual void disconnectOutputSignal(SignalWidget ^ sw) override;
    virtual void paint(Graphics ^ canvas) override;
};

/// Graphical representation of And.
ref class AndWidget:
    public LogicWidget
{
public:
    AndWidget(Point ^ location, Int32 id);
};

/// Graphical representation of Or.
ref class OrWidget:
    public LogicWidget
{
public:
    OrWidget(Point ^ location, Int32 id);
};

/// Graphical representation of Exor.
ref class ExorWidget:
    public LogicWidget
{
public:
    ExorWidget(Point ^ location, Int32 id);
};
}
