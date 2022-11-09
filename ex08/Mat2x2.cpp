#include "Mat2x2.h"

Mat2x2::Mat2x2()
{
    _value = new float *[SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        _value[i] = new float[SIZE_COLIMN];
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            _value[i][j] = 1;
        }
    }
}

Mat2x2::Mat2x2(float *array)
{
    int index = 0;

    _value = new float *[SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {

        _value[i] = new float[SIZE_COLIMN];
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            _value[i][j] = array[index];

            index++;
        }
    }
}

Mat2x2 Mat2x2::operator+(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    int index = 0;

    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[index] = this->_value[i][j] + mat._value[i][j];
            index++;
        }
    }

    return Mat2x2(ref_array);
}
Mat2x2 Mat2x2::operator-(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    int index = 0;
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[index] = this->_value[i][j] - mat._value[i][j];
            index++;
        }
    }
    return Mat2x2(ref_array);
}
Mat2x2 Mat2x2::operator*(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    float tmp = 0;
    int index = 0;
    for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
    {
        ref_array[i] = 0;

        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[i] += this->_value[i / SIZE_COLIMN][j] * mat._value[j][i / SIZE_COLIMN];
        }

        // if (i < SIZE_COLIMN)
        // {
        //     for (size_t j = 0; j < SIZE_COLIMN; j++)
        //     {
        //         ref_array[i] += this->_value[0][j] * mat._value[j][0];
        //     }
        // }
        // else
        // {
        //     for (size_t j = 0; j < SIZE_COLIMN; j++)
        //     {
        //         ref_array[i] += this->_value[1][j] * mat._value[j][1];
        //     }
        // }
    }

    return Mat2x2(ref_array);
}
Mat2x2 &Mat2x2::operator+=(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
        }
    }
}
Mat2x2 &Mat2x2::operator-=(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
        }
    }
}
Mat2x2 &Mat2x2::operator*=(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
        }
    }
}

float &Mat2x2::operator()(const int &i, const int &j)
{
}

bool &Mat2x2::operator==(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
        }
    }
}

ostream &operator<<(ostream &os, const Mat2x2 &mat)
{
    for (size_t i = 0; i < mat.SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < mat.SIZE_COLIMN; j++)
        {
            os << " " << mat._value[i][j];
        }
        os << endl;
    }

    return os;
}

Mat2x2::~Mat2x2()
{
}