#pragma once

using namespace System::Collections;

#include "gatter.h"

ref class Fork :
    public Gatter
{
public:
    Fork(void);
    Fork(int number);
    virtual void calculate() override;
protected:
    ArrayList ^ output;
};
