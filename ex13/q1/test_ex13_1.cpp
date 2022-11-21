#include "ex13_q1_Myheader.h"

int main()
{
    vector<float> test = {0.0, 0.1, 0.4, 0.3, 0.1, 1.0, 0.5, 0.7, 0.4};
    cout << "---input---" << endl;
    ShowVector(test);
    cout << "---output---" << endl;
    float ans = compute_median(test);
    cout << "Median:" << ans << endl;

    return 0;
}