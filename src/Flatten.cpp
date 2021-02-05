#include "Flatten.h"

Flatten::Flatten(INT_MNC l_Id)
	: Layer(Activation::RELU, l_Id)
{
	
}

void Flatten::init(const INT_MNC& inX, const INT_MNC& inY, const INT_MNC& inZ, Matrix3D *w, Matrix3D *b)
{
   i_X = inX;
   i_Y = inY;
   i_Z = inZ;
}

void Flatten::getOutDimensions(INT_MNC &outX, INT_MNC &outY, INT_MNC &outZ) const
{
	outX = 1;
	outY = i_X * i_Y * i_Z;
	outZ = 1;
}

float Flatten::get_result(const Matrix3D &in, const INT_MNC& x,  const INT_MNC& y,  const INT_MNC& z, Layer **layers)
{
	INT_MNC z1 = y / (i_X * i_Y);
	INT_MNC x1 = y % (i_X * i_Y); 
	INT_MNC y1 = x1 / i_X;
	x1 = x1 % i_X;
	return layerId == 0 ? in.at(x1, y1, z1) : layers[layerId - 1]->get_result(in, x1, y1, z1, layers);
}
