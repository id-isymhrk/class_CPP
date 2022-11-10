#include <iostream>

using namespace std;

// template <class T, int N>
// class MAt2x2;
// template <class T, int N>
// ostream &operator<<(ostream &os, const Mat2x2<T, N> &mat);

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
    Mat2x2(const Mat2x2<T, N> &mat)
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
    Mat2x2<T, N> &operator=(const Mat2x2<T, N> &mat)
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

    Mat2x2<T, N> operator+(const Mat2x2<T, N> &mat)
    {
        T *ref_array = new T[SIZE_COLIMN * SIZE_COLIMN];
        int index = 0;

        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[index] = this->_value[i][j] + mat._value[i][j];
                index++;
            }
        }

        return Mat2x2<T, N>(ref_array);
    };
    Mat2x2<T, N> operator-(const Mat2x2<T, N> &mat)
    {
        T *ref_array = new T[SIZE_COLIMN * SIZE_COLIMN];
        int index = 0;
        for (size_t i = 0; i < SIZE_COLIMN; i++)
        {
            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[index] = this->_value[i][j] - mat._value[i][j];
                index++;
            }
        }
        return Mat2x2<T, N>(ref_array);
    };
    Mat2x2<T, N> operator*(const Mat2x2<T, N> &mat)
    {
        T *ref_array = new T[SIZE_COLIMN * SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
        {
            ref_array[i] = 0;

            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[i] += this->_value[i / SIZE_COLIMN][j] * mat._value[j][i / SIZE_COLIMN];
            }
        }

        return Mat2x2<T, N>(ref_array);
    };
    Mat2x2<T, N> &operator+=(const Mat2x2<T, N> &mat)
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
    Mat2x2<T, N> &operator-=(const Mat2x2<T, N> &mat)
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
    Mat2x2<T, N> &operator*=(const Mat2x2<T, N> &mat)
    {
        T *ref_array = new T[SIZE_COLIMN * SIZE_COLIMN];
        for (size_t i = 0; i < SIZE_COLIMN * SIZE_COLIMN; i++)
        {
            ref_array[i] = 0;

            for (size_t j = 0; j < SIZE_COLIMN; j++)
            {
                ref_array[i] += this->_value[i / SIZE_COLIMN][j] * mat._value[j][i / SIZE_COLIMN];
            }
        }

        *this = Mat2x2<T, N>(ref_array);

        return *this;
    };

    T operator()(const size_t &i, const size_t &j) const
    {
        return _value[i][j];
    };

    bool operator==(const Mat2x2<T, N> &mat)
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

    ~Mat2x2()
    {
        delete[] _value;
    };
};

template class Mat2x2<int, 2>;
template class Mat2x2<float, 2>;
template class Mat2x2<int, 3>;
template class Mat2x2<float, 3>;

template <class U, int M>
ostream &operator<<(ostream &os, const Mat2x2<U, M> &mat)
{
    for (size_t i = 0; i < M; i++)
    {
        for (size_t j = 0; j < M; j++)
        {
            os << " " << mat(i, j);
        }
        os << endl;
    }

    return os;
};