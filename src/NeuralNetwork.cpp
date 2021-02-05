
#include "NeuralNetwork.h"

void NeuralNetwork::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, uint16_t l_c)
{
  delete[] layers;
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
  delete[] layers;
}

Matrix3D NeuralNetwork::guess(Matrix3D &in)
{
  INT_MNC outX, outY, outZ;
  layers[layer_count - 1]->getOutDimensions(outX, outY, outZ);
  Matrix3D result(outX , outY, outZ);
  for (uint16_t i = 0; i < layer_count; i++)
  {
    if (layers[i]->isCacheEnabled())
    {
      layers[i]->resetCache();
    }
  }

  for(INT_MNC z = 0; z < outZ; z++){
	 for(INT_MNC y = 0; y < outY; y++){
	    for(INT_MNC x = 0; x < outX; x++){
			result.set(x, y, z, layers[layer_count - 1]->get_result(in, x, y, z, layers));
  }
  } 
  }

  return result;
}
