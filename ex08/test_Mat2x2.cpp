#include "Mat2x2.h"

int main()
{
    Mat2x2 origin = Mat2x2();
    // float *test_array = new float[4];
    float array[] = {1.0, 1.0, 1.0, 1.0};
    Mat2x2 test_mat = Mat2x2(array);
    Mat2x2 tmp;

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

    return 0;
}