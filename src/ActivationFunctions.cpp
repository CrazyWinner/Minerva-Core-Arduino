#include "ActivationFunctions.h"
using namespace LightNetwork;

void RELU::activate(float &in)
{
    in = std::max((float)0, in);
}

void SIGMOID::activate(float &in)
{
    in = 1 / (1 + std::exp(-in));
}


void LEAKY_RELU::activate(float &in)
{
    in = std::max(0.01f * in, in);
}

