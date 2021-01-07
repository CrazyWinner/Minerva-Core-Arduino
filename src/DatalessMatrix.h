#pragma once
#include "Matrix.h"
struct DatalessMatrix : public LN::Matrix
{
    float (*atPtr)(uint16_t, uint16_t);

    float at(uint16_t i, uint16_t j)
    {
        return atPtr(i, j);
    }
    DatalessMatrix(float (*op)(uint16_t, uint16_t)) : LN::Matrix(op)
    {
        atPtr = op;
    };
    ~DatalessMatrix()
    {
    }
};