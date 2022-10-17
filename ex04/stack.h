#ifndef STACK_H
#define STACK_H

// Insert the relevant headers here

// Class for representing two dimensional points
struct Point
{
    int x;
    int y;
};

// Class for representing a stack
class Stack
{
private:
    int _max_size; // capacity of the fixed-size stack
    int _top;      // index to the top of the stack
    Point *_data;  // data container

public:
    Stack(int max_size = 100) : _max_size(max_size),
                                _top(-1), _data(new Point[max_size]) {}

    ~Stack() { delete[] _data; }

    // Interface

    // Check whether the stack is empty
    // (the implementation will go in stack.cpp)
    bool empty() const;

    // Check whether the stack is full
    // (the implementation will go in stack.cpp)
    bool full() const;

    // Return the number of elements in the stack
    // (the implementation will go in stack.cpp)
    int size() const;

    // Insert element on top
    // print an error message on std::cerr when overflow
    // (the implementation will go in stack.cpp)
    void push(const Point);

    // Remove element on top
    // print an error message on std::cerr when underflow
    // (the implementation will go in stack.cpp)
    void pop();

    // Acces the topmost element
    // (the implementation will go in stack.cpp)
    Point top() const;
};
#endif