#pragma once
#include "Matrix.h"
#include <Arduino.h>
    class Activation
    {
    public:
        virtual void activate(float& m) = 0;
    };

