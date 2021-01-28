#include "FullyConnected.h"

FullyConnected::FullyConnected(INT_MNC p_c, Activation::ActivationType act, INT_MNC l_Id)
	: Layer(act, l_Id)
{
	this->p_count = p_c;
}

void FullyConnected::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, MNC::Matrix *w, MNC::Matrix *b)
{
	this->i_size = inX * inY * inZ;
	weights = w;
	bias = b;
}

void FullyConnected::getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ)
{
	outX = 1;
	outY = p_count;
	outZ = 1;
}

float FullyConnected::get_result(const MNC::Matrix &in, INT_MNC p_id, Layer **layers)
{
	if (isCacheEnabled() && cached)
	{
		return cache[p_id];
	}
	float a = 0;
	for (uint32_t i = 0; i < i_size; i++)
	{

		if (layerId == 0)
		{
			a += in.at(i, 0) * weights->at(p_id, i);
		}
		else
		{
			a += layers[layerId - 1]->get_result(in, i, layers) * weights->at(p_id, i);
		}
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
