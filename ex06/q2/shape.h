#pragma once
#include <string>
#include <iostream>

class Point
{
public:
    Point()
    {
    }
    Point(double _x, double _y)
    {
        x = _x;
        y = _y;
    }
    double x;
    double y;
};

class Shape
{
protected:
    std::string _name;
    // float _area;

    // copy
    Shape(const Shape &copy)
    {
        _name = copy._name;
    }

    Shape &operator=(const Shape &copy)
    {
        if (this != &copy)
        {
            _name = copy._name;
        }
        return *this;
    }

public:
    // default
    Shape()
    {
        std::cout << "create" << std::endl;
    }

    virtual std::string get_name()
    {
        return _name;
    }

    virtual float compute_area() const = 0;
    // {
    //     return _area;
    // }

    virtual Shape *create() const = 0;
    // {
    //     return new Shape();
    // }

    virtual Shape *clone() const = 0;
    // {
    //     return new Shape(this);
    //     // return this;
    // }

    virtual ~Shape()
    {
    }
};