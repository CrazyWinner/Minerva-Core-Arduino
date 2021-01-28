#pragma once
#include "Matrix.h"

class Activation
{
public:
    enum ActivationType :  uint8_t
    {
        RELU = 0,
        SIGMOID,
        LEAKY_RELU
    };
    static void activate(float& in, ActivationType act)
    {
        switch (act)
        {
        case RELU:
        {
            in = max((float)0, in);
            break;
        }
        case SIGMOID:
        {
            in = 1 / (1 + exp(-in));
            break;
        }
        case LEAKY_RELU:
        {
            in = max(0.01f * in, in);
            break;
        }
        }
    };
};