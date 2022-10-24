#include <string>

class Shape
{
private:
    std::string _name;
    float _area;

public:
    Shape()
    {
    }

    // copy
    Shape(Shape &copy)
    {
        _name = copy._name;
        _area = copy._area;
    }
    Shape &operator=(Shape &copy)
    {
        if (this != &copy)
        {
            _name = copy._name;
            _area = copy._area;
        }
        return *this;
    }

    std::string set_name() const
    {
        return _name;
    }

    float compute_area() const
    {
        return _area;
    }

    Shape *create() const
    {
        return new Shape();
    }

    Shape *clone() const
    {
        // return new Shape(this);
        return this;
    }

    ~Shape()
    {
    }
};