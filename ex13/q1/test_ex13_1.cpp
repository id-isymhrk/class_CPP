#include "ex13_q1_Myheader.h"

constexpr int TEST_INDEX = 2;

int main()
{
    // vector<float> test = {0.0, 0.1, 0.4, 0.3, 0.1, 1.0, 0.5, 0.7, 0.4};
    vector<vector<float>> test = {
        {0.05, 0.1, 0.4, 0.3, 0.1, 1.05, 0.5, 0.7, 0.4},
        {0.1, 0.3, 1.1, 0.1, 1.1, 1.1, 0.1, 0.1, 1.1},
        {62, 61, 40, 90, 100, 32, 46, 5, 77, 44},
    };
    cout << "---input---" << endl;
    ShowVector(test[TEST_INDEX]);
    cout << "---output---" << endl;
    float ans = compute_median(test[TEST_INDEX]);
    cout << "Median:" << ans << endl;

    return 0;
}