#pragma once
#include "gatter.h"

public ref class Nand :
    public Gatter
{
public:
    Nand(int number);
    Nand(void);

    virtual void calculate() override;
};
