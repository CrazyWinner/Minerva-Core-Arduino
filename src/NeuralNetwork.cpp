
#include "NeuralNetwork.h"
using namespace LightNetwork;

NeuralNetwork::NeuralNetwork(int i_c)
{
  this->i_count = i_c;
}

NeuralNetwork::~NeuralNetwork()
{
  for (int i = 0; i < layers.size(); i++)
  {
    delete layers.at(i);
  }
  layers.clear();
}

void NeuralNetwork::addLayer(int p_c, Activation *act)
{
  if (layers.empty())
  {
    layers.push_back(new Layer(i_count, p_c, act, layers.size()));
  }
  else
  {
    layers.push_back(new Layer(layers.at(layers.size() - 1)->p_count, p_c, act, layers.size()));
  }
}


Matrix NeuralNetwork::guess(Matrix &in)
{
   Matrix result(layers.at(layers.size() -1 )->p_count,1);
   for(int i = 0; i < layers.at(layers.size() -1)->p_count; i++){
      result.data[i] = layers.at(layers.size() -1)->get_result(in, i, &layers);
   }
   return result;
}

