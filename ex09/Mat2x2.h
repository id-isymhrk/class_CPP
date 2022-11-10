#include <iostream>

using namespace std;

template <class T, int N>
class Mat2x2
{
protected:
    const size_t SIZE_COLIMN = N;

    T **_value;

public:
    // constructor
    Mat2x2()
    {
        _value = new T *[SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            _value[i] = new T[SIZE_COLIMN];
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                _value[i][j] = 1;
            }
        }
    };
    Mat2x2(T *array)
    {
        int index = 0;

        _value = new T *[SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {

            _value[i] = new T[SIZE_COLIMN];
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                _value[i][j] = array[index];

                index++;
            }
        }
    };

    // copy
    Mat2x2(const Mat2x2 &mat)
    {
        _value = new T *[SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {

            _value[i] = new T[SIZE_COLIMN];
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                _value[i][j] = mat._value[i][j];
            }
        }
    };
    Mat2x2 &operator=(const Mat2x2 &mat)
    {
        delete[] this->_value;

        this->_value = new T *[SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {

            this->_value[i] = new T[SIZE_COLIMN];
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                this->_value[i][j] = mat._value[i][j];
            }
        }

        return *this;
    };

    Mat2x2 operator+(const Mat2x2 &mat)
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
    };
    Mat2x2 operator-(const Mat2x2 &mat)
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
    };
    Mat2x2 operator*(const Mat2x2 &mat)
    {
        float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
        {
            ref_array[i] = 0;

            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[i] += this->_value[i / SIZE_COLIMN][j] * mat._value[j][i / SIZE_COLIMN];
            }
        }

        return Mat2x2(ref_array);
    };
    Mat2x2 &operator+=(const Mat2x2 &mat)
    {
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                this->_value[i][j] += mat._value[i][j];
            }
        }

        return *this;
    };
    Mat2x2 &operator-=(const Mat2x2 &mat)
    {
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                this->_value[i][j] -= mat._value[i][j];
            }
        }

        return *this;
    };
    Mat2x2 &operator*=(const Mat2x2 &mat)
    {
        float *ref_array = new float[SIZE_COLIMN * SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
        {
            ref_array[i] = 0;

            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[i] += this->_value[i / SIZE_COLIMN][j] * mat._value[j][i / SIZE_COLIMN];
            }
        }

        *this = Mat2x2(ref_array);

        return *this;
    };

    T operator()(const int &i, const int &j)
    {
        return _value[i][j];
    };

    bool operator==(const Mat2x2 &mat)
    {
        bool flag_equal = true;

        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                if (this->_value[i][j] != mat._value[i][j])
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
    };

    template <class U, int M>
    friend ostream &operator<<(ostream &os, const Mat2x2<U, M> &mat)
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
    };

    ~Mat2x2()
    {
        delete[] _value;
    };
};