#pragma once
#include "Matrix.h"
struct DatalessMatrix : public MNC::Matrix
{
    float (*atPtr)(const uint32_t&, const uint32_t&);

    float at(const uint32_t& i, const uint32_t& j)
    {
        return atPtr(i, j);
    }
    DatalessMatrix(float (*op)(const uint32_t&, const uint32_t&)) : MNC::Matrix(op)
    {
        atPtr = op;
    };
    ~DatalessMatrix()
    {
    }
};