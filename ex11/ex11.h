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
            for (BiDirIt sorted = begin; sorted != it; sorted++)
            {
                if (*it < *sorted)
                {
                    // cout << "check:" << *it << endl;
                    for (BiDirIt s = it; s != sorted; s--)
                    {
                        iter_swap(s, s - 1);
                    }

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