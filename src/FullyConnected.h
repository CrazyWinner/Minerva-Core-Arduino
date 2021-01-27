#pragma once
#include "Layer.h"
    class FullyConnected : public Layer
    {     
	private:
	    uint32_t i_size,p_count;
    public:
        float get_result(const MNC::Matrix& in, const uint32_t& p_id, Layer** layers);
        FullyConnected(const uint32_t& p_c, const Activation::ActivationType& act, const uint32_t& l_Id);
		void init(const uint32_t& inX, const uint32_t& inY, const uint32_t& inZ, MNC::Matrix* w, MNC::Matrix* b);
        void getOutDimensions(uint32_t& outX, uint32_t& outY, uint32_t& outZ);
	};

