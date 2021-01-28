#pragma once
#include "Matrix.h"
#include "DEFINE_INT.h"
struct DatalessMatrix : public MNC::Matrix
{
    float (*atPtr)(const INT_MNC&, const INT_MNC&);

    float at(const INT_MNC& i, const INT_MNC& j)
    {
        return atPtr(i, j);
    }
    DatalessMatrix(float (*op)(const INT_MNC&, const INT_MNC&)) : MNC::Matrix(op)
    {
        atPtr = op;
    };
    ~DatalessMatrix()
    {
    }
};