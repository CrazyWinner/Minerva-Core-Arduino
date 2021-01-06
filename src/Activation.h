#pragma once
#include "Matrix.h"
#include <algorithm>

    class Activation
    {
    public:
        virtual void activate(float& m) = 0;
    };

