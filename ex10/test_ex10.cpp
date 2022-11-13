#include "Myfunc.h"

constexpr bool FLAG_TEST = true;

int main()
{
    Init();

    if (FLAG_TEST)
    {
        string test = "( 1 + ( 2 * 3 ) )";
        cout << "This is Test!" << endl;
        cout << "input:" << test << endl;

        evaluate(test);
    }
    else
    {
        string test;
        cout << "---input yourself---" << endl;
        cin >> test;

        evaluate(test);
    }
    return 0;
}