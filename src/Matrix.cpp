#include "Matrix.h"

using namespace MNC;

Matrix::Matrix(const INT_MNC& r, const INT_MNC& c)
{
    this->rows = r;
    this->columns = c;
    this->isProgmem = false;
    data = new float[rows * columns]();
}
Matrix::Matrix(const INT_MNC& r, const INT_MNC& c, float *arr, bool i_p)
{
    data = arr;
    this->rows = r;
    this->columns = c;
    this->isProgmem = i_p;
    destroyAfter = false;
}
/*
void Matrix::doOperation(void (*op)(float &))
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            op(this->data[getIndex(i, j)]);
        }
    }
}
*/
Matrix::~Matrix()
{
    if (destroyAfter)
        delete[] data;
}
/*
void Matrix::operator+=(const Matrix &m)
{
    if (this->rows != m.rows || this->columns != m.columns)
        throw std::runtime_error("+= operation error!");
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            int index = getIndex(i, j);
            this->data[index] = this->data[index] + m.data[index];
        }
    }
}
*/
/*
WARNING: Transposed matrices will use the same pointer
DO NOT DELETE POINTER
*/

/*
Matrix Matrix::transpose()
{
    
    Matrix ret(this->columns, this->rows, this->data);
    ret.setTransposed(!this->isTransposed);
    return ret;
    
}
*/
/*
void Matrix::operator*=(const float &f)
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            int index = getIndex(i, j);
            this->data[index] = this->data[index] * f;
        }
    }
}
*/
/*
void Matrix::setTransposed(bool t){
    this->isTransposed = t;
}
*/
/*
Matrix Matrix::operator-(const Matrix &m)
{
    if (this->rows != m.rows || this->columns != m.columns)
        throw std::runtime_error("- operation error!");
    Matrix r(this->rows, this->columns);
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            int index = getIndex(i, j);
            r.data[index] = this->data[index] - m.data[index];
        }
    }
    return r;
}
*/
/*

void Matrix::operator=(const Matrix &m)
{
    if (this->rows * this->columns != m.rows * m.columns)
    {
        delete this->data;
        this->data = new float[m.rows * m.columns];
    }
    this->rows = m.rows;
    this->columns = m.columns;
    memcpy(this->data, m.data, sizeof(float) * m.rows * m.columns);
}
*/

/*
Matrix Matrix::operator*(const Matrix &m)
{
    if (this->columns != m.rows)
        throw std::runtime_error("* operation error!");
        
		Matrix r(this->rows, m.columns);
     
    
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < m.columns; j++)
        {
            for (int k = 0; k < this->columns; k++)
            {
                r.data[r.getIndex(i, j)] += this->data[getIndex(i, k)] * m.data[m.getIndex(k, j)];
            }
        }
    }
    return r;
}
*/
/*
void Matrix::randomize()
{
    
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
      //   this->data[getIndex(i, j)] = ((double)rand() / (RAND_MAX + 1.0)) - 0.5;
      //  this->data[getIndex(i, j)] = ((double)rand() / (RAND_MAX + 1.0) * 2 - 1);
        this->data[getIndex(i, j)] = i/(j+1);
        }
    }
}
*/
/*
void Matrix::fill()
{
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            this->data[getIndex(i, j)] = 0.5;
        }
    }
}
*/
/*
void Matrix::hadamard(const Matrix &m)
{
    if (this->rows != m.rows || this->columns != m.columns)
        throw std::runtime_error("hamard operation error!");
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            int index = getIndex(i, j);
            this->data[index] = this->data[index] * m.data[index];
        }
    }
}
*/
Matrix::Matrix(float (*op)(const INT_MNC&, const INT_MNC&))
{
    destroyAfter = false;
}
void Matrix::printDebug()
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
/*
void Matrix::operator-=(const Matrix &m)
{
    if (this->rows != m.rows || this->columns != m.columns)
        throw std::runtime_error("-= operation error!");
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->columns; j++)
        {
            int index = getIndex(i, j);
            this->data[index] = this->data[index] - m.data[index];
        }
    }
}
*/
float Matrix::at(const INT_MNC& i, const INT_MNC& j)
{
    if (!isProgmem)
        return data[getIndex(i, j)];
    float a = 0;
    memcpy_P(&a, data + getIndex(i, j), 4);
    return a;
}

INT_MNC Matrix::getIndex(const INT_MNC& r, const INT_MNC& c) const
{
    return r * columns + c;
}