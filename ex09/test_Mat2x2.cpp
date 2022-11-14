#include "Mat2x2.h"

int main()
{
    Mat2x2<float, 2> origin = Mat2x2<float, 2>();
    // float *test_array = new float[4];
    float array[] = {1.0, 2.0, 3.0, 4.0};
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

    cout << "-test_mat" << endl;
    cout << -test_mat << endl;

    cout << "test_mat*-test_mat" << endl;
    cout << test_mat * (-test_mat) << endl;
    cout << endl
         << endl;

    int test_array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int test2_array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    Mat2x2<int, 3> test = Mat2x2<int, 3>(test_array);
    Mat2x2<int, 3> test2 = Mat2x2<int, 3>(test2_array);

    cout << "test" << endl;
    cout << test << endl;
    cout << "test2" << endl;
    cout << test2 << endl;
    cout << "test + test2" << endl;
    cout << test + test2 << endl;
    cout << "test - test2" << endl;
    cout << test - test2 << endl;

    cout << "-test" << endl;
    cout << -test << endl;

    cout << "test * -test" << endl;
    cout << test * (-test) << endl;
    return 0;
}