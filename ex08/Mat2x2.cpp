#include "Mat2x2.h"

Mat2x2::Mat2x2()
{
    _value = new float *[MATRIX_SIZE];
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {
        *_value = new float[MATRIX_SIZE];
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            _value[i][j] = 1;
        }
    }
}

Mat2x2::Mat2x2(float *array)
{
    int index = 0;

    _value = new float *[MATRIX_SIZE];
    for (size_t i = 0; i < MATRIX_SIZE; i++)
    {

        *_value = new float[MATRIX_SIZE];
        for (size_t j = 0; j < MATRIX_SIZE; j++)
        {
            _value[i][j] = array[index];

            index++;
        }
    }
}

Mat2x2 &Mat2x2::operator+(const Mat2x2 &mat)
{
}
Mat2x2 &Mat2x2::operator-(const Mat2x2 &mat)
{
}
Mat2x2 &Mat2x2::operator*(const Mat2x2 &mat)
{
}
Mat2x2 &Mat2x2::operator+=(const Mat2x2 &mat)
{
}
Mat2x2 &Mat2x2::operator-=(const Mat2x2 &mat)
{
}
Mat2x2 &Mat2x2::operator*=(const Mat2x2 &mat)
{
}

float &Mat2x2::operator()(const int &i, const int &j)
{
}

bool &Mat2x2::operator==(const Mat2x2 &mat)
{
}

ostream &operator<<(ostream &os, const Mat2x2 &mat)
{
}

Mat2x2::~Mat2x2()
{
}