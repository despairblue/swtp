#include "StdAfx.h"
#include "Fork.h"

Fork::Fork(void): Gatter()
{
    this->output = gcnew ArrayList();
    this->output->Add(false);
    this->output->Add(false);
}

Fork::Fork(int number): Gatter(number)
{
    this->output = gcnew ArrayList();
    this->output->Add(false);
    this->output->Add(false);
}

void Fork::calculate()
{
    bool result = this->input[0];
    int i = 0;

	while (i < this->output->ToArray()->GetLength(0) )
    {
        this->output[i] = result;
        Gatter::setResult(i, result);
        Gatter::calculate();
        i++;
    }

    this->CalculationFinish();
}

