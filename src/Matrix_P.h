#pragma once
#include "Matrix.h"
#include "DEFINE_INT.h"
struct Matrix_P : public Matrix
{

    float at(const INT_MNC& i, const INT_MNC& j) const;
	Matrix_P(const INT_MNC& r, const INT_MNC& c, float *arr);
};