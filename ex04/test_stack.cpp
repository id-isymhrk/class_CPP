#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    // COMPLETE
    // Write tests for testing your Stack implementation.
    const int MAX_SIZE = 10;
    Point test_point[MAX_SIZE];
    Stack test_stack(MAX_SIZE - 1);

    // init
    for (int i = 0; i < MAX_SIZE; i++)
    {
        test_point[i] = Point{i, i * 2};

        if (!test_stack.full())
        {
            test_stack.push(test_point[i]);
            cout << " test_stack: Success to push!" << endl;
        }
        else
        {
            cout << " test_stack: full! Can't push!" << endl;
        }
    }

    cout << endl;
    cout << endl;
    cout << endl;

    for (int i = MAX_SIZE - 1; i >= 0; i--)
    {
        cout << "----------" << endl;
        cout << " test_point: " << test_point[i].x << ", " << test_point[i].y << endl;
        if (!test_stack.empty())
        {
            cout << " test_stack: " << test_stack.top().x << ", " << test_stack.top().y << endl;
            test_stack.pop();
        }
        else
        {
            cout << " test_stack: empty!" << endl;
        }
    }

    return 0;
}