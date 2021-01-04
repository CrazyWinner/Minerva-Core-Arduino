#include "Layer.h"
#include <unistd.h>

using namespace LightNetwork;


Layer::Layer(int i_s, int p_c, Activation *act, int l_Id)
{
    this->layerId = l_Id;
    activator = act;
    this->i_size = i_s;
    this->p_count = p_c;
    weights = new Matrix(p_count, i_size);
    weights->randomize();
    bias = new Matrix(p_count, 1);
    bias->fill();

}

Layer::~Layer()
{
    delete activator;
    delete weights;
    delete bias;
}

float Layer::get_result(Matrix& in, int p_id, std::vector<Layer*>* layers)
{
    if(layerId == 0) {
       float a = 0;
       for(int i = 0; i < this->i_size; i++){
           a += in.at(i,0) * weights->at(p_id, i);
       }
       a += bias->at(p_id, 0);
       activator->activate(a);
       return a;
    }else{
      float a = 0;
      for(int j = 0; j <  layers->at(layerId - 1)->p_count; j++){
        a += layers->at(layerId - 1)->get_result(in, j, layers)  * weights->at(p_id, j);
      }
      a += bias->at(p_id, 0);
      activator->activate(a);
      return a;
    }
  return 0;
}
