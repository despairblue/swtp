#pragma once
#include "gatter.h"

public ref class Nor :
    public Gatter
{
public:
    Nor(void);
    Nor(int number);

    virtual void calculate() override;
};
