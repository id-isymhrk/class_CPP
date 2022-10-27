#include "disk.h"

Disk::Disk()
    : Shape()
{
    _name = "Disk";
    _center = Point(0, 0);
    _radius = 1.0;
}

Disk::Disk(Point p, float r)
    : Shape()
{
    _name = "Disk";
    _center = p;
    _radius = r;
}

// copy
Disk::Disk(const Disk &copy)
    : Shape(copy)
{
    // *this = copy;
    _center = copy._center;
    _radius = copy._radius;
}

Disk &Disk::operator=(const Disk &copy)
{
    if (this != &copy)
    {
        // Shape::operator=(copy);
        // *this = copy;
        _center = copy._center;
        _radius = copy._radius;
    }

    return *this;
}

float Disk::compute_area() const
{
    return _radius * _radius * 3.14;
}

Shape *Disk::create() const
{
    return new Disk();
}

Shape *Disk::clone() const
{
    return new Disk(*this);
}

Disk::~Disk()
{
    // std::cout << "delete" << std::endl;
    delete this;
}