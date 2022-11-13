#include "Myfunc.h"
#include <vector>

constexpr bool FLAG_TEST = true;

int main()
{
    Init();

    if (FLAG_TEST)
    {
        vector<string> test = {
            "( 1 + ( 2 * 3 ) )",
            "( ( 1 * 2 ) / 2 )",
            "( ( 1 + 1 ) * ( 1 + 1 ) )",
            "( ( ( 32 / 4 ) / ( 4 * 2 ) ) - 1 )",
        };
        for (size_t i = 0; i < test.size(); i++)
        {
            cout << "---This is Test!---" << endl;
            cout << "No." << i << "   input:" << test[i] << endl;
            cout << "---answer---" << endl;
            cout << evaluate(test[i]) << endl;
            cout << endl;
        }
    }
    else
    {
        string test;
        cout << "---input yourself---" << endl;
        cin >> test;

        cout << endl;
        cout << "---answer---" << endl;
        cout << evaluate(test) << endl;
    }
    return 0;
}