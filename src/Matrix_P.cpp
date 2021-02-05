#include "Matrix_P.h"
Matrix_P::Matrix_P(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr) : Matrix3D(sX, sY, sZ, arr)
{
	
}

float Matrix_P::at(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const
{
	float a = 0;
    memcpy_P(&a, data + getIndex(x, y, z), 4);
    return a;
}