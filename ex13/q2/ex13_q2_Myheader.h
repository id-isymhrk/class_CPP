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

vector<float> compute_k_closest(int k, vector<float> array)
{
    vector<float> ans;
    for (size_t i = 0; i < k; i++)
    {
        vector<float>::iterator iter = max_element(array.begin(), array.end());
        cout << "max:" << i << " is " << *iter << endl;
        ans.push_back(*iter);
        ShowVector(array);
        array.erase(iter);
    }

    return ans;
}