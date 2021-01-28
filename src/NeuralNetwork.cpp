
#include "NeuralNetwork.h"

NeuralNetwork::NeuralNetwork(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, uint16_t l_c)
{
  i_X = inX;
  i_Y = inY;
  i_Z = inZ;
  this->layer_count = l_c;
  this->layers = new Layer *[l_c];
}

NeuralNetwork::~NeuralNetwork()
{
  for (unsigned char i = 0; i < layer_count; i++)
  {
    delete layers[i];
  }
}

MNC::Matrix NeuralNetwork::guess(MNC::Matrix &in)
{
  INT_MNC outX, outY, outZ;
  layers[layer_count - 1]->getOutDimensions(outX, outY, outZ);
  outY = outX * outY * outZ;
  MNC::Matrix result(outY, 1);
  for (uint16_t i = 0; i < layer_count; i++)
  {
    if (layers[i]->isCacheEnabled())
    {
      layers[i]->resetCache();
    }
  }

  for (INT_MNC i = 0; i < outY; i++)
  {
    result.data[i] = layers[layer_count - 1]->get_result(in, i, layers);
  }
  return result;
}
