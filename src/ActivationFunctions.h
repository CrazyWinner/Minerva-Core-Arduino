#pragma once
#include "Activation.h"
#include "Matrix.h"
#include <Arduino.h>
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

