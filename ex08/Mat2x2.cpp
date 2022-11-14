#include "Mat2x2.h"

Mat2x2::Mat2x2()
{
    _value = new float *[SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        _value[i] = new float[SIZE_COLIMN];
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            if (i == j)
            {
                _value[i][j] = 1;
            }
            else
            {
                _value[i][j] = 0;
            }
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
    }

    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            _value[j][i] = array[index];

            index++;
        }
    }
}

// copy
Mat2x2::Mat2x2(const Mat2x2 &mat)
{
    _value = new float *[SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {

        _value[i] = new float[SIZE_COLIMN];
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            _value[i][j] = mat._value[i][j];
        }
    }
}
Mat2x2 &Mat2x2::operator=(const Mat2x2 &mat)
{
    delete[] this->_value;

    this->_value = new float *[SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {

        this->_value[i] = new float[SIZE_COLIMN];
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            this->_value[i][j] = mat._value[i][j];
        }
    }

    return *this;
}

Mat2x2 Mat2x2::operator+(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    int index = 0;

    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[index] = this->_value[j][i] + mat._value[j][i];
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
            ref_array[index] = this->_value[j][i] - mat._value[j][i];
            index++;
        }
    }
    return Mat2x2(ref_array);
}
Mat2x2 Mat2x2::operator*(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
    {
        ref_array[i] = 0;

        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[i] += this->_value[j][i % SIZE_COLIMN] * mat._value[i / SIZE_COLIMN][j];
        }
    }

    return Mat2x2(ref_array);
}
Mat2x2 &Mat2x2::operator+=(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            this->_value[i][j] += mat._value[i][j];
        }
    }

    return *this;
}
Mat2x2 &Mat2x2::operator-=(const Mat2x2 &mat)
{
    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            this->_value[i][j] -= mat._value[i][j];
        }
    }

    return *this;
}
Mat2x2 &Mat2x2::operator*=(const Mat2x2 &mat)
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
    {
        ref_array[i] = 0;

        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            ref_array[i] += this->_value[j][i % SIZE_COLIMN] * mat._value[i / SIZE_COLIMN][j];
        }
    }

    *this = Mat2x2(ref_array);

    return *this;
}

Mat2x2 Mat2x2::operator-() const
{
    float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
    int index = SIZE_COLIMN * SIZE_COLIMN - 1;

    float n1 = 1, n2 = 1;

    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            if (i == j)
            {
                ref_array[index] = this->_value[i][j];
                n1 *= this->_value[i][j];
            }
            else
            {
                ref_array[index] = -this->_value[i][j];
                n2 *= this->_value[i][j];
            }
            index--;
        }
    }
    // cout << "--test--" << endl;
    // cout << Mat2x2(ref_array) << endl;
    // cout << (n1 - n2) << endl;
    for (int i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
    {
        ref_array[i] /= (n1 - n2);
    }

    return Mat2x2(ref_array);
}
float Mat2x2::operator()(const int &i, const int &j)
{
    return _value[i][j];
}

bool Mat2x2::operator==(const Mat2x2 &mat)
{
    const static double judge = 1.0e-20;
    float tmp;
    bool flag_equal = true;

    for (size_t i = 0; i < SIZE_COLIMN; i++)
    {
        for (size_t j = 0; j < SIZE_COLIMN; j++)
        {
            tmp = this->_value[i][j] - mat._value[i][j];
            if (tmp < -judge || judge < tmp)
            {
                flag_equal = false;
                break;
            }
        }

        if (!flag_equal)
        {
            break;
        }
    }

    return flag_equal;
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
    delete[] _value;
}