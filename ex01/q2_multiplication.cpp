#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

// bitset<sizeof(unsigned long)> Multiplication(unsigned long a1, unsigned long b1)
// {
//     // unsigned long ans;
//     // bitset<sizeof(unsigned long)> a2 = bitset<sizeof(unsigned long)>(a1);
//     // bitset<sizeof(unsigned long)> b2 = bitset<sizeof(unsigned long)>(b1);
//     // unsigned long divide = sizeof(unsigned long);

//     bitset<sizeof(unsigned long)> ans = 0x00000000;
//     ans = bitset<sizeof(unsigned long)>(a1 * b1);

//     return ans;
// }

void Multiplication(unsigned long a1, unsigned long b1)
{

    // vector<vector<int>> calc;
    vector<int> calc;

    // init
    calc.resize(sizeof(unsigned long) * CHAR_BIT);
    for (int i = 0; i < calc.size(); i++)
    {
        calc[i] = 0;
    }

    // bit calc
    for (int i = 0; i < sizeof(unsigned long); i++)
    {
        if (a1 & 1 << i)
        {
            for (int j = 0; j < sizeof(unsigned long); j++)
            {
                // calc[i][j] += (b1 & 1 << j);
                if (b1 & 1 << j)
                    calc[j + i]++;
                // cout << "test:calc[" << j + i << "]=" << calc[j + i] << endl;
            }

            // calc[i + 1][j] = calc[i][j]
        }

        calc[i + 1] += calc[i] / 2;
        calc[i] = calc[i] % 2;
    }

    // output
    cout << "answer(bit):";
    for (int i = calc.size() - 1; i >= 0; i--)
    {
        cout << calc[i];
    }
    cout << endl;
}

int main()
{
    vector<unsigned long> test1 = {5, 10, 12, 33, 51, 2, 100};
    vector<unsigned long> test2 = {4, 11, 6, 3, 20, 4, 8};
    const int LOOP_NUM = test1.size() > test2.size() ? test1.size() : test2.size();

    for (int i = 0; i < LOOP_NUM; i++)
    {
        cout << "----------" << endl;
        cout << "test1:" << test1[i] << endl;
        // cout << "test1(bit):" << bitset<sizeof(unsigned long)>(test1[i]) << endl;
        cout << "test2:" << test2[i] << endl;
        // cout << "test2(bit):" << bitset<sizeof(unsigned long)>(test2[i]) << endl;
        cout << "answer:" << test1[i] * test2[i] << endl;
        cout << "answer(bit):" << bitset<sizeof(unsigned long) * CHAR_BIT>(test1[i] * test2[i]) << endl;
        // cout << "answer(bit):" << Multiplication(test1[i], test2[i]) << endl;
        Multiplication(test1[i], test2[i]);
    }

    return 0;
}