#include "shape.h"

class Rectangle : public Shape
{
private:
    Point _left_corner;
    float _width;
    float _height;

protected:
    // copy
    Rectangle(const Rectangle &copy);
    Rectangle &operator=(const Rectangle &copy);

public:
    Rectangle();
    Rectangle(Point left_corner, float width, float height);

    float compute_area() const override;

    Shape *create() const override;

    Shape *clone() const override;

    ~Rectangle();
};