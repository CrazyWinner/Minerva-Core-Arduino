#pragma once
#include "Matrix.h"
#include "Activation.h"
#include <Arduino.h>

    class Layer
    {     
    private:
        bool deleteAfter = true;    
		bool cacheEnabled = false;		
    public:
	    Activation::ActivationType activationType;
	    float* cache = nullptr;
	    bool cached = false;
     	enum LayerType : uint8_t {FULLY_CONNECTED = 0, CONVOLUTIONAL, MAX_POOLING};
        MNC::Matrix* weights;
        MNC::Matrix* bias;     
        uint32_t layerId;   
		void enableCache(bool e);
		bool isCacheEnabled();
		void resetCache();
        Layer(const Activation::ActivationType& act, const uint32_t& l_Id);
        ~Layer();
        virtual float get_result(const MNC::Matrix& in, const uint32_t& p_id, Layer** layers) = 0;
        virtual void init(const uint32_t& inX, const uint32_t& inY, const uint32_t& inZ, MNC::Matrix* w, MNC::Matrix* b) = 0;
        virtual void getOutDimensions(uint32_t& outX, uint32_t& outY, uint32_t& outZ) = 0;
	};

