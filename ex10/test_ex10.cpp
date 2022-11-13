#include "Myfunc.h"

constexpr bool FLAG_TEST = true;

int main()
{
    if (!FLAG_TEST)
    {
        string test;
        cout << "---input yourself---" << endl;
        cin >> test;

        evaluate(test);
    }
    else
    {
        string test = "( 1 + 2 )";
        cout << "This is Test!" << endl;
        cout << "input:" << test << endl;

        evaluate(test);
    }
    return 0;
}