#include <iostream>
#include <sstream>
#include <stack>
#include <map>

using namespace std;

void Add(double &n1, double n2)
{
    n1 += n2;
}
void Sub(double &n1, double n2)
{
    n1 -= n2;
}
void Mult(double &n1, double n2)
{
    n1 *= n2;
}
void Div(double &n1, double n2)
{
    n1 /= n2;
}

typedef map<string, void (*)(double &, double)> Calc;
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
    bool first = true;
    double res = 0.0;

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
        if (tmp != "(")
        {
            if (tmp == ")")
            {
                if (first) //計算初回
                {
                    static double n1;
                    static double n2;
                    static string ope;
                    n1 = operands.top();
                    operands.pop();
                    n2 = operands.top();
                    operands.pop();
                    ope = operations.top();
                    operations.pop();
                    Calc::iterator it = calc.find(ope);
                    it->second(n1, n2);
                    res = n1;

                    first = false;
                }
                else //２回目以降は以前の計算結果を使う
                {
                    static double n1;
                    static string ope;
                    n1 = operands.top();
                    operands.pop();
                    ope = operations.top();
                    operations.pop();
                    Calc::iterator it = calc.find(ope);
                    it->second(res, n1);
                }
            }
            else
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
    }

    // cout << "---operands---" << endl;
    // while (!operands.empty())
    // {
    //     cout << operands.top() << endl;
    //     operands.pop();
    // }
    // cout << endl;
    // cout << "---operations---" << endl;
    // while (!operations.empty())
    // {
    //     cout << operations.top() << endl;
    //     operations.pop();
    // }

    return res;
}