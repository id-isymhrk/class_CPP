#include "polygon.h"

using namespace std;

Polygon::Polygon()
{
    _points.push_back(new Point(0, 0));
    _points.push_back(new Point(0, 1));
    _points.push_back(new Point(1, 1));
    _points.push_back(new Point(1, 0));
}

Polygon::Polygon(vector<Point *> p)
{
    _points = p;
}

// copy
Polygon::Polygon(const Polygon &copy)
    : Shape(copy)
{
    this->_points = copy._points;
}

Polygon &Polygon::operator=(const Polygon &copy)
{
    if (this != &copy)
    {
        this->_points = copy._points;
    }

    return *this;
}

float Polygon::compute_area() const
{
    float ans = 0.0;

    for (size_t i = 0; i < _points.size() - 1; i++)
    {
        ans += _points[i]->x * _points[i + 1]->y - _points[i]->y * _points[i + 1]->x;
    }

    return ans / 2;
}

Shape *Polygon::create() const
{
    return new Polygon();
}

Shape *Polygon::clone() const
{
    return new Polygon(*this);
}

Polygon::~Polygon()
{
    cout << "  Polygon delete" << endl;
    _points.clear();
}