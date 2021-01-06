#pragma once
#include "Matrix.h"
#include "Activation.h"
#include "ActivationFunctions.h"
#include <Arduino.h>
#define LN LightNetwork

    class Layer
    {     
    private:
        bool deleteAfter = true;    
    public:
        Activation* activator;
        LN::Matrix* weights;
        LN::Matrix* bias;     
        uint16_t layerId;   
        uint16_t i_size,p_count;
        Layer(uint16_t i_s, uint16_t p_c, Activation* act, uint16_t l_Id);
        Layer(uint16_t i_s, uint16_t p_c, Activation* act, uint16_t l_Id, LN::Matrix* w, LN::Matrix* b);
        ~Layer();
        float get_result(LN::Matrix& in, uint16_t p_id, Layer** layers);
       
    };

