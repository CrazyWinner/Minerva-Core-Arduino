#include "FullyConnected.h"



FullyConnected::FullyConnected(const uint32_t& p_c, const Activation::ActivationType& act, const uint32_t& l_Id)
: Layer(act, l_Id)
{
	this->p_count = p_c;
}


void FullyConnected::init(const uint32_t& inX, const uint32_t& inY, const uint32_t& inZ, MNC::Matrix* w, MNC::Matrix* b)
{
	this->i_size = inX * inY * inZ;  
    weights = w;
    bias = b;
}

void FullyConnected::getOutDimensions(uint32_t& outX, uint32_t& outY, uint32_t& outZ){
	outX = 1;
	outY = p_count;
	outZ = 1;
}





float FullyConnected::get_result(const MNC::Matrix& in, const uint32_t& p_id, Layer** layers)
{
	if(isCacheEnabled() && cached){
	return cache[p_id];
	}
	float a = 0;  
       for(uint32_t i = 0; i < i_size; i++){
		   
			 if(layerId == 0){
			 a += in.at(i,0) * weights->at(p_id, i); }else{
			 a += layers[layerId - 1]->get_result(in, i, layers)  * weights->at(p_id, i);}
		 
       }
       a += bias->at(p_id, 0);
	   Activation::activate(a, activationType);
   
	if(isCacheEnabled()){
		cache[p_id] = a;
	}
	if(p_id == p_count - 1)cached = true;
  return a;
}
