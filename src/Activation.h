#pragma once
#include "Matrix.h"

namespace LightNetwork
{
    class Activation
    {
    public:
        virtual void activate(float& m) = 0;
    };

} // namespace LightNetwork