#include "Matrix.h"


Matrix::Matrix(const INT_MNC& r, const INT_MNC& c)
{
    this->rows = r;
    this->columns = c;
    data = new float[rows * columns]();
}
Matrix::Matrix(const INT_MNC& r, const INT_MNC& c, float *arr)
{
    data = arr;
    this->rows = r;
    this->columns = c;
    destroyAfter = false;
}

Matrix::~Matrix()
{
    if (destroyAfter)
        delete[] data;
}

Matrix::Matrix(bool da)
{
    destroyAfter = da;
}

void Matrix::printDebug() const
{

    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            Serial.print(at(i, j));
            Serial.print(" ");
        }
        Serial.println("");
    }
    Serial.println("");
}

Matrix Matrix::fromArray(const INT_MNC& r, const INT_MNC& c, float *arr)
{
    Matrix m(r, c);
    memcpy(m.data, arr, sizeof(float) * r * c);
    return m;
}

float Matrix::at(const INT_MNC& i, const INT_MNC& j) const
{
        return data[getIndex(i, j)];
}

INT_MNC Matrix::getIndex(const INT_MNC& r, const INT_MNC& c) const
{
    return r * columns + c;
}