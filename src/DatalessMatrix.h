#pragma once
#include "Matrix.h"
#include "DEFINE_INT.h"
struct DatalessMatrix : public Matrix3D
{
    float (*atPtr)(const INT_MNC&, const INT_MNC&, const INT_MNC&);

    float at(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const 
    {
        return atPtr(x, y, z);
    }
    DatalessMatrix(float (*op)(const INT_MNC&, const INT_MNC&, const INT_MNC&)) : Matrix3D(false)
    {
        atPtr = op;
    };
    ~DatalessMatrix()
    {
    }
};