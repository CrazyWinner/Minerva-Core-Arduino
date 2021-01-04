#pragma once
#include <vector> 
#include "Layer.h"
namespace LightNetwork{
   class NeuralNetwork{
       private:
         
         int i_count;
       public:
         std::vector<Layer*> layers;
         void reset();
         NeuralNetwork(int i_c);
         ~NeuralNetwork();
         void addLayer(int p_c, Activation* act);
         Matrix guess(Matrix& in);
         void train(Matrix& in, Matrix& desired_result);
      


   };




}