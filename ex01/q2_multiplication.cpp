#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

const int MAX_BIT = 64;

// void Multiplication(unsigned long a1, unsigned long b1)
// {
//     vector<int> calc;

//     // init
//     calc.resize(sizeof(unsigned long) * CHAR_BIT);
//     for (int i = 0; i < calc.size(); i++)
//     {
//         calc[i] = 0;
//     }

//     // bit calc
//     for (int i = 0; i < sizeof(unsigned long); i++)
//     {

//         if (a1 & 1 << i)
//         {
//             for (int j = 0; j < sizeof(unsigned long); j++)
//             {
//                 if (b1 & 1 << j)
//                 {
//                     calc[j + i]++; //桁をずらして加算していく
//                 }
//                 // cout << "test:calc[" << j + i << "]=" << calc[j + i] << endl;
//             }
//         }

//         //桁上げの処理
//         calc[i + 1] += calc[i] / 2;
//         calc[i] = calc[i] % 2;
//     }

//     // output
//     cout << "answer(vector) :";
//     for (int i = calc.size() - 1; i >= 0; i--)
//     {
//         cout << calc[i];
//     }
//     cout << endl;
// }

void Add(unsigned long &a2, int digit_)
{
    int tmp = a2;
    unsigned long digit = digit_;
    if (tmp >> digit & 1) //該当の桁が既に１かどうかの判定
    {
        //桁上げ
        a2 ^= (unsigned long)1 << digit;

        //ひとつ上の桁でも桁上げが生じるか計算する
        Add(digit, 0); //算術演算子が使えないのでAddで次の桁を指せる準備
        Add(a2, digit);
    }
    else
    {
        //普通に足し算
        a2 |= (unsigned long)1 << digit;
        // cout << "Add:digit " << digit;
        // cout << "   Add:a2 " << bitset<MAX_BIT>(a2) << endl;
    }
}

void Multiplication2(unsigned long a1, unsigned long b1)
{
    unsigned long ans = 0;
    unsigned long tmp_a, tmp_b, tmp_i;
    // bit calc
    for (int i = 0; i < MAX_BIT; i++)
    {
        tmp_a = a1;

        // if (a1 & 1 << i)
        if (tmp_a >> i & 1) // aの２進数上の桁全てから１を判定
        {
            for (int j = 0; j < MAX_BIT; j++)
            {
                tmp_b = b1;
                // if (b1 & 1 << j)
                if (tmp_b >> j & 1) //２進数上のbの全ての桁で１を判定。１だった桁の加算を行う
                {
                    // cout << "i=" << i << " j=" << j << "  Call Add" << endl;
                    // Add(ans, i + j);

                    tmp_i = i;
                    // cout << "i: " << i << endl;
                    // cout << "j: " << j << endl;
                    for (int k = 0; k < j; k++)
                    {
                        Add(tmp_i, 0); // tmp_iをj回加算する → imp_i=i+j
                    }
                    // cout << "tmp_i: " << tmp_i << endl;

                    Add(ans, tmp_i); // tmp_i(i+j)の桁に１を足す

                    // cout << "Multi:ans: " << bitset<MAX_BIT>(ans) << endl;
                }
            }
        }
    }

    // output
    cout << "answer(bit)    :";
    cout << bitset<MAX_BIT>(ans);
    cout << endl;
}

int main()
{
    // vector<unsigned long> test1 = {1, 3};
    // vector<unsigned long> test2 = {1, 2};
    vector<unsigned long> test1 = {536870912};
    vector<unsigned long> test2 = {805306368};
    // vector<unsigned long> test1 = {1, 5, 10, 12, 33, 51, 2, 100, 682, 536870912};
    // vector<unsigned long> test2 = {1, 4, 11, 6, 3, 20, 4, 8, 1365, 805306368};
    const int LOOP_NUM = test1.size() > test2.size() ? test1.size() : test2.size();

    for (int i = 0; i < LOOP_NUM; i++)
    {
        cout << "----------" << endl;
        cout << "test1:" << test1[i] << endl;
        cout << "test1(bit):" << bitset<MAX_BIT>(test1[i]) << endl;
        cout << "test2:" << test2[i] << endl;
        cout << "test2(bit):" << bitset<MAX_BIT>(test2[i]) << endl;
        cout << "answer:" << test1[i] * test2[i] << endl;
        cout << "answer(default):" << bitset<MAX_BIT>(test1[i] * test2[i]) << endl;
        // Multiplication(test1[i], test2[i]);
        Multiplication2(test1[i], test2[i]);
    }

    return 0;
}