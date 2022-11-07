// ArrayStack.h

#include <string>
#include <exception>
#include <iostream>

#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

using namespace std;

class EmptyError : public std::exception
{
public:
    EmptyError(bool empty){

    };
};

void throwEmptyError(bool empty)
{
    if (empty)
        throw EmptyError(empty);
}

class ArrayStack
{
private:
    int _num_items;      // number of items in the stack
    std::string *_items; // stack items
    int _allocated_size; // size of memory allocated

    void resize(int max_size)
    {
        if (max_size == 0)
            max_size++;

        // Move stack to a new array of size max
        _allocated_size = max_size;
        std::string *temp = new std::string[max_size];
        // Copy
        for (int i = 0; i < _num_items; ++i)
        {
            temp[i] = _items[i];
        }
        delete[] _items;
        _items = temp;
    }

public:
    // Constructors:
    // Default constructor
    ArrayStack()
    {
        /* COMPLETE ... initialize _num_items to 0, _allocated_size to 0, and
         * set _items to the null pointer,
         */
        _num_items = 0;
        _allocated_size = 0;
        _items = nullptr;
    }

    explicit ArrayStack(int allocated_size)
    {
        /* COMPLETE ... initialize _num_items to 0,
         * pre-allocate memory for an array of size allocated_size
         * and make _items point to it */
        _num_items = 0;
        _allocated_size = allocated_size;
        _items = new std::string[allocated_size];
        // _items = nullptr;
        // resize(_allocated_size);
    }
    // copy
    ArrayStack(const ArrayStack &stack)
    {
        std::cout << "copy!" << std::endl;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;
        _items = new std::string[stack.size()];
        for (int i = 0; i < stack.size(); ++i)
        {
            _items[i] = stack._items[i];
        }
    }

    ArrayStack &operator=(ArrayStack &stack)
    {
        std::cout << "copy!" << std::endl;
        if (this != &stack)
        {
            delete[] _items;
            _num_items = stack._num_items;
            _allocated_size = stack._allocated_size;
            _items = new std::string[stack.size()];
            for (int i = 0; i < stack.size(); ++i)
            {
                _items[i] = stack._items[i];
            }
        }
        return *this;
    }

    // move
    ArrayStack(ArrayStack &&stack)
    // : _items(std::move(stack._items)), _num_items(std::move(stack._num_items)), _allocated_size(std::move(stack._allocated_size))
    {
        std::cout << "move!" << std::endl;
        // delete[] _items;
        // _num_items = 0;
        // _allocated_size = 0;
        // _items = new std::string[stack.size()];

        // _items = std::move(stack._items);
        // _num_items = std::move(stack._num_items);
        // _allocated_size = std::move(stack._allocated_size);

        _items = stack._items;
        _num_items = stack._num_items;
        _allocated_size = stack._allocated_size;

        stack._items = nullptr;
        stack._num_items = 0;
        stack._allocated_size = 0;
    }

    ArrayStack &operator=(ArrayStack &&stack)
    {
        std::cout << "move!" << std::endl;
        if (this != &stack)
        {
            delete[] _items;

            // _num_items = 0;
            // _allocated_size = 0;
            // _items = new std::string[stack.size()];

            // _items = std::move(stack._items);
            // _num_items = std::move(stack._num_items);
            // _allocated_size = std::move(stack._allocated_size);

            _items = stack._items;
            _num_items = stack._num_items;
            _allocated_size = stack._allocated_size;

            stack._items = nullptr;
            stack._num_items = 0;
            stack._allocated_size = 0;
        }

        return *this;
    }

    // Destructor:
    ~ArrayStack()
    {
        // COMPLETE
        if (_items != nullptr)
        {
            cout << "death" << endl;
            delete[] _items;
        }
    }

    // Push item to the stack
    void push(const std::string &item)
    {
        if (_num_items == _allocated_size)
            resize(2 * _allocated_size);
        _items[_num_items++] = item;
    }

    // Pop an item
    void pop()
    {
        cout << "pop()!" << endl;
        throwEmptyError(this->empty());

        _num_items--;
        if (_num_items > 0 && _num_items == _allocated_size / 4)
            resize(_allocated_size / 2);
    }

    // Access the top-most item
    std::string top()
    {
        throwEmptyError(this->empty());
        return _items[_num_items - 1];
    }

    // Check if the stack is empty
    bool empty() const { return _num_items == 0; }

    // Return the number of elements in the stack
    int size() const { return _num_items; }

    void show_items()
    {
        for (int i = 0; i < size(); i++)
        {
            std::cout << i << ":" << _items[i] << std::endl;
        }
        std::cout << "----------" << std::endl;
    }
};

#endif // ARRAY_STACK_H