// test_ArrayStack.cpp
#include "ArrayStack.h"
#include <vector>

using namespace std;

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

    cout << "---stack1 pop---" << endl;
    for (int i = 0; !stack1.empty(); i++)
    {
        cout << stack1.top() << endl;
        stack1.pop();
    }

    cout << endl;
    cout << endl;
    cout << endl;
    // Create another instance of ArrayStack named stack2
    //   using the other constructor, specify an original size of 5
    // Push several items in this stack.
    const int SIZE = 5;

    ArrayStack stack2(SIZE);
    string test2[SIZE] = {"1:Aizu", "2:Hukushima", "3:Tohoku", "4:Japan", "5:Earth"};

    cout << "---stack2 push---" << endl;
    for (int i = 0; i < SIZE; i++)
    {
        cout << test2[i] << endl;
        stack2.push(test2[i]);
    }

    cout << endl;
    cout << "-----------" << endl;
    cout << "stack2 size:" << stack2.size() << endl;
    cout << "-----------" << endl;
    cout << endl;

    cout << "---stack2 pop---" << endl;
    for (int i = 0; !stack2.empty(); i++)
    {
        cout << stack2.top() << endl;
        stack2.pop();
    }

    return 0;
}