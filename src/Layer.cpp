#include "Layer.h"





Layer::Layer(uint16_t i_s, uint16_t p_c, Activation *act, uint16_t l_Id, LN::Matrix* w, LN::Matrix* b)
{
    this->layerId = l_Id;
    activator = act;
    this->i_size = i_s;
    this->p_count = p_c;
    weights = w;
    bias = b;
    deleteAfter = false;

}

void Layer::enableOptimization(bool e){
	if(e != optEnabled){
		if(e){
			optimizator = new float[p_count];
		}else{
			delete[] optimizator;
			optimizator = 0;
		}
		
		optEnabled = e;
	}
	
}

Layer::Layer(uint16_t i_s, uint16_t p_c, Activation *act, uint16_t l_Id)
{
    this->layerId = l_Id;
    activator = act;
    this->i_size = i_s;
    this->p_count = p_c;
    weights = new LN::Matrix(p_count, i_size);
    bias = new LN::Matrix(p_count, 1);

}

void Layer::resetOptimization(){
	opt = false;
}

bool Layer::isOptimizationEnabled(){
	return optEnabled;
}

Layer::~Layer()
{
  if(deleteAfter){
    delete bias;
    delete weights;}
    delete activator;
	if(optEnabled){
		delete[] optimizator;
	}
   
}

float Layer::get_result(LN::Matrix& in, uint16_t p_id, Layer** layers)
{
	if(optEnabled && opt){
	return optimizator[p_id];
	}
	float a = 0;
    if(layerId == 0) {
       
       for(int i = 0; i < this->i_size; i++){
           a += in.at(i,0) * weights->at(p_id, i);
       }
       a += bias->at(p_id, 0);
	   activator->activate(a);
    }else{

      for(int j = 0; j <  layers[layerId - 1] -> p_count; j++){
        a += layers[layerId - 1]->get_result(in, j, layers)  * weights->at(p_id, j);
      }
      a += bias->at(p_id, 0);
      activator->activate(a);
    }
	if(optEnabled){
		optimizator[p_id] = a;
	}
	if(p_id == p_count - 1)opt = true;
  return a;
}
