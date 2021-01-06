#pragma once
#include <Arduino.h>
namespace LightNetwork
{
    class Matrix
    {
        private:
       //   uint16_t rows, columns;    
          bool isTransposed = false;
          bool destroyAfter = true;
		  bool isProgmem = false;
          uint16_t rows, columns;  		  
        public:    
          float* data;  		
          Matrix(uint16_t r, uint16_t c);
          Matrix(uint16_t r, uint16_t c, float* arr, bool i_p);
          ~Matrix();      
          void operator+=(const Matrix &m);
          Matrix operator*(const Matrix &m);
          float at(uint16_t i, uint16_t j);
          Matrix transpose();
          void doOperation(void (*op)(float&));
          Matrix operator-(const Matrix &m);
          void operator=(const Matrix &m);
          void hadamard(const Matrix &m);
          void operator*=(const float &f);
          void randomize();
          void fill();
          void operator-=(const Matrix &m);
          void printDebug();
          uint32_t getIndex (uint16_t r,uint16_t c) const;
          void setTransposed(bool t);
          static Matrix fromArray(uint16_t r, uint16_t c, float* arr);   
    
    };

} // namespace LightNetwork