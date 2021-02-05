#pragma once
#include <Arduino.h>
#include "DEFINE_INT.h"

  class Matrix3D
  {
  private:
    bool destroyAfter = true;
    INT_MNC sizeX, sizeY, sizeZ;

  public:
    float *data;
    Matrix3D(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ);
    Matrix3D(bool da);
    Matrix3D(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr);
    virtual ~Matrix3D();
    virtual float at(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const;
	void set(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z, const float& a);
    void printDebug() const;
    INT_MNC getIndex(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const;
    static Matrix3D fromArray(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr);
  };

