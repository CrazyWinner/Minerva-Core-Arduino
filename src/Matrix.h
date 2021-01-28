#pragma once
#include <Arduino.h>
#include "DEFINE_INT.h"
namespace MNC
{
  class Matrix
  {
  private:
    bool destroyAfter = true;
    bool isProgmem = false;
    INT_MNC rows, columns;

  public:
    float *data;
    Matrix(const INT_MNC& r, const INT_MNC& c);
    Matrix(float (*op)(const INT_MNC&, const INT_MNC&));
    Matrix(const INT_MNC& r, const INT_MNC& c, float *arr, bool i_p);
    virtual ~Matrix();
    void operator+=(const Matrix &m);
    Matrix operator*(const Matrix &m);
    virtual float at(const INT_MNC& i, const INT_MNC& j);
    Matrix transpose();
    void doOperation(void (*op)(float &));
    Matrix operator-(const Matrix &m);
    void operator=(const Matrix &m);
    void hadamard(const Matrix &m);
    void operator*=(float f);
    void randomize();
    void fill();
    void operator-=(const Matrix &m);
    void printDebug();
    INT_MNC getIndex(const INT_MNC& r, const INT_MNC& c) const;
    void setTransposed(bool t);
    static Matrix fromArray(const INT_MNC& r, const INT_MNC& c, float *arr);
  };

} // namespace MNC