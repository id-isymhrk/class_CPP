// #include "rectangle.h"
// #include "disk.h"
#include "polygon.h"

// #include <vector>
// #include <iostream>
#include <math.h>

using namespace std;

int main()
{
    vector<Point *> p_test = {new Point(0, 0), new Point(0, 2), new Point(2, 2), new Point(2, 0)};
    vector<Point *> p_test2;

    for (double i = 0; i < 360; i += 360 / 64)
    {
        const static double R = 1.0;
        double rad = i * 3.14 / 180;
        p_test2.push_back(new Point(R * cos(rad), R * sin(rad)));
    }

    vector<Shape *> test;
    vector<Shape *> test2;

    cout << "-----input-----" << endl;
    test.push_back(new Polygon());
    test.push_back(new Polygon(p_test));
    test.push_back(new Polygon(p_test2));
    cout << "-----result-----" << endl;
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test[i]->get_name() << endl;
        cout << "Area:" << test[i]->compute_area() << endl;
    }
    cout << endl;
    cout << "-----copied-----" << endl;
    test2.resize(test.size());
    for (size_t i = 0; i < test.size(); i++)
    {
        test2[i] = test[i];
    }

    test[0] = test[2]->clone();
    // test2.push_back(test[2]->clone());
    cout << "-----result(test)-----" << endl;
    for (size_t i = 0; i < test.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test[i]->get_name() << endl;
        cout << "Area:" << test[i]->compute_area() << endl;
    }
    cout << "-----result(test2)-----" << endl;
    for (size_t i = 0; i < test2.size(); i++)
    {
        cout << i << endl;
        cout << "Name:" << test2[i]->get_name() << endl;
        cout << "Area:" << test2[i]->compute_area() << endl;
    }
    return 0;
}