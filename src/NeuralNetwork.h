#pragma once
#include "Layer.h"
#include <Arduino.h>
#include "Matrix.h"
   class NeuralNetwork{
       private:
         
         uint32_t i_X;
         uint32_t i_Y;
		 uint32_t i_Z;
       public:
         unsigned char layer_count;
         Layer** layers;
         NeuralNetwork(const uint32_t& inX, const uint32_t& inY, const uint32_t& inZ, const uint16_t& l_c);
         ~NeuralNetwork();
         MNC::Matrix guess(MNC::Matrix& in);
         void train(MNC::Matrix& in, MNC::Matrix& desired_result);
      


   };




