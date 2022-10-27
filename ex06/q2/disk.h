#include "shape.h"

class Disk : public Shape
{
private:
    Point _center;
    float _radius;

protected:
    // copy
    Disk(const Disk &copy);
    Disk &operator=(const Disk &copy);

public:
    Disk();
    Disk(Point center, float radius);

    float compute_area() const override;

    Shape *create() const override;

    Shape *clone() const override;

    ~Disk();
};