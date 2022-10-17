#include "stack.h"
#include <iostream>

using namespace std;

const Point POINT_NULL{-100, -100};

// Check whether the stack is empty
bool Stack::empty() const
{
    return _top < 0;
}

// Check whether the stack is full
bool Stack::full() const
{
    return _top >= _max_size - 1;
}

// Return the number of elements in the stack
int Stack::size() const
{
    return _top + 1;
}

// Insert element on top
// print an error message on std::cerr when overflow
void Stack::push(Point point)
{
    try
    {
        _top++;
        _data[_top] = point;
    }
    catch (const std::exception &e)
    {
        cerr << "Stack is full. Don't push!" << e.what() << endl;
    }
}

// Remove element on top
// print an error message on std::cerr when underflow
void Stack::pop()
{
    try
    {
        _data[_top] = POINT_NULL;
        _top--;
    }
    catch (const std::exception &e)
    {
        cerr << "Stack is empty. Don't pop!" << e.what() << endl;
    }
}

// Acces the topmost element
Point Stack::top()
{
    return _data[_top];
}