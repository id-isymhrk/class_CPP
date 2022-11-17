
#include <math.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <functional>

using namespace std;

struct Point
{
    Point() : x(0.0), y(0.0), z(0.0) {}
    Point(double x_, double y_, double z_) : x(x_), y(y_), z(z_) {}

    double x, y, z;
};

void ShowPoint(Point test_point)
{
    cout << test_point.x
         << " " << test_point.y
         << " " << test_point.z << endl;
}

struct Compare
{
    static bool Comp(const Point &a, const Point &b)
    {
        Point origin(0, 0, 0);

        double dist_a, dist_b;
        double x, y, z;

        x = a.x - origin.x;
        y = a.y - origin.y;
        z = a.z - origin.z;
        dist_a = sqrt(x * x + y * y + z * z);

        x = b.x - origin.x;
        y = b.y - origin.y;
        z = b.z - origin.z;
        dist_b = sqrt(x * x + y * y + z * z);

        return (dist_a < dist_b);
    }
};

void find_k_closest(int k, vector<Point *> &list)
// vector<Point> find_k_closest(int k, vector<Point> &list)
{
    stack<Point> pstack;
    auto comp = Compare::Comp;
    // auto comp = [&](Point a, Point b) -> bool {
    // }

    priority_queue<Point, vector<Point>, decltype(comp)> queue(comp);
    // priority_queue<Point> queue;

    for (size_t i = 0; i < list.size(); i++)
    {
        queue.push(*list[i]);
    }

    for (size_t i = 0; !queue.empty(); i++)
    {
        // ShowPoint(queue.top());
        pstack.push(queue.top());
        queue.pop();
    }

    for (size_t i = 0; i < k; i++)
    {
        ShowPoint(pstack.top());
        pstack.pop();
    }
}