#include "shape.h"

#include <vector>

class Polygon : public Shape
{
private:
    std::vector<Point *> _points;

protected:
    // copy
    Polygon(const Polygon &copy);
    Polygon &operator=(const Polygon &copy);

public:
    Polygon();
    Polygon(std::vector<Point *> p);

    float compute_area() const override;

    Shape *create() const override;

    Shape *clone() const override;

    ~Polygon();
};