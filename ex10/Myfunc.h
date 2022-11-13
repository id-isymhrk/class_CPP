#include <iostream>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

double Add(double n1, double n2)
{
    return n1 + n2;
}
double Sub(double n1, double n2)
{
    return n1 - n2;
}
double Mult(double n1, double n2)
{
    return n1 * n2;
}
double Div(double n1, double n2)
{
    return n1 / n2;
}

typedef map<string, double (*)(double, double)> Calc;

Calc calc;
void Init()
{
    calc.insert(make_pair("+", Add));
    calc.insert(make_pair("-", Sub));
    calc.insert(make_pair("*", Mult));
    calc.insert(make_pair("/", Div));
}

double evaluate(const string &str)
{
    double res;

    double num;
    stack<double> operands;
    string ope;
    stack<string> operations;

    stringstream ss(str);
    string tmp;

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