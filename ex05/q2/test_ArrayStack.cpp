// test_ArrayStack.cpp
#include "ArrayStack.h"
#include <vector>

using namespace std;

void result(ArrayStack stack);

int main(void)
{
    // Create an instance of ArrayStack named stack1
    //   using the default constructor
    // Push several items in this stack.
    ArrayStack stack1;
    vector<string> test1 = {"University", "of", "Aizu"};

    cout << "---stack1 push---" << endl;
    for (int i = 0; i < test1.size(); i++)
    {
        cout << test1[i] << endl;
        stack1.push(test1[i]);
    }

    cout << endl;
    cout << "-----------" << endl;
    cout << "stack1 size:" << stack1.size() << endl;
    cout << "-----------" << endl;
    cout << endl;

    cout << "---stack1---" << endl;
    // result(stack1);

    cout << endl;
    cout << endl;
    cout << endl;
    // Create another instance of ArrayStack named stack2
    //   using the other constructor, specify an original size of 5
    // Push several items in this stack.
    const int SIZE_S2 = 5;

    ArrayStack stack2(SIZE_S2);
    string test2[SIZE_S2] = {"1:Aizu", "2:Hukushima", "3:Tohoku", "4:Japan", "5:Earth"};

    cout << "---stack2 push---" << endl;
    for (int i = 0; i < SIZE_S2; i++)
    {
        cout << test2[i] << endl;
        stack2.push(test2[i]);
    }

    cout << endl;
    cout << "-----------" << endl;
    cout << "stack2 size:" << stack2.size() << endl;
    cout << "-----------" << endl;
    cout << endl;

    cout << endl
         << endl
         << endl;
    // Copy
    ArrayStack stack3(stack1);
    ArrayStack stack4 = stack2;

    cout << "---stack3---" << endl;
    // result(stack3);
    cout << endl
         << endl
         << endl;

    cout << "---stack4---" << endl;
    // result(stack4);
    cout << endl
         << endl
         << endl;

    // Assignment
    ArrayStack stack5;
    stack5 = stack1;

    cout << "---stack5---" << endl;
    // result(stack5);
    cout << endl
         << endl
         << endl;

    const int SIZE_S6 = 10;
    ArrayStack stack6(SIZE_S6);
    stack6 = stack6;

    // COMPLETE
    // Verify that the content of the stacks 'stack1' and 'stack3', 'stack2' and 'stack4'
    // and 'stack1' and 'stack5' are identical.
    //
    // Push several items in 'stack6'.
    string test6[SIZE_S6] = {"0:ex05", "1:q2", "2:stack1", "3:stack2", "4:stack3", "5:stack4", "6:stack5", "7:stack6", "8", "9"};

    cout << "---stack6 push---" << endl;
    for (int i = 0; i < SIZE_S6; i++)
    {
        cout << test6[i] << endl;
        stack6.push(test6[i]);
    }

    cout << endl;
    cout << "-----------" << endl;
    cout << "stack6 size:" << stack6.size() << endl;
    cout << "-----------" << endl;
    cout << endl;

    cout << "---stack1---" << endl;
    result(stack1);
    cout << "---stack2---" << endl;
    result(stack2);
    cout << "---stack3---" << endl;
    result(stack3);
    cout << "---stack4---" << endl;
    result(stack4);
    cout << "---stack5---" << endl;
    result(stack5);
    cout << "---stack6---" << endl;
    result(stack6);

    return 0;
}

void result(ArrayStack stack)
{
    // cout << "---stack pop---" << endl;
    for (int i = 0; !stack.empty(); i++)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
}