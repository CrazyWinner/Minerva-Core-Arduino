
#include "NeuralNetwork.h"


NeuralNetwork::NeuralNetwork(uint16_t i_c, unsigned char l_c)
{
  this->i_count = i_c;
  this->layer_count = l_c;
  this->layers = new Layer*[l_c];
}

NeuralNetwork::~NeuralNetwork()
{
  for (unsigned char i = 0; i < layer_count; i++)
  {
    delete layers[i];
  }
}




LN::Matrix NeuralNetwork::guess(LN::Matrix &in)
{
   LN::Matrix result(layers[layer_count - 1]->p_count,1);
   for(int i = 0; i < layers[layer_count - 1]->p_count; i++){
      result.data[i] = layers[layer_count - 1]->get_result(in, i, layers);
   }
   return result;
}

