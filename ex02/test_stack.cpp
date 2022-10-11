#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    // COMPLETE
    // Write tests for testing your Stack implementation.
    const int max_size = 10;
    Point test_point[max_size];
    Stack test_stack(max_size);

    // init
    for (int i = 0; i < max_size; i++)
    {
        test_point[i] = Point{i, i * 2};

        if (!test_stack.full())
        {
            test_stack.push(test_point[i]);
        }
    }

    for (int i = max_size - 1; i >= 0; i--)
    {
        cout << "----------" << endl;
        cout << " test_point: " << test_point[i].x << ", " << test_point[i].y << endl;
        cout << " test_stack: " << test_stack.top().x << ", " << test_stack.top().y << endl;
        if (!test_stack.empty())
        {
            test_stack.pop();
        }
    }

    return 0;
}