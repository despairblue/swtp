#pragma once
#include "Gatter.h"

public ref class And :
    public Gatter
{
public:
    And(int number);
    And(void);

    virtual void calculate() override;
};
