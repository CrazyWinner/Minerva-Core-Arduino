#pragma once
#include "Matrix.h"
#include "Activation.h"
#include "ActivationFunctions.h"
#include <Arduino.h>

    class Layer
    {     
    private:
        bool deleteAfter = true;   
        bool optEnabled = false;
    public:
	    float* optimizator;
		bool opt;
        Activation* activator;
        MNC::Matrix* weights;
        MNC::Matrix* bias;     
        uint16_t layerId;   
        uint16_t i_size,p_count;
		void enableOptimization(bool e);
		bool isOptimizationEnabled();
		void resetOptimization();
        Layer(uint16_t i_s, uint16_t p_c, Activation* act, uint16_t l_Id);
        Layer(uint16_t i_s, uint16_t p_c, Activation* act, uint16_t l_Id, MNC::Matrix* w, MNC::Matrix* b);
        ~Layer();
        float get_result(MNC::Matrix& in, uint16_t p_id, Layer** layers);
       
    };

