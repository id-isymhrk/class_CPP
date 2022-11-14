#include "ex11.h"

constexpr bool FLAG_TEST = true;

int main()
{
    if (FLAG_TEST)
    {
        vector<vector<int>> test_int{
            {0, 9, 8, 7, 6, 5, 4, 3, 2, 1},
            {12, 3, 15, 0, 96, 33, 123, 52},
        };
        vector<vector<double>> test_double{
            {0.1, 0.3, 0.5, 0.7, 0.9, 1.1, -4, 3.6},
        };

        //////////////input///////////////////////
        cout << "---input test_int---" << endl;
        for (size_t i = 0; i < test_int.size(); i++)
        {
            cout << "No." << i << ":";
            show_vector(test_int[i]);
            cout << endl;
            PL4::sort(test_int[i].begin(), test_int[i].end());
        }
        cout << endl;
        cout << "---input test_double---" << endl;
        for (size_t i = 0; i < test_double.size(); i++)
        {
            cout << "No." << i << ":";
            show_vector(test_double[i]);
            cout << endl;
            PL4::sort(test_double[i].begin(), test_double[i].end());
        }
        cout << endl;

        //////////////output///////////////////////
        cout << "---output test_int---" << endl;
        for (size_t i = 0; i < test_int.size(); i++)
        {
            cout << "No." << i << ":";
            show_vector(test_int[i]);

            cout << endl;
        }
        cout << endl;
        cout << "---output test_double---" << endl;
        for (size_t i = 0; i < test_double.size(); i++)
        {
            cout << "No." << i << ":";
            show_vector(test_double[i]);

            cout << endl;
        }
        cout << endl;
    }
    else
    {
        static int n;
        static double tmp;
        vector<double> array;

        cout << "---input array length---" << endl;
        cin >> n;
        cout << endl;
        for (int i = 0; i < n; i++)
        {
            cout << "---input Number yourself---" << endl;
            cin >> tmp;
            array.push_back(tmp);
        }
        cout << endl;
        cout << "---Result Sorting---" << endl;
        show_vector(array);
        cout << endl;
    }
    return 0;
}