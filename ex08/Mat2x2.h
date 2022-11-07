#include <iostream>

using namespace std;

class Mat2x2
{
protected:
    const size_t MATRIX_SIZE = 2;

    float **_value;

public:
    Mat2x2();
    Mat2x2(float *array);

    Mat2x2 &operator+(const Mat2x2 &mat);
    Mat2x2 &operator-(const Mat2x2 &mat);
    Mat2x2 &operator*(const Mat2x2 &mat);
    Mat2x2 &operator+=(const Mat2x2 &mat);
    Mat2x2 &operator-=(const Mat2x2 &mat);
    Mat2x2 &operator*=(const Mat2x2 &mat);

    float &operator()(const int &i, const int &j);

    bool &operator==(const Mat2x2 &mat);

    friend ostream &operator<<(ostream &os, const Mat2x2 &mat);

    ~Mat2x2();
};