#include "rectangle.h"

Rectangle::Rectangle()
    : Shape()
{
    _name = "Rectangle";
    _left_corner = Point(0, 0);
    _width = 1;
    _height = 1;
}

Rectangle::Rectangle(Point left_corner, float width, float height)
    : Shape()
{
    _name = "Rectangle";
    _left_corner = left_corner;
    _width = width;
    _height = height;
}

// copy
Rectangle::Rectangle(const Rectangle &copy)
    : Shape(copy)
{
    // *this = copy;
    _left_corner = copy._left_corner;
    _width = copy._width;
    _height = copy._height;
}

Rectangle &Rectangle::operator=(const Rectangle &copy)
{
    if (this != &copy)
    {

        // Shape::operator=(copy);
        *this = copy;
    }

    return *this;
}

float Rectangle::compute_area() const
{
    return _width * _height;
}

Shape *Rectangle::create() const
{
    return new Rectangle();
}

Shape *Rectangle::clone() const
{
    return new Rectangle(*this);
}

Rectangle::~Rectangle()
{
    delete this;
}