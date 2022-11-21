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
    vector<float>::iterator iter = array.begin() + array.size() / 2;
    nth_element(array.begin(), iter, array.end());

    ShowVector(array);

    return array[array.size() / 2];
}