#include <iostream>
#include <sstream>
#include <stack>

using namespace std;

double evaluate(const string &str)
{
    double res;
    stringstream ss(str);
    string tmp;

    double num;
    stack<double> operands;
    string ope;
    stack<string> operations;

    while (getline(ss, tmp, ' '))
    {
        // cout << "in evaluate while" << endl;
        // cout << tmp << endl;
        if ((tmp != "(") && (tmp != ")"))
        {
            stringstream ss_tmp{tmp};
            if ((tmp == "+") || (tmp == "-") || (tmp == "*") || (tmp == "/"))
            {
                ss_tmp >> ope;
                // ope = tmp;
                operations.push(ope);
            }
            else
            {
                ss_tmp >> num;
                operands.push(num);
            }
        }
    }

    cout << "---operands---" << endl;
    while (!operands.empty())
    {
        cout << operands.top() << endl;
        operands.pop();
    }
    cout << endl;
    cout << "---operations---" << endl;
    while (!operations.empty())
    {
        cout << operations.top() << endl;
        operations.pop();
    }

    return res;
}