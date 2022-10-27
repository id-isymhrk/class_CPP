#include "shape.h"

#include <vector>

class Polygon : public Shape
{
private:
    std::vector<Point> points;

public:
    Polygon();

    float compute_area() const override;

    Shape *create() const override;

    Shape *clone() const override;

    ~Polygon();
};