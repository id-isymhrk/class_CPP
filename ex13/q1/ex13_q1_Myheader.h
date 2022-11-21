#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template <class T>
void ShowVector(vector<T> array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        cout << array[i] << endl;
    }
}

float compute_median(vector<float> array)
{
    float ans = 0.0;

    vector<float>::iterator iter = array.begin() + array.size() / 2;
    nth_element(array.begin(), iter, array.end());
    ans += *iter;
    array.erase(iter);

    iter = array.begin() + array.size() / 2;
    nth_element(array.begin(), iter, array.end());
    ans += *iter;

    return ans / 2.0;
}