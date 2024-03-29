#include <iostream>
#include <vector>
#include <bitset>
#include <climits>

using namespace std;

vector<unsigned long> test = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 105, 44, 64, 4294967295};

int parity(unsigned long val)
{
    val ^= val >> 32;
    val ^= val >> 16;
    val ^= val >> 8;
    val ^= val >> 4;
    val ^= val >> 2;
    val ^= val >> 1;

    return 0x00000001 & (val ^ 0x00000001);
}

int main()
{
    for (int i = 0; i < test.size(); i++)
    {
        cout << "input:" << test[i] << endl;
        cout << "input:" << bitset<8>(test[i]) << endl;
        cout << "input:" << bitset<sizeof(long) * CHAR_BIT>(test[i]) << endl;
        cout << "result:" << parity(test[i]) << endl;
        cout << endl;
    }
    return 0;
}