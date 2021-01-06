#pragma once
#include "Layer.h"
#define LN LightNetwork
   class NeuralNetwork{
       private:
         
         uint16_t i_count;
         
       public:
         unsigned char layer_count;
         Layer** layers;
         void reset();
         NeuralNetwork(uint16_t i_c, unsigned char l_c);
         ~NeuralNetwork();
         void addLayer(uint16_t p_c, Activation* act);
         LN::Matrix guess(LN::Matrix& in);
         void train(LN::Matrix& in, LN::Matrix& desired_result);
      


   };




