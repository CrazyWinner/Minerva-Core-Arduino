#include "Layer.h"
void Layer::enableCache(bool e)
{
	if (e != cacheEnabled)
	{
		if (e)
		{
			INT_MNC outX, outY, outZ;
			getOutDimensions(outX, outY, outZ);
			cache = new float[outX * outY * outZ];
		}
		else
		{
			delete[] cache;
			cache = nullptr;
		}

		cacheEnabled = e;
	}
}
void Layer::resetCache()
{
	cached = false;
}

Layer::Layer(Activation::ActivationType act, INT_MNC l_Id)
{
	this->layerId = l_Id;
	this->activationType = act;
}

Layer::~Layer()
{
	if (deleteAfter)
	{
		delete bias;
		delete weights;
	}
	if (cacheEnabled)
	{
		delete[] cache;
	}
}

bool Layer::isCacheEnabled()
{
	return cacheEnabled;
}