
#include <math.h>
#include <iostream>
#include <queue>

using namespace std;

struct Point
{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    double x, y, z;
};

bool Compare(Point a, Point b)
{
    double dist_a, dist_b;
    dist_a = sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
    dist_b = sqrt(b.x * b.x + b.y * b.y + b.z * b.z);

    return dist_a >= dist_b;
}