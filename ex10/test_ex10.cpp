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
        cout << endl;
        cout << "answer" << endl;
        cout << evaluate(test) << endl;
    }
    else
    {
        string test;
        cout << "---input yourself---" << endl;
        cin >> test;

        cout << "answer" << endl;
        cout << evaluate(test) << endl;
    }
    return 0;
}