#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

namespace PL4
{
    template <class BiDirIt>
    void sort(BiDirIt begin, BiDirIt end)
    {
        for (BiDirIt it = begin + 1; it != end; it++)
        {
            for (BiDirIt it2 = begin; it2 != it; it2++)
            {
                if (*it < *it2)
                {
                    // cout << "check:" << *it << endl;
                    iter_swap(it, it2); //ここでforが巻き戻る

                    // for (BiDirIt a = begin; a != end; a++)
                    // {
                    //     cout << " " << *a;
                    // }
                    // cout << endl;
                }
            }
        }
    }
}

template <class T>
void show_vector(vector<T> vec)
{
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << " " << vec[i];
    }
}