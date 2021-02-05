#pragma once
#include "Matrix.h"
#include "DEFINE_INT.h"
struct Matrix_P : public Matrix3D
{

    float at(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const;
	Matrix_P(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr);

};