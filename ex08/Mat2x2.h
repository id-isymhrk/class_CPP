#include <iostream>

using namespace std;

class Mat2x2
{
protected:
    const size_t SIZE_COLIMN = 2;

    float **_value;

public:
    // constructor
    Mat2x2();
    Mat2x2(float *array);
    // copy
    Mat2x2(const Mat2x2 &mat);
    Mat2x2 &operator=(const Mat2x2 &mat);

    Mat2x2 operator+(const Mat2x2 &mat);
    Mat2x2 operator-(const Mat2x2 &mat);
    Mat2x2 operator*(const Mat2x2 &mat);
    Mat2x2 &operator+=(const Mat2x2 &mat);
    Mat2x2 &operator-=(const Mat2x2 &mat);
    Mat2x2 &operator*=(const Mat2x2 &mat);

    Mat2x2 operator-() const;

    float operator()(const int &i, const int &j);

    bool operator==(const Mat2x2 &mat);

    friend ostream &operator<<(ostream &os, const Mat2x2 &mat);

    ~Mat2x2();
};