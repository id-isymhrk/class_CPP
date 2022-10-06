#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

bitset<sizeof(unsigned long)> Multiplication(unsigned long a1, unsigned long b1)
{
    // unsigned long ans;
    // bitset<sizeof(unsigned long)> a2 = bitset<sizeof(unsigned long)>(a1);
    // bitset<sizeof(unsigned long)> b2 = bitset<sizeof(unsigned long)>(b1);
    // unsigned long divide = sizeof(unsigned long);

    bitset<sizeof(unsigned long)> ans = 0x00000000;
    ans = bitset<sizeof(unsigned long)>(a1 * b1);

    return ans;
}

int main()
{
    vector<unsigned long> test1 = {5, 10, 12, 33, 51, 2, 100};
    vector<unsigned long> test2 = {4, 11, 6, 3, 20, 4, 8};
    const int LOOP_NUM = test1.size() > test2.size() ? test1.size() : test2.size();

    for (int i = 0; i < LOOP_NUM; i++)
    {
        cout << "answer:" << test1[i] * test2[i] << endl;
        // cout << "answer(bit):" << bitset<sizeof(unsigned long)>(test1[i] * test2[i]) << endl;
        cout << "answer(bit):" << Multiplication(test1[i], test2[i]) << endl;
    }

    return 0;
}