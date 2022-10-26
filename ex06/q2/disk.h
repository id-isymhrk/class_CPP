#include "shape.h"

class Disk : public Shape
{
private:
    Point _center;
    float _radius;

public:
    Disk();
    Disk(Point center, float radius);
    // copy
    Disk(const Disk &disk);
    Disk &operator=(const Disk &disk);

    float compute_area() const override;

    Shape *create() const override;

    Shape *clone() const override;

    ~Disk();
};