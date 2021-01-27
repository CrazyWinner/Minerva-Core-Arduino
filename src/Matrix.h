#pragma once
#include <Arduino.h>
namespace MNC
{
    class Matrix
    {
        private: 
          bool destroyAfter = true;
		  bool isProgmem = false;
          uint32_t rows, columns;  		  
        public:    
          float* data;  		
          Matrix(const uint32_t& r, const uint32_t& c);
		  Matrix(float (*op)(const uint32_t&,const uint32_t&));
          Matrix(const uint32_t& r, const uint32_t& c, float* arr, bool i_p);
          virtual ~Matrix();      
          void operator+=(const Matrix &m);
          Matrix operator*(const Matrix &m);
          virtual float at(const uint32_t& i, const uint32_t& j);
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
          uint32_t getIndex (const uint32_t& r,const uint32_t& c) const;
          void setTransposed(bool t);
          static Matrix fromArray(const uint32_t& r, const uint32_t& c, float* arr);   
    
    };

} // namespace Minerva