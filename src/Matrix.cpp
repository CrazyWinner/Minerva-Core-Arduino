#include "Matrix.h"


Matrix3D::Matrix3D(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ)
{
	sizeX = sX;
	sizeY = sY;
	sizeZ = sZ;
    data = new float[sX * sY * sZ]();
}
Matrix3D::Matrix3D(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr)
{
    data = arr;
	sizeX = sX;
	sizeY = sY;
	sizeZ = sZ;
    destroyAfter = false;
}

Matrix3D::~Matrix3D()
{
    if (destroyAfter)
        delete[] data;
}

Matrix3D::Matrix3D(bool da)
{
    destroyAfter = da;
}

void Matrix3D::set(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z, const float& a){
	data[getIndex(x,y,z)] = a;
}

void Matrix3D::printDebug() const
{

    for (int y = 0; y < sizeY; y++)
    {
        for (int x = 0; x < sizeX; x++)
        {
            Serial.print(at(x, y, 0));
            Serial.print(" ");
        }
        Serial.println("");
    }
    Serial.println("");
}

Matrix3D Matrix3D::fromArray(const INT_MNC& sX, const INT_MNC& sY, const INT_MNC& sZ, float *arr)
{
    Matrix3D m(sX, sY, sZ);
    memcpy(m.data, arr, sizeof(float) * sX * sY * sZ);
    return m;
}

float Matrix3D::at(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const
{
        return data[getIndex(x,y,z)];
}

INT_MNC Matrix3D::getIndex(const INT_MNC& x, const INT_MNC& y, const INT_MNC& z) const
{
    return z * sizeX * sizeY + y * sizeX + x;
}