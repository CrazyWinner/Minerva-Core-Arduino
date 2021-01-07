#pragma once
#include "Layer.h"
#include <Arduino.h>
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
         MNC::Matrix guess(MNC::Matrix& in);
         void train(MNC::Matrix& in, MNC::Matrix& desired_result);
      


   };




