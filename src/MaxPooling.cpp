#include "MaxPooling.h"

MaxPooling::MaxPooling(const INT_MNC& sizeX, const INT_MNC& sizeY, INT_MNC l_Id)
: Layer(0, l_Id)
{
    pooling_size_X = sizeX;
    pooling_size_Y = sizeY;
}



void MaxPooling::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix *w, Matrix *b)
{
    i_X = inX;
    i_Y = inY;
    i_Z = inZ;
}


void MaxPooling::getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const
{
    outX = i_X / pooling_size_X;
    if(outX * pooling_size_X < i_X) outX++;
    outY = i_Y / pooling_size_Y;
    if(outY * pooling_size_Y < i_Y) outY++;
    outZ = i_Z;
}

float MaxPooling::get_result(const Matrix &in, INT_MNC p_id, Layer **layers)
{
	INT_MNC outX, outY, outZ;
    getOutDimensions(outX, outY, outZ);
	if (isCacheEnabled() && cached)
	{
		return cache[p_id];
	}
	
	INT_MNC x, y, z;
	z = p_id / (outX * outY);
	x = p_id % (outX * outY);
	y = (x / outX) * pooling_size_Y;
	x = (x % outX) * pooling_size_X;
	INT_MNC i = (z * i_X * i_Y) + y * i_X + x; 
	float a = layerId == 0 ? in.at(i, 0) : layers[layerId - 1]->get_result(in, i, layers);
	for(INT_MNC dy = 0; dy < pooling_size_Y; dy++){
		 for(INT_MNC dx = 0; dx < pooling_size_X; dx++){
             if((y + dy) >= i_Y || (x + dy) >= i_X) continue;
			 if(dx == 0 && dy == 0) continue;
			    i = (z * i_X * i_Y) + (y + dy) * i_X + x + dx; 
				float b = layerId == 0 ? in.at(i, 0) : layers[layerId - 1]->get_result(in, i, layers);
				if(b > a ){
					a = b;
				}
	}
	}
    

	if (isCacheEnabled())
	{
		cache[p_id] = a;
	}
	
	if (p_id == outX * outY * outZ - 1)
		cached = true;
	
	return a;
}

