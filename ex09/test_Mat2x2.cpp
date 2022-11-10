#include "Mat2x2.h"

int main()
{
    Mat2x2<float, 2> origin = Mat2x2<float, 2>();
    // float *test_array = new float[4];
    float array[] = {1.0, 0.0, 0.0, 1.0};
    Mat2x2<float, 2> test_mat = Mat2x2<float, 2>(array);

    cout << "origin" << endl;
    cout << origin << endl;
    cout << "test_mat" << endl;
    cout << test_mat << endl;
    cout << "origin + test" << endl;
    cout << origin + test_mat << endl;
    cout << "origin - test" << endl;
    cout << origin - test_mat << endl;
    cout << "origin * test" << endl;
    cout << origin * test_mat << endl;

    Mat2x2<float, 2> tmp = Mat2x2<float, 2>();
    cout << "operator+=" << endl;
    tmp += test_mat;
    cout << tmp << endl;

    Mat2x2<float, 2> tmp2 = Mat2x2<float, 2>();
    cout << "operator-=" << endl;
    tmp2 -= test_mat;
    cout << tmp2 << endl;

    Mat2x2<float, 2> tmp3 = Mat2x2<float, 2>();
    cout << "operator*=" << endl;
    tmp3 *= test_mat;
    cout << tmp3 << endl;

    cout << "operator==" << endl;
    if (tmp3 == (origin * test_mat))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
    cout << endl;

    cout << "origin*=origin" << endl;
    origin *= origin;
    cout << origin << endl;

    return 0;
}