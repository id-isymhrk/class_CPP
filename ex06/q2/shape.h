#include <string>

class Shape
{
private:
    // std::string _name;
    // float _area;

public:
    // default
    Shape()
    {
    }

    // copy
    // Shape(const Shape &copy)
    // {
    //     _name = copy._name;
    //     _area = copy._area;
    // }
    // Shape &operator=(const Shape &copy)
    // {
    //     if (this != &copy)
    //     {
    //         _name = copy._name;
    //         _area = copy._area;
    //     }
    //     return *this;
    // }

    virtual std::string get_name() const = 0;
    // {
    //     return _name;
    // }

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