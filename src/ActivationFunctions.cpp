#include "ActivationFunctions.h"


void RELU::activate(float &in)
{
    in = max((float)0, in);
}

void SIGMOID::activate(float &in)
{
    in = 1 / (1 + exp(-in));
}


void LEAKY_RELU::activate(float &in)
{
    in = max(0.01f * in, in);
}

