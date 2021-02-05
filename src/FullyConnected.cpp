#include "FullyConnected.h"

FullyConnected::FullyConnected(INT_MNC p_c, Activation::ActivationType act, INT_MNC l_Id)
	: Layer(act, l_Id)
{
	this->p_count = p_c;
}

void FullyConnected::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix3D *w, Matrix3D *b)
{
	this->i_size = inX * inY * inZ;
	weights = w;
	bias = b;
}

void FullyConnected::getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const
{
	outX = 1;
	outY = p_count;
	outZ = 1;
}

float FullyConnected::get_result(const Matrix3D &in, const INT_MNC& x,  const INT_MNC& y,  const INT_MNC& z, Layer **layers)
{
	if (isCacheEnabled() && cached)
	{
		return cache[y];
	}
	float a = 0;
	for (uint32_t i = 0; i < i_size; i++)
	{
        float b = layerId == 0 ? in.at(0, i, 0) : layers[layerId - 1]->get_result(in, 0, i, 0, layers);
		a += b * weights->at(i, y, 0);
	}
	a += bias->at(0, y, 0);
	Activation::activate(a, activationType);

	if (isCacheEnabled())
	{
		cache[y] = a;
		if (y == p_count - 1)
		cached = true;
	}

	return a;
}
