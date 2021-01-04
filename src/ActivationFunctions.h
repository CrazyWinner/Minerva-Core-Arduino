#pragma once
#include "Activation.h"
#include "Matrix.h"
#include <algorithm>
#include "math.h"
namespace LightNetwork
{
     class RELU : public Activation
     {
     public:
        virtual void activate(float& m);
        ~RELU(){};
     };
    

     class SIGMOID : public Activation
     {
     public:
          virtual void activate(float &m);
          ~SIGMOID(){};

     };
     class LEAKY_RELU : public Activation
     {
     public:
          virtual void activate(float &m);
          ~LEAKY_RELU(){};

     };

} // namespace LightNetwork