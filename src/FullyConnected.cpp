#include "FullyConnected.h"

FullyConnected::FullyConnected(INT_MNC p_c, Activation::ActivationType act, INT_MNC l_Id)
	: Layer(act, l_Id)
{
	this->p_count = p_c;
}

void FullyConnected::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix *w, Matrix *b)
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

float FullyConnected::get_result(const Matrix &in, INT_MNC p_id, Layer **layers)
{
	if (isCacheEnabled() && cached)
	{
		return cache[p_id];
	}
	float a = 0;
	for (uint32_t i = 0; i < i_size; i++)
	{
        float b = layerId == 0 ? in.at(i, 0) : layers[layerId - 1]->get_result(in, i, layers);
		a += b * weights->at(p_id, i);
	}
	a += bias->at(p_id, 0);
	Activation::activate(a, activationType);

	if (isCacheEnabled())
	{
		cache[p_id] = a;
	}
	if (p_id == p_count - 1)
		cached = true;
	return a;
}
