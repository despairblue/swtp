#pragma once

#include "StdAfx.h"

//#include "Signal.h"

public ref class Gatter
{
public:
    delegate void CalculationFinishEventHandler();
    event CalculationFinishEventHandler ^ CalculationFinish;

    Gatter(void);
    Gatter(int inputNumber);

    virtual void calculate();

    virtual void setInputValue(bool value);
    void setInputValue(int number, bool value);

    int getLength();
    bool getResult(int number);
    bool getResult();
    bool output;

    void setResult(bool result);
    void setResult(int number, bool result);
    void addInput(int number);

protected:

    array<bool> ^ input;

private:
    int length;
    int number;
    System::String ^ name;

};
