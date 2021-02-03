#include "Matrix_P.h"
Matrix_P::Matrix_P(const INT_MNC& r, const INT_MNC& c, float *arr) : Matrix(r, c, arr)
{
	
}

float Matrix_P::at(const INT_MNC& i, const INT_MNC& j) const
{
	float a = 0;
    memcpy_P(&a, data + getIndex(i, j), 4);
    return a;
}