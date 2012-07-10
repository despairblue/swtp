#pragma once
#include "Gatter.h"

public ref class Exor :
    public Gatter
{
public:
    Exor(void);
    Exor(int number);

    virtual void calculate() override;
};
